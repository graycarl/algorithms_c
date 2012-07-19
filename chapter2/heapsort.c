void (*sort)(int *, unsigned int);

void max_heap(int *array, int i, int size)
{
	int left, right, max, tmp;

	left = (i+1)*2 - 1;
	right = (i+1)*2+1 -1;
	max = i;

	if (left < size && array[i] < array[left])
		max = left;
	if (right < size && array[max] < array[right])
		max = right;
	if (max != i) {
		tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;
		max_heap(array, max, size);
	}
}

void build_max_heap(int *array, int size)
{
	int i;

	for (i=size/2; i>=0; i--)
		max_heap(array, i, size);

}

void heap_sort(int *array, int size)
{
	int i, tmp;
	build_max_heap(array, size);

	for (i=size; i>1; i--) {
		tmp = array[i-1];
		array[i-1] = array[0];
		array[0] = tmp;
		max_heap(array, 0, i-1);
	}
}


void P_heap_sort(int *nums, unsigned int count)
{
	heap_sort(nums, count);
}	

void init_sortfn(void)
{
	sort = P_heap_sort;
}
