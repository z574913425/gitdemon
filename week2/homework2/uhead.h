#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#define UNUMBER 50

void urand(int* , int);
void bsort(void*, size_t, size_t, int (*)(const void*, const void*));
int compare(const void* ,const void*);
double bsort_time(int* arr , int n);
double qsort_time(int* arr , int n);
