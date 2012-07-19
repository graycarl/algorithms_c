void (*sort)(int *, unsigned int);

int partition(int *array, int p, int r)
{
	int q, i, j, last, tmp;

	last = array[r];
	j = p-1;
	for (i=p; i<r; i++) {
		if (array[i] < last) {
			j++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}

	array[r] = array[j+1];
	array[j+1] = last;

	return j+1;
}

void _quicksort(int *nums, int p, int r)
{
	int q;
	if (p < r) {
		q = partition(nums, p, r);
		_quicksort(nums, p, q-1);
		_quicksort(nums, q+1, r);
	}
}

void quicksort(int *nums, unsigned int count)
{
	_quicksort(nums, 0, count-1);
}

void init_sortfn(void)
{
	sort = quicksort;
}
