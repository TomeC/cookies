#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__
#include <stdlib.h>
#define INFINITY 65535
void Merge (int *a, int p, int q, int r)
{
	int i, j, k;
	 int n1 = q - p + 1;
	 int n2 = r - q;
	 int *left = (int *)malloc (sizeof (int) * n1+1);
	 int *right = (int *)malloc (sizeof (int) * n2+1);
	 for (i = 0; i < n1; i++)
	 {
		 left[i] = a[p + i];
	 }
	 left[i] = INFINITY;	//
	 for (i = 0; i < n2; i++)
	 {
		 right[i] = a[q + i + 1];
	 }
	 right[i] = INFINITY;//设置旗帜，防止在下面的比较中溢出
	 i = j = 0;
	 for (k = p; k <= r; k++)
	 {
		 if (left[i] < right[j])
			 a[k] = left[i++];
		 else
			 a[k] = right[j++];
		 
	 }
}

void MergeSort (int *a, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort (a, p, q);
		MergeSort (a, q+1, r);
		Merge (a, p, q, r);
	}
}

#endif