#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
	int num;
	int index;
}term;

int compare(const void* a, const void* b)
{
	const term *q = (const term *)a;
	const term *d = (const term *)b;
	
	return ( q->num - d->num);
}

int main ()
{	
	int n = 0;
	int i = 0,j = 0;
	int count = 0, verify = 1;

	scanf("%d",&n);
	
	term M[n];
	
	for(i = 0;i < n; i++ )
	{
		scanf("%d",&M[i].num);
		M[i].index = i;
	}
	
	qsort(M,n,sizeof(term),compare);
	
	for(i = 0;i<n;i++)
	{
		printf("%d ",M[i].num);
	}
	
	for(i = 0;i<n/2+1;i++)
	{
		if(M[i].index - i > count)
		{
			count = M[i].index - i;
		}
	}
	
	printf("\n%d",count);
	
	return 0;
}
/*
int qsort(term *a, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = a[left].num;
	int pivot_point = left;
	int temp1,temp2;
	int k = 0;
	
	if(left<right)
	{
		for(j = left+1; j <= right ; j++)
		{
			if(a[j].num <= pivot)
			{
				i++;
				
				swap(&a[i],&a[j]);
				/*
				temp1 = a[i].num;
				a[i].num = a[j].num;
				a[j].num = temp1;
				
				temp2 = a[i].index;
				a[i].index = a[j].index;
				a[j].index = temp2;
				
			}
			
		}
		
		pivot_point = i;
		
		swap(&a[left],&a[pivot_point]);
		
		temp1 = a[left].num;
		a[left].num = a[pivot_point].num;
		a[pivot_point].num = temp1;
		
		temp2 = a[left].index;
		a[left].index = a[pivot_point].index;
		a[pivot_point].index = temp2;
		
		qsort( a , left , pivot_point-1);
		qsort( a , pivot_point+1, right);
	}
	
	return 0;
}


void swap(term *a,term *b)
{
	int temp1 = 0;
	
	temp1 = a->num;
	a->num = b->num;
	b->num = temp1;
	
	temp1 = a->index;
	a->index = b->index;
	b->index = temp1;
	
	return ;
	
}
*/



