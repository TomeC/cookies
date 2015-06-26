#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

void swap (int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
int partition (int *a, int left, int right)
{
	int min, max, pivot;
	min = left;
	max = right;
	pivot = a[left];
	while (1)
	{
		while ((min < max) && (pivot <= a[max]))
		{
			max--;
		}
		if (min < max)
			a[min ++] = a[max];
		while ((min < max) && (pivot > a[min]))
		{
			min++;
		}
		if (min < max)
			a[max --] = a[min];

		if (min >= max)
			break;
	}
	a[max] = pivot;
	return max;
}
*/
//最新的算法
int partition (int *a, int left, int right)
{
	int i, j, pivot;
	pivot = a[right];
	j = left - 1;

	for (i = left; i < right; i++)
	{
		if (a[i] <= pivot)
		{
			j++;
			swap (a + j, a + i);
		}
	}
	swap (a + j + 1, a + right);
	return j + 1;
}
//随机算法
/*
int Random_Partition (int *a, int left, int right)
{
	int tmp;
	srand (time (0));
	tmp = rand()%(right + 1);
	swap (a + tmp, a + right);
	return partition (a, left, right);
}
*/
//主循环
void QuickSort (int *a, int left, int right)
{
	int pivot;
	if (left < right)
	{
		pivot = partition (a, left, right);
		QuickSort(a, left, pivot - 1);
		QuickSort(a, pivot + 1, right);
	}
	return;
}

#endif
