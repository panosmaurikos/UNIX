#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define PERMS 0600
#define SHMSIZE 100


int main (int argc,char* argv[])
{
	
	key_t key;
	key_t key1;
    int *data;
    double *datap;
    double p[argc-2];
    
    key = 1234;
    key1=9876;
	int x,l,i,shmid,shmidp;
	
	
	srand(time(0));
	int num[argc];/// pinakas opou mpainoun oi times pou dinei o xristis///
	
	for(x=1;x<argc;x++)
	{
	num[x]= atoi(argv[x]);/// to atoi metatrepei ena char se int ///
	}			
	
	l=num[argc-1];/// gia na bro ta loops ///
	printf("loops:%d\n",l);///ektiposi ton loops///
	printf("the numder of children is:%d\n\n",argc-2);///gia na bro ta paidia ///
	if ((shmid = shmget(key, SHMSIZE, 0600| IPC_CREAT)) == -1) ///dimiourgia mnimis mother -p///
				{
					perror("shmget");///elenxos///
					exit(1);
				}
				data = shmat(shmid,NULL, 0);///metabliti gia antalagi (data)///
				if (data == (int *)(-1)) 
				{
					perror("shmat");///elenxos///
					exit(1);
				}
			if ((shmidp = shmget(key1, SHMSIZE, 0600| IPC_CREAT)) == -1) ///dimiourgia mnimis p-mother (data2)///
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
	for(i=1;i<=argc-2;i++)/// gia osa paidia einai kano to loop///
	{
		int arr[i];
		if(fork()==0)
		{
				*data=i;///poio paidi einai///	
				arr[i]=getpid();
				//printf("pid:%d \n",arr[i]);
				execvp("./den1",argv);
		}
		else wait(NULL);	
		p[i]=*datap;
		
		//shmdt(data2);	///thn apodesmeuei ////
		//shmctl(shmid2,IPC_RMID,NULL);
	}
	for(i=1;i<=argc-2;i++)
	printf("To paidi %d upologise %lf gia thn pleura %d\n",i,p[i],num[i]);
	
	shmdt(data);	///thn apodesmeuei ////
	shmctl(shmid,IPC_RMID,NULL);
	shmdt(datap);	///thn apodesmeuei ////
	shmctl(shmidp,IPC_RMID,NULL);
return 0 ;
}



