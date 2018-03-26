#include "AMQPcpp.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
using namespace std;

string get_time()
{
    time_t timer;  
    struct tm *tblock;  
    timer=time(NULL);  
    tblock=localtime(&timer); 
    char buf[32] = {0};
    sprintf(buf, "%d-%d-%d %d:%d:%d", tblock->tm_year, tblock->tm_mon, tblock->tm_mday, tblock->tm_hour, tblock->tm_min, tblock->tm_sec);
    return string(buf);
}

bool isOK = false;
void cb_sig(int no)
{
    isOK = true;
    cout<<get_time() <<" | recevie signal SIGUSR1, isOK set to true" <<endl;;
}

int main () 
{
    signal(SIGUSR1, cb_sig);
    try {
        AMQP amqp("test:test@192.168.83.141:5672/test_host");
        cout<<get_time()<<" | login success, pid:" <<getpid() <<endl;
        AMQPExchange * ex = amqp.createExchange("amq.direct");
        ex->Declare("amq.direct", "direct", 2);

        AMQPQueue * qu = amqp.createQueue("order_queue");
        qu->Declare("order_queue", 2);
        qu->Bind("amq.direct", "order_bind");

        ex->setHeader("Delivery-mode", 2);
        ex->setHeader("Content-type", "text/text");
        ex->setHeader("Content-encoding", "UTF-8");
        char data[1024];
        int seq = 0;
        while(1)
        {
            if (isOK)
            {
                isOK = false;
                memset(data, 0, sizeof(data));
                sprintf(data,"{\"seq\":%d,\"biz_type\":1,\"card_type\":1,\"create_time\":\"2017-06-28 17:45:34\",\"cur_type\":\"CNY\","
                    "\"err_msg\":\"该商户不存在：900000000000748400001152222333332\",\"id_num\":\"372922198804100621\",\"id_type\":1,"
                    "\"mch_agentpay_acct_id\":\"900000000012012321007484\",\"mch_id\":\"2666600000005\",\"mch_name\":"
                    "\"代付dwadasdadwasdaaw测试商户\",\"modify_time\":\"2017-06-28 17:45:35\",\"option\":\"agent_insert\","
                    "\"order_no\":\"800201706dwasdawdsad28174534932413637120501\",\"order_status\":3,\"order_type\":3,\"out_order_no\":"
                    "\"88661745dawsdaw1557968178866\",\"pay_channel_id\":\"1001\",\"pay_channel_name\":\"微众银行\",\"pay_sdadtime\":\"\","
                    "\"pay_time1\":\"sdaawdasdawdas\",\"pay_time2\":\"dasdawdwas\",\"payee_acct_name\":\"9000000000007484\",\"payee_acct_no\":"
                    "\"9999600170340100007102\",\"payee_acct_type\":2,\"payee_bank_name\":\"深圳前海微众银行\",\"payee_bank_no\":\"323584000888\","
                    "\"payee_phone_num\":\"15275159755\",\"payment_fee\":10000,\"payment_profit\":100,\"pyh_status\":1,\"summar_code\":\"PR03\"}",
                    ++seq);
                ex->Publish(data, strlen(data), "order_bind");
                cout<<get_time() <<" send data: "<<data <<endl;
                /*
                int t = rand()%600;
                if (t%5 == 0)
                {
                   cout<<"sleep "<< t<<"s\n";
                   sleep(t);
                }
                */
            }
            sleep(1);// 跑的太快浪费资源
        }    
    }
    catch (AMQPException& e)
    {
        cout<<"throw AMQPException" <<endl;
        cout << e.getMessage() << std::endl;
    }
    catch(...)
    {
        cout<<"throw common exception" <<endl;
    }
    return 0;
}
