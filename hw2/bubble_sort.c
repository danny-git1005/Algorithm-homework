#include <stdio.h>


int main ()
{	
	int n = 0;
	int i = 0,j = 0;
	int count = 0, verify = 1;

	scanf("%d",&n);
	
	long long M[n];
	
	for(i = 0;i < n; i++ )
	{
		scanf("%lld",&M[i]);
	}
	
	long long temp = 0;
	int mark = n;
	int k = 0;
	
	for(k = 0; k < n;k++)
	{
		verify = 0;
		for(j = 0;j < n-k-1;j++)
		{
			if( M[j] > M[j+1])
			{
				temp =  M[j];
				M[j] = M[j+1];
				M[j+1] = temp; 
				
				verify = 1;
			}
		}
		
		count += 1;
		/*
		printf("count = %d\t",count);
		for(i = 0;i<n;i++)
		{
			printf("%lld ",M[i]);
		}
		printf("swap1 = %d",verify);
		printf("\n");
		*/
		if( verify == 0)
		{
			break;
		}
	}
	/*
	for(k = 0;k<n;k++)
	{
		printf("%lld ",M[k]);
		if(k%10 == 9)
		{
			printf("\n");
		}
	}
	printf("\n");
	*/
	printf("\n%d",count-1);
	
	return 0;
}


