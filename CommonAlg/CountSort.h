#ifndef __COUNT_SORT_H__
#define __COUNT_SORT_H__
#include <stdlib.h>
#include <string.h>
void CountSort (int *a, int n)
{
	int i, k, *b, *c;

	k = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > k)
			k = a[i];
	}
	b = (int *)malloc (sizeof (int) * (n + 1));
	c = (int *)malloc (sizeof (int) * (k + 1));
	memset (c, 0, sizeof (int) * (k + 1));
	
	for (i = 1; i <= n; i++)
		c[a[i]] = c[a[i]] + 1;
	for (i = 1; i <= k; i++)
		c[i] += c[i - 1];
	for (i = n; i >= 1; i--)
	{
		b[c[a[i]]] = a[i];
		c[a[i]] --;
	}
	memcpy(a, b, sizeof (int) * (n+1));
}
#endif