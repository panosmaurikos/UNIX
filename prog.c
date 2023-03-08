#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sin.h"


int main ()
{
	int N,S,error,plithos_u, plithos_i;
	FILE *f1,*f2;
	clock_t t1, t2;
	double ratio = 1./CLOCKS_PER_SEC;
	f1=fopen("sample_2.txt","r");
	f2=fopen("result.txt","w");
	if (f1 == NULL && f2==NULL) 
	{
        printf("file can't be opened \n");
        exit(1);
    }
    printf("\nDoste B: ");	scanf("%d", &B);
    error = initialize(B);
	if(error == -1)	{	printf("\nMAIN: initialize error");		return 0;	}
    //printf("\nDoste N: ");	scanf("%d", &N);
	//printf("\nDoste S: ");	scanf("%d", &S);
	t1 = clock(); 
	error = create_num_id(f1,f2,N,S,&plithos_u, &plithos_i);
	if(error == -1)	{	printf("\nMAIN: create_num_id error");		return 0;	}
	t2 = clock(); 
	printf("Users:%d Items:%d",plithos_u,plithos_i);
	printf("\nTime = %g seconds", ratio*(long)t2 - ratio*(long)t1 );

	fclose(f1);
 	fclose(f2);
	return 0;
}

