#include <stdio.h>
#include <stdlib.h>

typedef struct location		 
{ 
	int row ;		
	int col;		 
}location;

int main ()
{	
	int n = 0,m = 0,i = 0,j = 0;
	int k = 0;
	int island_u = 0,island_v = 0,weight = 0;  
	int start = 0, end = 0;
	int c_num = 0;

	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	
	char **world;
	world = malloc(n*sizeof(char*));
	
	for(i = 0;i <= n; i++)
	{
		world[i] = calloc(m+1,sizeof(char));
	}
	
	for(i = 0;i < n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			if( world[i][j-1] == '\n')
			{
				j -= 1;
			}
			scanf("%c",&world[i][j]);
			if( world[i][j] == 'C')
			{
				c_num ++;
			}
		}
	}
	
	location *explored = calloc(n*m,sizeof(location));
	int forward = 0, back = 0;
	int index = 0;
	
	for(i = 0;i < n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			if( world[i][j] == 'L')
			{
				explored[index].row = i;
				explored[index].col = j;
				index++;
			}	
		}
		if( index == 1)
		{
			break;
		}
	}
	
	int temp = 0,temp0 = 0,temp1 = 0,count = 0,num = 0;;
	for(i = 0; i < k; i++)
	{
		temp = index;
		
		while( count != temp )
		{
			temp0 = explored[count].row;
			temp1 = explored[count].col;

			if( temp0 != 0 && world[temp0-1][temp1] == 'C')			//¤W 
			{
				explored[index].row = temp0-1;
				explored[index].col = temp1;
				world[temp0-1][temp1] = 'X';
				index++;
				c_num--;
			}
			if( temp1 != m-1 && world[temp0][temp1+1] == 'C')		//¥k 
			{
				explored[index].row = temp0;
				explored[index].col = temp1+1;
				world[temp0][temp1+1] = 'X';
				index++;
				c_num--;
			}
			if( temp0 != n-1 && world[temp0+1][temp1] == 'C')		//¤U 
			{
				explored[index].row = temp0+1;
				explored[index].col = temp1;
				world[temp0+1][temp1] = 'X';
				index++;
				c_num--;
			}
			if( temp1 != 0 && world[temp0][temp1-1] == 'C')			//¥ª 
			{
				explored[index].row = temp0;
				explored[index].col = temp1-1;
				world[temp0][temp1-1] = 'X';
				index++;
				c_num--;
			}
			count++;	
		}	
		if( c_num == 0)
		{
			break;
		}
	}
	//printf("\n");
	for(i = 0;i < n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			printf("%c",world[i][j]);
		}
	}
	free(explored);
	return 0;
} 


/*
1 1 1
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCL
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
*/
/*
5 2 1
CC
CC
CC
CC
CC
*/




