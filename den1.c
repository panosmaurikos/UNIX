#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define PERMS 0600
#define SHMSIZE 100
int main(int argc,char** argv)
{
	int i,num[argc],count=0,epan,shmidp;
	double x,r,y,d,p;
	double *datap;
	key_t key;
	key_t key1;
    int *data;
    
    key = 1234;
    key1=9876;
	int shmid;
	
	if ((shmid = shmget(key, SHMSIZE, 0600)) == -1)///dimiourgia mnimis///
	{
	perror("shmget");///elenxos///
	exit(1);
	}
	data = shmat(shmid,NULL, 0);///metabliti gia antalagi///
	if (data == (int *)(-1)) 
	{
	perror("shmat");///elenxos///
	exit(1);
	}
	if ((shmidp = shmget(key1, SHMSIZE, 0600)) == -1) ///dimiourgia mnimis///
				{
					perror("shmget");///elenxos///
					exit(1);
				}
	datap = shmat(shmidp,NULL, 0);///metabliti gia antalagi///
				if (datap == (double*)(-1)) 
				{
					perror("shmat");///elenxos///
					exit(1);
				}	
				
	for (i=1;i<argc; i++)
	num[i]=atoi(argv[i]);

	epan=num[argc-1]/(argc-2);///epanalifis kathe pediou ///
	//printf("epan=%d/%d ara %d\n",num[argc-1],argc-2,epan);
	
	//printf("Eimai to paidi %d kai kanw %d epanalhpseis\n",*data,epan);
	
	for(i=0;i<epan;i++)
	{
		r=(double)num[*data]/2; ///upologismos pleuras ///
		//printf("koita to r \n %f",r);
		x=rand()%num[*data]+(rand()%num[*data])*0.01;///tixeo x///
		y=rand()%num[*data]+(rand()%num[*data])*0.01;///tixeo y///
		d=sqrt(pow((x-r),2)+pow((y-r),2));///upologismos euklidias apostasis///
		if(d<=r)///eimai mesa ston kyklo ??///
		count++;
	}
	//printf("mpika %d apo ta %d",count,epan);
	p=(double)4*count/epan;
	*datap=p;
	//printf("apo paidi erxetai !!!p=%lf\n",p);
	
	return 0;
}
