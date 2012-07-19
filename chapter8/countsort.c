#include <string.h>
#include <stdlib.h>

void (*sort)(int *, unsigned int);

void count_sort(int *array_a, int *array_b, int count, int max)
{
	int *array_c = malloc(sizeof(int)*(max+1));
	int i, j;
	
	memset(array_c, 0, sizeof(int)*(max+1));

	for (i=0; i<count; i++)
		array_c[array_a[i]]++;

	for (i=1; i<=max; i++)
		array_c[i] = array_c[i]+array_c[i-1];

	for (i=0; i<count; i++) {
		array_b[array_c[array_a[i]]-1] = array_a[i];
		array_c[array_a[i]]--;
	}

	free(array_c);

}

void countsort(int *nums, unsigned int count)
{
	int max = 99999;
	int *B = malloc(sizeof(int) * count);
	int i;

	count_sort(nums, B, count, max);

	for (i=0; i<count; i++)
		nums[i] = B[i];

	free(B);

	return;
}

void init_sortfn(void)
{
	sort = countsort;
}
