#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct salesman			 
{
	long long weight;
	int num;
	struct salesman *pre_node;
	struct salesman *next_node;
}salesman;

typedef struct heap			 
{
	long long weight;
	int num;
}heap;

salesman* insert(salesman *a ,int b,int c);	
salesman* verify(salesman *a,int b,int c);			
void print(salesman *a, int num);
long long dijkstra (salesman *a, int b,int c,int num);

bool operator<(heap a, heap b)
{
     if( a.weight == b.weight ) return a.num > b.num;
     return a.weight > b.weight; 
}
 
int main ()
{	
	int n = 0,m = 0,i = 0,j = 0,k = 0;
	int id[4] = {0};
	int stop_u = 0,stop_v = 0,weight = 0;  

	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&id[0],&id[1],&id[2],&id[3]);	//id[0] 代表 H  id[1] 代表 s1  id[2] 代表 s2  id[3] 代表 c  
	
	salesman *stop = NULL; 
	salesman *temp = NULL;
	salesman *temp0 = NULL;
	stop =(salesman*) malloc(sizeof(salesman)*(n+1));
	
	for(i = 0 ; i <= n ;i++)						//初始化 
	{
		stop[i].pre_node = NULL;
		stop[i].next_node = NULL;
		stop[i].num = i;
		stop[i].weight = 0;
	}
	for(i = 0 ; i < m ;i++)						//資料輸入 
	{
		scanf("%d",&stop_u);		scanf("%d",&stop_v);		scanf("%d",&weight);
		
		temp = verify(&stop[stop_u],stop_v,weight);		temp->next_node = insert(temp,stop_v ,weight);
		temp0 = verify(&stop[stop_v],stop_u,weight);		temp0->next_node = insert(temp0,stop_u ,weight);
	}

	int start = 0,end = 0;
	long long times = 0;
	
	for( i = 0; i < 4 ;i++)
	{
		if( i == 3)
		{
			start = id[3];
			end = id[0];
		}
		else
		{
			start = id[i];	end = id[i+1];
		}
		times += dijkstra(stop, start, end,n);
	}
	
	printf("%ld",times);
	return 0;
} 

salesman* verify(salesman *a,int b,int c)					//尋找節點該插入的位置，將節點依大小排 
{
	salesman *next = a;
	
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
				if(next->pre_node == NULL && next->next_node->weight >= c)
				{
					return next;
				}
				else if(next->weight <= c && next->next_node->weight >= c)
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

salesman* insert(salesman *a,int b,int c)					//插入節點 
{	
	salesman *temp1 = (salesman*)malloc(sizeof(salesman));
	
	temp1->next_node = NULL;
	temp1->pre_node = NULL;
	temp1->num = 0;
	
	temp1->num = b;
	temp1->weight = c;
	temp1->pre_node = a;
	temp1->next_node = a->next_node;

	if(a->next_node != NULL)
	{
		a->next_node->pre_node = temp1;	
	}
	return temp1;
}

void print(salesman *a, int num)
{
	int i = 0;
	salesman *temp = (salesman*) malloc(sizeof(salesman));
	
	temp->next_node = NULL;
	temp->pre_node = NULL;
	temp->num = 0;
	
	for (i = 1 ; i <= num ; i++ )
	{
		temp = a[i].next_node;
		printf("%d : ",i);
		while( temp != NULL)
		{
			printf("%d[%d] -> ",temp->num,temp->weight);
			temp = temp->next_node;
		}
		printf("\n");
	}
	return;
}

long long dijkstra(salesman *a, int b, int c,int num)
{
	int i = 0,o = 0;
	salesman *temp = a[b].next_node;
	//printf("1\n");
	long long *check = (long long*)calloc(num+1,sizeof(long long));
	long long *check2 = (long long*)calloc(num+1,sizeof(long long));
	long long *t = (long long*)calloc(num+1,sizeof(long long));
	
	priority_queue<heap> p;
	
	for(i = 0; i < num+1; i++)
	{
		t[i] = 1000000000000;
		if(i == b)
		{
			t[i] = 0;
		}
	}
	

	heap visit ;
	visit.weight = 1000000000000;
	int *mark = (int*)calloc(num+1,sizeof(int));
	while( temp != NULL )
	{
		t[temp->num] = temp->weight;
		visit.weight = temp->weight;
		visit.num = temp->num;
		p.push(visit);
		temp = temp->next_node;
	}
	mark[b] = 1;
	int index = 0;
	
	salesman *temp1 = NULL;
	heap get;
	
	
	while(1)
	{
		get = p.top();
		if( get.num == c )
		{
			break;
		}
		if( mark[get.num] == 1)
		{
			p.pop();
			continue;
		}
		p.pop();
		mark[get.num] = 1;
		
		temp1 = a[get.num].next_node;
		while( temp1 != NULL)
		{
			if( t[temp1->num] > t[get.num] + temp1->weight)
			{
				t[temp1->num] = t[get.num] + temp1->weight;
			}
			if(mark[temp1->num] == 0 )
			{
				visit.num = temp1->num;
				visit.weight = t[temp1->num];
				p.push(visit);
			}
			temp1 = temp1->next_node;
		}
	}
	printf("\n--------------------------\n");
	for(i = 1;i < num+1; i++)
	{
		printf("%ld	",t[i]);
	}
	printf("\n");
	for(i = 1;i < num+1; i++)
	{
		printf("%d	",mark[i]);
	}
	printf("\n--------------------------\n");
	
	
	return get.weight;
}







