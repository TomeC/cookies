#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__
void insertSort (int *a, int len)
{
	int i, j;
	for (i = 2; i < len; i++)
	{
		if (a[i] < a[i - 1])
		{
			//a[0]作为哨兵
			a[0] = a[i];
			for (j = i - 1; a[j] > a[0]; j--)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}
	}
}

#endif
