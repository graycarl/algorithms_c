#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void (*sort)(int *, unsigned int);

void merge(int *array, int p, int q, int r)
{
	int *aL, *aR;
	int n1 = q-p+1;
	int n2 = r-q;
	int i, j, k;
	
	aL = malloc(sizeof(int)*(n1+1));
	aR = malloc(sizeof(int)*(n2+1));

	memcpy(aL, &array[p], sizeof(int)*n1);
	memcpy(aR, &array[q+1], sizeof(int)*n2);
	aL[n1] = 999999;
	aR[n2] = 999999;

	i = 0; j = 0;
	for (k=p; k<=r; k++) {
		if (aL[i] <= aR[j]) {
			array[k] = aL[i];
			i++;
		} else {
			array[k] = aR[j];
			j++;
		}
	}

	return;
}

void merge_sort(int *array, int p, int r)
{
	int q;

	if (p < r) {
		q = (p+r)/2;
		merge_sort(array, p, q);
		merge_sort(array, q+1, r);
		merge(array, p, q, r);
	}

	return;
}

void mergesort(int *nums, unsigned int count)
{
	merge_sort(nums, 0, count-1);

	return;
}

void init_sortfn(void)
{
	sort = mergesort;
}
