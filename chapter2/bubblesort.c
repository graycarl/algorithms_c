void (*sort)(int *, unsigned int);

void bubblesort(int *nums, unsigned int count)
{
	int i, j;
	int tmp;

	for (i=0; i<count-1; i++)
		for (j=count-1; j>i; j--) 
			if (nums[j] < nums[j-1]) {
				tmp = nums[j];
				nums[j] = nums[j-1];
				nums[j-1] = tmp;
			}
	
	return;
}

void init_sortfn(void)
{
	sort = bubblesort;
}
