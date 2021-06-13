#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
	int num ;
	struct item *next_node;
	struct item *pre_node;
}item;

item* insert(item *a ,int b);
item* verify(item *a,int b);
void print(item *a, int num);
void dfs(item *a, int num, int *index);

int main ()
{	
	int n = 0, k = 0;
	int i = 0,j = 0;
	int temp1 = 0,temp2 = 0;  

	scanf("%d",&n);
	
	item *village = NULL; 
	item *temp = NULL;
	item *temp0 = NULL;
	village = malloc(sizeof(item)*(n+1));
	
	for(i = 0 ; i <= n ;i++)
	{
		village[i].pre_node = NULL;
		village[i].next_node = NULL;
		village[i].num = i;
	}
	
	for(i = 0 ; i < n-1;i++)
	{
		scanf("%d",&temp1);
		scanf("%d",&temp2);
		temp = verify(&village[temp1],temp2);
		temp->next_node = insert(temp,temp2 );
		temp0 = verify(&village[temp2],temp1);
		temp0->next_node = insert(temp0,temp1 );
	}
	
	print(village,n);
	
	int *index;
	
	index = calloc((n+1),sizeof(int));
	
	dfs(village,n,index);
	
	free(village);
	free(index);
	
	return 0;
} 

item* verify(item *a,int b)
{
	item *next = a;
	
	if( next->next_node == NULL)
	{
		return a;
	}
	else
	{
		while(1)
		{
			if(  next->next_node != NULL)
			{
				if(next->pre_node == NULL && next->next_node->num <= b)
				{
					return next;
				}
				else if(next->num >= b && next->next_node->num <= b)
				{
					return next;
				}
			}
			else
			{
				return next;	
			} 
			
			next = next->next_node;
		}
	}
}

item* insert(item *a,int b)
{	
	item *temp1 = (item*)malloc(sizeof(item));
	
	temp1->next_node = NULL;
	temp1->pre_node = NULL;
	temp1->num = 0;
	
	temp1->num = b;
	temp1->pre_node = a;
	temp1->next_node = a->next_node;

	if(a->next_node != NULL)
	{
		a->next_node->pre_node = temp1;	
	}
	return temp1;
}


void print(item *a, int num)
{
	int i = 0;
	item *temp;
	
	temp->next_node = NULL;
	temp->pre_node = NULL;
	temp->num = 0;
	
	for (i = 1 ; i <= num ; i++ )
	{
		temp = a[i].next_node;
		printf("%d : ",i);
		while( temp != NULL)
		{
			printf("%d -> ",temp->num);
			temp = temp->next_node;
		}
		printf("\n");
	}
	
	return;
}

void dfs(item *a, int num,int *index)
{
	item *temp = &a[num];
	
	if(index[temp->num] == 0)
	{
		printf("%d ",temp->num);
		index[temp->num] = 1;
	}
	
	temp = temp->next_node;
	
	while(temp != NULL)
	{
		if(index[temp->num] == 0)
		{
			dfs(a,temp->num,index);
		}
		temp = temp->next_node;
	}
		
	return ;
}








