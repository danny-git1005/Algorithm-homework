#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int min(int first, int second);
int max(int first, int second);


int main ()
{	
	int n = 0, m = 0;
	int i = 0,j = 0;

	scanf("%d",&n);
	scanf("%d",&m);
	
	int **a = malloc( n*sizeof(int));
	for(i = 0; i < n ;i++)
	{
		a[i] = malloc( 2*sizeof(int));
	}
	
	for(i = 0;i< n;i++)
	{
		
		a[i][0] = 0;
		a[i][1] = 0;
	
	}
	
	int temp;
	int sum = 0;
	
	for(i = 0;i < n; i++ )
	{
		scanf("%d",&temp);
		a[i][0] = temp; 
	}
	
	
	for( i = 0;i<n;i++)
	{
		sum = (sum*2)%1000000007;
		for( j = 0 ; j < i;j++)
		{
			if( (( -m <= a[i][0] - a[j][0] ) && ( a[i][0] - a[j][0] <= 0) ) ||  ( 0 <=a[i][0] - a[j][0])&&( a[i][0] - a[j][0] <= m ) ) 
			{
				sum =  (sum+a[j][1]+1)%1000000007;
				printf("sum1 =%d\n",sum);
			}
			else
			{
				a[i][1] += (a[j][1]+1)%1000000007;
				printf("sum2 =%d\n",sum);
			}
		}
	}
	
	for(i = 0;i < n; i++ )
	{
		printf("%d %d \n", a[i][0],a[i][1]);
	}
	
	printf("%d",sum);
	
	return 0;
} 







