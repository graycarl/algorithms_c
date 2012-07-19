#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void (*sort)(int *, unsigned int);
extern void init_sortfn(void);

#define MAXSIZE 1000000

int read_nums(char *filename, int *numlist)
{
	unsigned int count = 0;
	FILE *fp = NULL;

	fp = fopen(filename, "r");
	while(fscanf(fp, "%d", &numlist[count]) != EOF)
		count++;

	fclose(fp);

	return count;
}

int write_nums(char *filename, int *numlist, unsigned int count)
{
	FILE *fp = NULL;
	int i;

	fp = fopen(filename, "w");
	for (i=0; i<count; i++)
		fprintf(fp, "%d\n", numlist[i]);

	fclose(fp);

	return 0;
}

int main(int argc, char *argv[])
{
	int *numlist = malloc(sizeof(int)*MAXSIZE);
	unsigned int count;
	clock_t start, end;
	
	printf("start test %s\n", argv[0]);

	init_sortfn();
	count = read_nums("data", numlist);
	start = clock();
	sort(numlist, count);
	end = clock();
	write_nums("result", numlist, count);

	printf("\"%s\" finish, use %lds [%ld]\n", argv[0], (end-start)/CLOCKS_PER_SEC,
			(end-start));

	return 0;
}
	
