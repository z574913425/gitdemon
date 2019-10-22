#include "uhead.h"

void urand(int* arr, int n)
{
	int i ;
	srand((int)time(0));
	for(i = 0; i < n ; i++)
	{
		arr[i] = 1 + (int)(100.0*rand()/(RAND_MAX+1.0));
	}
}

int compare(const void* a,const void* b)
{
	int *aa = (int *) a, *bb = (int *) b;
	if(*aa > *bb)
		return 1;
	if(*aa == *bb)
		return 0;
	if(*aa < *bb)
		return -1;
}

void bsort(void* base, size_t nmemb, size_t size, int (*compare)(const void*, const void*))
{
	int i , j ;
	void* temp;
	for(i = 0; i < nmemb-1 ; i++)
	{
		for(j = 0; j < nmemb-1 ; j++)
		{
			if(compare(base + size*j, base + size*(j+1)) > 0)
			{
				memcpy(temp, base + size*(j+1), size);
  				memcpy(base + size*(j+1), base + size*j, size);
				memcpy(base + size*j, temp, size);
			}
		}
	}
}

double bsort_time(int* arr , int n)
{
	struct timeval tv1, tv2;
	struct timezone tz ;
	double i;
	gettimeofday(&tv1, &tz);
	bsort((void*)arr, n, sizeof(int), compare);
	gettimeofday(&tv2, &tz);
	i = tv2.tv_usec - tv1.tv_usec;
	return i;
}
double qsort_time(int* arr , int n)
{
	struct timeval tv1, tv2;
	struct timezone tz ;
	double i;
	gettimeofday(&tv1, &tz);
	qsort((void*)arr, n, sizeof(int), compare);
	gettimeofday(&tv2, &tz);
	i = tv2.tv_usec - tv1.tv_usec;
	return i;
}

