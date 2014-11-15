#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__
void swap (int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = n-1; j > 0; j--)
		{
			if (a[j] < a[j - 1])
				swap (a + j - 1, a + j);
		}
	}
}

#endif