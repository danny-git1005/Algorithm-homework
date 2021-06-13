#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Floyd(int **a, int b);


int main ()
{	
	int n = 0,m = 0,i = 0,j = 0,k = 0;
	int id[4] = {0};
	int stop_u = 0,stop_v = 0,weight = 0;  
	
	scanf("%d %d",&n,&m);
	
	
	int **graph = calloc(n+1,sizeof(int *));
	int *index = calloc(n+1,sizeof(int));
	for(i = 0 ; i < n+1 ; i++)
	{
		graph[i] = calloc(n+1,sizeof(int));
	}
	
	for(i = 0 ; i < n+1 ; i++)
	{
		for(j = 0 ; j < n+1 ; j++)
		{
			graph[i][j] = 3000001;
		}
	}
	
	for(i = 0 ; i < m ;i++)						//¸ê®Æ¿é¤J 
	{
		scanf("%d",&stop_u);		scanf("%d",&stop_v);		scanf("%d",&weight);
		if( weight < graph[stop_u][stop_v])
		{
			graph[stop_u][stop_v] = weight;
		}
		
		if(stop_u == stop_v)
		{
			index[stop_u] = weight;
		}
	}
	
	Floyd(graph,n);
	/*for( i = 0;i < n+1 ; i++)
	{
		for(j = 0; j < n+1;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}*/
	int min = 3000001;
	
	for( i = 1;i < n+1 ; i++)
	{
		if(graph[i][i] < min)
		{
			min = graph[i][i];
		}
	}
	
	if(min == 3000001)
	{
		printf("-1");
	}
	else
	{
		printf("%d",min);
	}
	
	return 0;
} 


void Floyd(int **a, int b)
{
	int i = 0,j = 0,k = 0;
	
	for(i = 1;i < b+1; i++)
	{
		for(j = 1;j < b+1; j++)
		{
			for(k = 1;k < b+1; k++)
			{
				if( a[i][j] > a[i][k] + a[k][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	for(i = b;i > 0; i--)
	{
		for(j = b;j > 0; j--)
		{
			for(k = b;k > 0; k--)
			{
				if( a[i][j] > a[i][k] + a[k][j])
				{
					a[i][j] = a[i][k]+a[k][j];
				}
			}
		}
	}
}









