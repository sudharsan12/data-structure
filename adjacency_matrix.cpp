/*
    ___
    \ /
     B-------C
    /|  \   /|
   / |   \ / |
  A  |   /\  | 
   \ |  /   \|
     E      D



*/
#include<iostream>
using namespace std;

#define V 5

void addedge(int graph[][V],int u,int v)
{
	graph[u][v]=1;
}
int main()
{
	int graph[V][V]={0};
	char graph_point[]={'A','B','C','D','E'};

	addedge(graph,0,1);
	addedge(graph,0,4);
	addedge(graph,1,1);
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,1,4);
	addedge(graph,3,2);
	addedge(graph,3,4);

	cout<<"Adjacency matrix :"<<endl;
        cout<<"   ";
	for(int i=0;i<V;i++)
		cout<<graph_point[i]<<"  ";
	cout<<endl;	
	for(int i=0;i<V;i++)
	{
		cout<<graph_point[i]<<"  ";
		for(int j=0;j<V;j++)
			cout<<graph[i][j]<<"  ";
		cout<<endl;
	}

}
