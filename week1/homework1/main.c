#include "uhead.h"

int main()
{
	int* a[UNUMBER] ;
	urand(a , UNUMBER);
	show(a , UNUMBER);
	printf("\n**********\n sum=%d\n",usum(a , UNUMBER));
}
