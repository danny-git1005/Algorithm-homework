#include <stdio.h>

int main ()
{	
	int n = 0;
	int i = 0,j = 0;
	int count = 0;

	scanf("%d",&n);
	
	long long M[n];
	
	for(i = 0;i < n; i++ )
	{
		scanf("%lld",&M[i]);
	}
	
	long long temp = 0;
	int left = 0;
	int right = n-1;
	int shift = 0;
	int swap1=1,swap2=1;
	int k = 0;
	while(left < right)
	{
		swap1 = 0;
		swap2 = 0;
		for(j = left;j < right;++j)
		{
			if( M[j] > M[j+1])
			{
				temp =  M[j];
				M[j] = M[j+1];
				M[j+1] = temp; 
				
				swap1 = 1;
			}
			
		}
		
		--right;
		
		
		printf("count = %d\t",count);
		for(k = 0;k<n;k++)
		{
			printf("%lld ",M[k]);
		}
		printf("swap1 = %d",swap1);
		printf("\n");
		

		for(j = right-1;j >= left;--j)
		{
			if( M[j] > M[j+1])
			{
				temp =  M[j];
				M[j] = M[j+1];
				M[j+1] = temp; 
				
				swap2 = 1;
			}
		}
		
		count += 1;
		++left;
		
		printf("count = %d\t",count);
		for(k = 0;k<n;k++)
		{
			printf("%lld ",M[k]);
		}
		printf("swap2 = %d",swap2);
		printf("\n");
		
		if(swap1 == 0 && swap2 == 0 )
		{
			break;
		}
		
	}
	printf("\n");
	
	for(k = 0;k<n;k++)
	{
		printf("%lld ",M[k]);
		if(k%10 == 9)
		{
			printf("\n");
		}
	}
	printf("\n");
	
	printf("%d\n",2*count-1);
	

	return 0;
}



