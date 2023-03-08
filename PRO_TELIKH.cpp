#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* deiktis;
typedef struct node
{
	char name[50];
	char items[50];
	int  ratting;
	int  time;
	int idu;
	int idi;
	int itemcount;
	deiktis next;
}node;

deiktis *arrayU;
deiktis *arrayI;
deiktis fin;	
deiktis temp;
int B=3;

int hash_func(char* name);
int initialize (int B);
void create_num_id (FILE* f1, FILE* f2);
int return_id (node **cur,char* name, char eidos);

int main ()
{
	FILE *f1,*f2;
	f1=fopen("sample_2.txt","r");
	f2=fopen("result.txt","w");
	if (f1 == NULL && f2==NULL) 
	{
        printf("file can't be opened \n");
        exit(1);
    }
    create_num_id(f1,f2);
	
	fclose(f1);
 	fclose(f2);
	return 0;
}

void create_num_id (FILE* f1, FILE* f2)
{
	node *array;	
	deiktis neos_kombos;
	char onoma[50],items[50],u='u',it='i';
	int i,j,pos,count,ratting,time,idu=0,idi=0,check,c1,k;
	for(count=0;!feof(f1);count++) 
	{
		fscanf(f1,"%s %s %d %d  ",onoma,items,&ratting,&time);
	}
	array=(node*)malloc(count*sizeof(node));
	if(array==NULL)
	{
		printf("Lathos malloc");
		exit(1);
	}
	fseek(f1,0,SEEK_SET);
	int ite[count],on[count],rat[count],tim[count],temp_1,temp_2,temp_3,temp_4;
	for(i=0;i<count;i++)
	{
		fscanf(f1,"%s %s %d %d",onoma,items,&ratting,&time);
		strcpy(array[i].name,onoma);
		strcpy(array[i].items,items);
		array[i].ratting=ratting;
		array[i].time=time;
	}
	
	if(initialize (B)==1)
	{
		for(i=0;i<count;i++)
		{
			check=0;
			temp = (deiktis)malloc(sizeof(node));
			if(array==NULL)
			{
				printf("Lathos malloc to temp");
				exit(1);
			}
			pos=hash_func(array[i].name);
			strcpy(temp->name,array[i].name);
			strcpy(temp->items,array[i].items);
			temp->ratting=array[i].ratting;
			temp->time=array[i].time;
			temp->idu=idu;
			temp->next=NULL;
		
		
			if(arrayU[pos]==NULL)
			{
				arrayU[pos]=temp;
				//printf("1ST TIME     {%d}  IDu:%d      %s \n",pos,arrayU[pos]->idu,arrayU[pos]->name);
			}
			else
			{
				for( fin=arrayU[pos]; fin!=NULL;  fin=fin->next )
				{
					//printf("mphke sthn epanalipsi sugkrisi %s me %s ",fin->name,array[i].name);
					if( strcmp(fin->name,array[i].name) == 0 )
					{
						check=1;
						//printf("brike idio \n");
						break;
					}
					else
					{
						//printf("den brike \n");
						check=2;
					}
				}
				if(check==2)
				{
					neos_kombos=temp;
        			neos_kombos->next = arrayU[pos];
        			arrayU[pos] = neos_kombos;
        			//printf("CREATE NODE  {%d}  IDu:%d       %s\n",pos,arrayU[pos]->idu,arrayU[pos]->name);
        			//printf("%s",arrayU[pos]->name);
        		}
        		else
        		continue;
        	}
    	    idu++;		
		}
		
		k=1;
		
		
		
		
		
		
		
		
		for(i=0;i<count;i++)
		{
			check=0;
			temp = (deiktis)malloc(sizeof(node));
			pos=hash_func(array[i].items);
			strcpy(temp->name,array[i].name);
			strcpy(temp->items,array[i].items);
			temp->ratting=array[i].ratting;
			temp->time=array[i].time;
			temp->idi=idi;
			temp->itemcount=k;
			temp->next=NULL;
			
			if(arrayI[pos]==NULL)
			{
				arrayI[pos]=temp;
				//k[pos]=k[pos]+1;
				//printf("1ST TIME     {%d}  IDi:%d      %s \n",pos,arrayI[pos]->idi,arrayI[pos]->items);
			}
			else
			{
				//printf("eimaste sthn epanalipsi {%d}->",i);
				for( fin=arrayI[pos]; fin!=NULL;  fin=fin->next )
				{
					//printf("\nSugkrisi %s me %s: ",fin->items,array[i].items);
					if( strcmp(fin->items,array[i].items) == 0 )
					{
						//printf("Einai idio");
						arrayI[pos]->itemcount=k++;
						check=1;
						//printf("Hrthe to item:%s kai ekane to k[%d]= %d\n",array[i].items,pos,fin->itemcount);
						//printf("brike idio \n");
						break;
					}
					else
					{
						//printf("den brike \n");
						check=2;
					}
				}
				if(check==2)
				{
					neos_kombos=temp;
        			neos_kombos->next = arrayI[pos];
        			arrayI[pos] = neos_kombos;
        			//printf("CREATE NODE  {%d}  IDi:%d       %s\n",pos,arrayI[pos]->idi,arrayI[pos]->items);
        			//printf("%s",arrayI[pos]->items);
        		}
      		  	else
      		  	continue;
      	  	}
      	  	
      	  	
      	  	
        	idi++;
        	//printf("%d \n",k);
		}
		
		
		fprintf(f2,"%d %d\n",idu,idi);
		//printf("\n%d %d\n\n",idu,idi);
		
		
		for(i=0;i<count;i++)
		{
			pos = hash_func(array[i].name);
			on[i]= return_id(&arrayU[pos],array[i].name,u);
			pos = hash_func(array[i].items);
			ite[i]	= return_id(&arrayI[pos],array[i].items,it);
			rat[i]=array[i].ratting;
			tim[i]=array[i].time;
			//printf("%d  %d\n",on[i],ite[i]);
			//fprintf(f2,"%d  %d  %d  %d\n",on[i],ite[i],array[i].ratting,array[i].time);
		}
		
		for(i=0; i<count; i++)																				
		{																									
			for(j=count-1; j > i; j--)																		
			{																								
				if(on[j] < on[j-1])																		
   				{																				
					temp_1 = on[j];     																		
 		   			on[j] = on[j-1];            										
 					on[j-1] = temp_1;																				
			 																										
   					temp_2= ite[j];																						
					ite[j]=ite[j-1];												
					ite[j-1]=temp_2;
					
					temp_3= rat[j];																			
					rat[j]= rat[j-1];								
					rat[j-1]=temp_3;																		
																												
					temp_4= tim[j];															
					tim[j]= tim[j-1];												
					tim[j-1]= temp_4;
				}
			}
		}
		
		for(i=0;i<count;i++)
		{
			//printf("%d  %d\n",on[i],ite[i]);
			fprintf(f2,"%d  %d  %d  %d\n",on[i],ite[i],rat[i],tim[i]);
		}
		
		//for(i=0;i<count;i++)
		//printf("%d  %d\n",on[i],ite[i]);
		//printf("\n");
		/*for(i=0;i<B;i++)
		{
			printf("POS {%d}:",i);
			if(arrayU[i]==NULL)
			{
				printf("NULL");
			}
			else{
			while(arrayU[i]!=NULL)
			{
				printf("%s->",arrayU[i]->name);
				arrayU[i]=arrayU[i]->next;
			}
			printf("NULL");
		}
			printf("\n");
		}
		printf("\n");*/
		
		/*for(i=0;i<B;i++)
		{
			printf("POS {%d}:",i);
			if(arrayI[i]==NULL)
			{
				printf("NULL");
			}
			else
			{
				while(arrayI[i]!=NULL)
				{
					printf("%s %d->",arrayI[i]->items,arrayI[i]->itemcount);
					arrayI[i]=arrayI[i]->next;
				}
				printf("NULL");
			}
			printf("\n");
		}*/
	}
}


int hash_func(char* name)
{
	int pos=0; 
	for (int i=0; i<strlen(name); i++)
	pos=(pos+name[i])%B;
	return pos;
}

int initialize (int B)
{
	arrayU = (deiktis*)malloc(B*sizeof(node));
	arrayI = (deiktis*)malloc(B*sizeof(node));
	for(int i=0; i<B; i++)
	{
		arrayU[i]= NULL;
		arrayI[i]= NULL;
		//printf("ArrayU:%s ArrayI:%s\n",arrayU[i],arrayI[i]);
	}
	if (arrayU==NULL)
	{
		printf("Den egine swsta h desmeush mnhmhs");
		return -1;
	}
	else
	{
		//printf("Egine swsta h desmeush mnhmhs");
		return 1;
	}
}
		
		
int return_id (node **head, char* string, char eidos)
{
	int i;
	char u;
	if(eidos=='u')
	{
		//printf("u: ");
		//printf("%s %d ",temp->name,temp->idu);
		for( fin=*head; fin!=NULL;  fin=fin->next )
		{
			//printf("%s",fin->name);
			if( strcmp(fin->name,string) == 0 )
			{
				return fin->idu;
			}
		}
	}
	else
	{
		//printf("i: ");
		for( fin=*head; fin!=NULL;  fin=fin->next )
		{
			if( strcmp(fin->items,string) == 0 )
			{
				return fin->idi;
			}
		}
	}
	return 0;
}
