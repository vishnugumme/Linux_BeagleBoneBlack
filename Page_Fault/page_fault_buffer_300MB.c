
#include<stdio.h>
#include<stdlib.h>


int main()
{

	int* big_arry= (int *) malloc(300000000);
	int rndm;
	int rndm_sum;
	while(1)
	{
		rndm=rand();

		rndm=rndm%(75000000);
	printf("%d\n",rndm);
		*(big_arry+rndm)=143651;
	}
	return 0;

}
