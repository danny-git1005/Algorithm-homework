#include <stdio.h>
#include <stdlib.h>


int min(int first, int second);
int max(int first, int second);

typedef struct num
{
	int first ;
	int second;
}num;

int main ()
{	
	int n = 0, k = 0;
	int i = 0,j = 0;

	scanf("%d",&n);
	scanf("%d",&k);
	
	num **a = malloc( (n/k)*sizeof(num));
	for(i = 0; i< n/k ;i++)
	{
		a[i] = malloc( (i+1)*sizeof(num));
	}
	
	for(i = 0;i< n/k;i++)
	{
		for(j = 0;j<=i;j++)
		{
			a[i][j].first = 0;
			a[i][j].second = 0;
		}
	}
	
	int temp;
	int q = n/k;
	
	for(i = 0;i < q; i++ )
	{
		for( j = 0 ; j<k;j++)
		{
			scanf("%d",&temp);
			a[i][i].first += temp; 
		} 
		a[i][i].second = 0;
	}
	
	
	for(i = 1;i < n/k; i++)
	{
		for(j = i-1;j>=0;j--)
		{
			a[i][j].first = max( a[j][j].first + a[i][j+1].second , a[i][i].first + a[i-1][j].second );
			if( a[j][j].first + a[i][j+1].second > a[i][i].first + a[i-1][j].second )
			{
				a[i][j].second = a[i][j+1].first; 
			}
			else
			{
				a[i][j].second = a[i-1][j].first;
			}
		}
	}

	int b_sum = a[n/k-1][0].first;
	int a_sum = a[n/k-1][0].second;
	
	for(i = 0; i<n/k;i++)
	{
		for(j = 0;j < n/k ;j++)
		{
			printf("(%d , %d )",a[i][j].first,a[i][j].second);
		}
		printf("\n");
	}
	
	
	if(b_sum > a_sum)
	{
		printf("Bogay\n");
		printf("%d %d",b_sum,a_sum);
	}
	else if ( b_sum < a_sum )
	{
		printf("aserf18766\n");
		printf("%d %d",b_sum,a_sum);
	}
	else
	{
		printf("TIE\n");
		printf("%d %d",b_sum,a_sum);
	}
	
	return 0;
} 

int max(int first, int second)
{
	if (first > second)
	{
		return first;
	}
	else
	{
		return second;
	}
}





