#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#define PARENT(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)

void swap (int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Heapify (int *a, int i, int heap_size)
{
	int left, right, largest;
	left = LEFT (i);
	right = RIGHT (i);
	if ((left <= heap_size)&& (a[left] > a[i]))
		largest = left;
	else
		largest = i;
	if ((right <= heap_size) && (a[right]) > a[largest])
		largest = right;
	if (largest != i)
	{
		swap (a + i, a + largest);
		Heapify (a, largest, heap_size);
	}
}
void BuildHeap (int *a, int length)
{
	int i;
	for (i = length/2; i >=1; i--)
	{
		Heapify (a, i, length);
	}
}
//length是要排序数组的长度，heap_size为堆的大小
void HeapSort (int *a, int length, int heap_size)
{	
	int i;
	BuildHeap (a, length);
	for (i = length; i > 1; i--)
	{
		swap (a + 1, a + i);
		heap_size --;
		Heapify (a, 1, heap_size);
	}
}

#endif