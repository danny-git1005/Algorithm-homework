#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct passer
{
	int start_day ;
	int end_day ;
	int times;
}passer;

int cmp(const void* a, const void* b)
{
	const passer *p = (const passer *)a;
	const passer *q = (const passer *)b;
	
	return ( p->end_day - q->end_day);
}

int search(passer *a, int b,int c);
void print(passer *a,int b);

int main ()
{	
	int n = 0;
	int i = 0,j = 0;
	int temp1 = 0,temp2 = 0;  
	int temp = 0;

	scanf("%d",&n);
	
	passer *tour = NULL;
	tour = malloc(sizeof(passer)*n);
	
	for(i = 0 ; i < n ;i++)
	{
		tour[i].start_day = 0;
		tour[i].end_day = 0;
		tour[i].times = 0;
	}
	
	for(i = 0 ; i < n;i++)
	{
		scanf("%d",&temp1);
		scanf("%d",&temp2);
		tour[i].start_day = temp1;
		tour[i].end_day = temp2;
	}
	
	qsort(tour,n,sizeof(passer),cmp);
	//print(tour,n);
	
	int firework[2] = {0};
	int count = 0;
	
	for(j = 0 ; j < n ; j++)
	{
		if(j == 0)
		{
			firework[0] = tour[j].end_day-1;
			firework[1] = tour[j].end_day;
			count += 2;
			continue;
		}
		
		if ( firework[1] == tour[j].start_day ) 
		{
			firework[0] = tour[j].start_day;
			firework[1] = tour[j].end_day;
			count += 1;
		}
		else if ( firework[1] < tour[j].start_day)
		{
			firework[0] = tour[j].end_day-1;
			firework[1] = tour[j].end_day;
			count += 2;
		}
		else
		{
			if( firework[0] < tour[j].start_day )
			{
				firework[0] = firework[1];
				firework[1] = tour[j].end_day;
				count += 1;
			}
			continue;
		}
	}
	
	printf("%d",count);
	free(tour);
	
	return 0;
} 

void print(passer *a,int b)
{
	int i = 0;
	passer *temp = a;
	
	for(i = 0;i < b;i++)
	{
		printf("%d %d\n",temp[i].start_day,temp[i].end_day);
	}
	return ;
}



