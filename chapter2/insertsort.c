void (*sort)(int *, unsigned int);

void insertsort(int *nums, unsigned int count)
{
	int i, j;
	int tmp;

	for (i=1; i<count; i++) {
		tmp = nums[i];
		j = i-1;
		while (j >= 0 && tmp < nums[j]) {
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = tmp;
	}
	
	return;
}

void init_sortfn(void)
{
	sort = insertsort;
}
