#include <stdio.h>
#include <stdlib.h>

typedef struct airplane			 
{
	int num ;						//�����i�������q 
	struct airplane *next_node;		//�s������@�Ӯq 
	struct airplane *pre_node;		//�s�����e�@�Ӯq 
}airplane;

airplane* insert(airplane *a ,int b);	
airplane* verify(airplane *a,int b);			
void print(airplane *a, int num);
void dfs(airplane *a, int num, int end,int *index, int *queue, int *check);

int main ()
{	
	int n = 0,i = 0,j = 0;
	int island_u = 0,island_v = 0,weight = 0;  
	int start = 0, end = 0;

	scanf("%d",&n);
	
	airplane *island = NULL; 
	airplane *temp = NULL;
	airplane *temp0 = NULL;
	island = malloc(sizeof(airplane)*(n+1));
	
	int **chart;									//�ŧi�G���}�C 
	chart = malloc((n+1)*sizeof(int*));
	
	for(i = 0;i <= n; i++)
	{
		chart[i] = calloc(n+1,sizeof(int));
	}
	
	for(i = 0 ; i <= n ;i++)						//��l�� 
	{
		island[i].pre_node = NULL;
		island[i].next_node = NULL;
		island[i].num = i;
	}
	
	for(i = 0 ; i < n-1;i++)						//��ƿ�J 
	{
		scanf("%d",&island_u);		scanf("%d",&island_v);		scanf("%d",&weight);
		
		temp = verify(&island[island_u],island_v);		temp->next_node = insert(temp,island_v );
		temp0 = verify(&island[island_v],island_u);		temp0->next_node = insert(temp0,island_u );
		chart[island_u][island_v] = weight;				chart[island_v][island_u] = weight;
	}
	
	scanf("%d",&start);
	scanf("%d",&end);
	
	int *index = calloc((n+1),sizeof(int));			//�ݨ��Ǹ`�I�w�y�X�L 
	int *queue = calloc((n+1),sizeof(int));			//�������| (queue[0] ���� queue �s��ĴX�Ӱ}�C)
	int q = 0;
	int *tag = &q;									//�ΨӰO���O�_����I 
	
	dfs(island,start,end,index,queue,tag);

	int first = 0, second = 0;
	int times = 0;
	
	for(i = 1; i < queue[0];i++)					//����g�������i�B�骺�̤p�� 
	{
		first = queue[i];	second = queue[i+1];
		if(i == 1 )
		{
			times = chart[first][second];
		}
		else if( chart[first][second] < times )
		{
			times = chart[first][second];
		}
	}
	
	printf("%d",times);
	
	free(island);
	free(chart);
	
	return 0;
} 

airplane* verify(airplane *a,int b)					//�M��`�I�Ӵ��J����m�A�N�`�I�̤j�p�� 
{
	airplane *next = a;
	
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

airplane* insert(airplane *a,int b)					//���J�`�I 
{	
	airplane *temp1 = (airplane*)malloc(sizeof(airplane));
	
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

void print(airplane *a, int num)
{
	int i = 0;
	airplane *temp;
	
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

void dfs(airplane *a, int num1, int end, int *index, int *queue, int *check)
{
	airplane *temp = &a[num1];
	
	if( *check == 1){ return ;}						//�Y�����|�A�h������^ 
	
	if(index[temp->num] == 0)						//�Y�`�I�S��L�A�h�N����J��C 
	{
		queue[queue[0]+1] = temp->num;
		queue[0] += 1;
		index[temp->num] = 1;
	}
	
	if( temp->num == end)							//�Y���`�I�����I�A�h�Ncheck�]��1�A�ê�^ 
	{
		*check = 1;
		return ;
	}
	temp = temp->next_node;
	
	int current = queue[0];							//������e���`�Iqueue����m 
	while(temp != NULL)								
	{
		if( *check == 1){	return ;}				//�Y�����I�A�h�����~��� 
		if(index[temp->num] == 0)					//�Y�U�@�`�I����L�A�h�~��i��dfs 
		{
			queue[0] = current;						
			dfs(a,temp->num,end,index,queue,check);
		}
		temp = temp->next_node;
	}
	return ;
}








