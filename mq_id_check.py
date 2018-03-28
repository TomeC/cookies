import pika, json, sys
seq_id = 1
def callback(ch, method, properties, body):
    global seq_id
    content = json.loads(body)
    if content['seq'] != seq_id:
        print 'not equal, content seq:',content['seq'], ' normal seq:', seq_id
        sys.exit(1)
    else:
        seq_id = seq_id + 1
    ch.basic_ack(delivery_tag = method.delivery_tag)

try:
    credentials = pika.PlainCredentials('admin', 'admin')
    connection = pika.BlockingConnection(pika.ConnectionParameters('10.100.120.183', 5672, 'dev_host', credentials))
    channel = connection.channel()
    channel.queue_declare(queue = 'order_queue', durable = True)
    channel.basic_qos(prefetch_count = 1)
    channel.basic_consume(callback, queue = 'order_queue', no_ack = False)
    channel.start_consuming()
except Exception as e:
    print 'mq exception:',str(e)
