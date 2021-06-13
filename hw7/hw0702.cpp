#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <cstdlib>
using namespace std; 

bool bfs(int **rGraph, int s, int t, int parent[],int n) ;
int fordFulkerson(int **graph, int s, int t,int n) ;

int main() 
{ 
	int n = 0,m = 0,s = 0,t = 0;
	int i = 0,j = 0;
	int temp1 = 0, temp2 = 0, weight = 0;
	
	cin >> n >> m ;
	
	int **bytes;
	bytes = (int**)malloc((n+2)*sizeof(int*));
	
	for(i = 0; i < n+2 ; i++)
	{
		bytes[i]= (int*)calloc(n+2,sizeof(int));
	}
	
	for(i = 1; i < n+1 ; i++)
	{
		cin >> temp1 ;
		bytes[0][i] = temp1;
		bytes[i][0] = temp1;
	}
	for(i = 1; i < n+1 ; i++)
	{
		cin >> temp1 ;
		bytes[n+1][i] = temp1;
		bytes[i][n+1] = temp1;
	}
	
	for( i = 0 ; i < m; i++)
	{
		cin >> temp1 >> temp2 >> weight;
		
		bytes[temp1][temp2] += weight;
		bytes[temp2][temp1] += weight;
	}
	
	cout << fordFulkerson(bytes, 0, n+1,n); 

	return 0; 
} 

bool bfs(int **rGraph, int s, int t, int parent[],int n) 
{ 
	bool visited[n+2]; 
	memset(visited, 0, sizeof(visited)); 

	
	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 

	// Standard BFS Loop 
	while (!q.empty()) 
	{ 
		int u = q.front(); 
		q.pop(); 

		for (int v=0; v<n+2; v++) 
		{ 
			if (visited[v]==false && rGraph[u][v] > 0) 
			{ 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true; 
			} 
		} 
	} 

	return (visited[t] == true); 
} 

int fordFulkerson(int **graph, int s, int t,int n) 
{ 
	int u, v; 
	int i = 0;
	
	
	int **rGraph;
	rGraph = (int**)malloc((n+2)*sizeof(int*)); 
	
	for(i = 0; i < n+2; i++)
	{
		rGraph[i] = (int*)calloc(n+2,sizeof(int));
	}
	
	
	for (u = 0; u < n+2; u++)
	{
		for (v = 0; v < n+2; v++) 
		{
			rGraph[u][v] = graph[u][v]; 
		}
	 } 
		
	
	int parent[n+2]; 

	int max_flow = 0; 

	
	while (bfs(rGraph, s, t, parent,n)) 
	{ 
		
		int path_flow = INT_MAX; 
		for (v=t; v!=s; v=parent[v]) 
		{ 
			u = parent[v]; 
			path_flow = min(path_flow, rGraph[u][v]); 
		} 
 
		for (v=t; v != s; v=parent[v]) 
		{ 
			u = parent[v]; 
			rGraph[u][v] -= path_flow; 
			rGraph[v][u] += path_flow; 
		} 

		max_flow += path_flow; 
	} 

	return max_flow; 
} 

//°Ñ¦Òhttps://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/ 

