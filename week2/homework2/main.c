#include "uhead.h"

int main()
{
	int arr[UNUMBER];
	int i, j, k;
	double l , m; 
	urand(arr , UNUMBER);
	printf("原数组:");
	for(j = 0; j < UNUMBER; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
	m =  qsort_time(arr , UNUMBER);
	printf("快速排序:");
	qsort(arr, UNUMBER, sizeof(int), compare);
	for(k = 0; k < UNUMBER; k++)
	{
		printf("%d ",arr[k]);
	}
	printf("\n");
	printf("快速排序用时: %f us",m);
	printf("\n");
	l = bsort_time(arr , UNUMBER);
	//bsort((void*)arr, UNUMBER, sizeof(int), compare);
	printf("冒泡排序:");
	for(i = 0; i < UNUMBER; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("冒泡排序用时: %f us",l);
	printf("\n");
	return 0;
}
