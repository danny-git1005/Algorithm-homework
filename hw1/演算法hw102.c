#include <stdio.h>


int main ()
{	
	int n = 0;
	long d = 0;
	int i = 0,j = 0;
	long num = 0;
	int certify = 0,count = 0;
	
	scanf("%d",&n);
	scanf("%ld",&d);
	
	long M[n];
	
	for(i = 0;i < n; i++ )
	{
		scanf("%ld",&M[i]);
	}
	
	j = n-1;
	count = 0;
	while( j>=0 )
	{
		//printf("num = %ld\n", num);
		if(num == d) break;
		while(num < d)
		{
			if(j<0) break;
			
			num +=  M[j];
			j--;
			count++;
			//printf("1.num = %ld\n", num);
		}
		while(num > d)
		{
			
			int temp = M[j+count];
			num -= temp;
			count--;
			//printf("2.num = %ld\n", num);
		}
		
	}
	if(num == d)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	
	return 0;
}

