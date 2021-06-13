#include <stdio.h>
#include <stdlib.h>

int sort(long *a , int c, long long *count);
int merge(long *a,int num1 ,long *b, int num2, long *c,long long *count);

//long count = 0;


int main ()
{	
	int n = 0;
	int i = 0,j = 0;
	int check = 0;

	scanf("%d",&n);
	
	long M_even[n/2];
	long M_odd[n/2+1]; 
	int q = 0, w = 0;
	
	for(i = 0;i < n; i++ )
	{
		if(i%2 == 0)
		{
			scanf("%ld",&M_odd[q]);
			q++;
		}
		else
		{
			scanf("%ld",&M_even[w]);
			w++;
		}
	}
	long long count1 = 0;
	long long count2 = 0;
	
	long long *ptr_c1 = &count1;
	long long *ptr_c2 = &count2;
	
	sort(M_even,w,ptr_c1);
	sort(M_odd,q,ptr_c2);
	
	//printf("count1 = %d\n",count1);
	//printf("count2 = %d\n",count2);
	
	for(i = 0;i<n;i++)
	{
		
		if( i == n-1)
		{
			break;
		}
		if(i%2 == 0)
		{
			printf("M_odd[%d/2] = %ld\n",i,M_odd[i/2]);
			if(M_odd[i/2] > M_even[i/2]) 
			{
				//printf("odd\n");
				//printf("M_odd[%d/2] = %ld\n",i,M_odd[i/2]);
				//printf("M_even[%d/2] = %ld\n",i,M_even[i/2]);
				check = 1;
			}
		}
		else
		{
			printf("M_even[%d/2] = %ld\n",i,M_even[i/2]);
			if(M_even[i/2] > M_odd[i/2+1])
			{
				//printf("even\n");
				//printf("M_even[%d/2] = %ld\n",i,M_even[i/2]);
				//printf("M_odd[%d/2] = %ld\n",i,M_odd[i/2]);
				check = 1;
			}
		}
		/* 
		if(check == 1)
		{
			break;
		}*/
	}
	
	if(check == 1)
	{
		printf("no\n");
	}
	else
	{
		printf("yes\n");
	}
	printf("%d",count1+count2);
	
	return 0;
}

int sort(long *a , int c,long long *count)
{
	int w = 0;
	
	if(c > 1)
	{
		int i = 0,k = 0;
		int mid = c/2;
		long *A;
		long *B;
		
		
		A = calloc(mid,sizeof(long));
		B = calloc(c-mid,sizeof(long));
		
		for(i = 0;i<mid;i++)
		{
			A[i] = a[i];
		}
		for(i = mid;i<c;i++)
		{
			B[i-mid] = a[i];
		}
		
		int cal0 = 0,cal1 = 0;
		int *ptr_0 = &cal0;
		int *ptr_1 = &cal1;
		
		
		sort(A,mid,count);
		sort(B,c-mid,count);
		//printf("\n************\n");
		//printf("count_1 = %d\n",*count);
		
		merge(A,mid,B,c-mid,a,count);
		
		free(A);
		free(B);
		
	}
	
	return 0;
}

int merge(long *a,int num1 ,long *b, int num2, long *c,long long *count)
{
	int count3 = 0;
	int i = 0,j = 0,k = 0;
	while(i < num1 && j < num2 )
	{
		if(a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			*count =  *count + (num1 - i);
			j++;
		}
		k++;
	}
	while(i < num1)
	{
		c[k++] = a[i++];
	}
	while(j < num2)
	{
		c[k++] = b[j++];
	}
	
	return 0;
}









