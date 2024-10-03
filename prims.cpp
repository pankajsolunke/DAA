#include<iostream>
#include<limits.h>
using namespace std;

int min_key(int key[],bool visited[],int V){
	int min = INT_MAX,min_index = -1;
	for(int v = 0;v < V;v++){
		if(!visited[v] && key[v] < min){
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}

int print_MST(int parent[],int **cost,int V){
	int mincost = 0;
	cout<<"Edge \tWeigth\n";
	for(int i = 1;i < V;i++){
		cout<<parent[i] << " - " << i << "\t" <<cost[i][parent[i]]<<"\n";
		mincost += cost[i][parent[i]];
	}
	cout<<"Total Cost is: "<<mincost<<endl;
}
void find_MST(int** cost,int V){
	int parent[V],key[V];
	bool visited[V];
	for(int i=0;i<V;i++){
		key[i] = INT_MAX;
		visited[i] = false;
		parent[i] = -1;
	}	
	
	key[0]=0;
	parent[0] = -1;
	
	for(int x=0;x<V-1;x++){
		int u = min_key(key,visited,V);
		visited[u] = true;
		
		for(int v = 0;v<V;v++){
			if(cost[u][v] != 0 && !visited[v] && cost[u][v]<key[v]){
				parent[v] = u;
				key[v] = cost[u][v];
			}
		}
	}
	print_MST(parent,cost,V);
}

int main(){
	int V;
	cout<<"Enter the number of vertices: ";
	cin>>V;
	
	int **cost = new int*[V];
	for(int i = 0;i < V;i++)
		cost[i] = new int[V];
	
	cout<<"Enter the adjacency matrix for graph: \n";
	for(int i = 0;i < V;i++){
		for(int j = 0;j < V;j++){
			cin>>cost[i][j];
		}
	}
	
	find_MST(cost,V);
	
	for(int i = 0;i < V;i++){
		delete[] cost[i];
	}
	delete[] cost;
	
	return 0;
}
