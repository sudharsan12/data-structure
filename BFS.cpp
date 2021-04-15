// breath first search
//
// here we need three need 3 data structure
//    1. graph- used data stored
//    2. queue- stored the graph node stored data collect in to the queue
//    3. array- this used for stored visited node find out that we used

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void add_edge(vector<int>graph[],int u,int v)
{
	graph[u].emplace_back(v);
	graph[v].emplace_back(u);
}
void bfs(vector<int>graph[],int start)
{
	vector<bool>visited(graph->size(),false);///this used as  a array
	queue<int>q;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		int v=q.front();
		cout<<v<<"  ";
		q.pop();
		for(auto i=graph[v].begin();i!=graph[v].end();i++)
		{
			if(!visited[*i]){
				q.push(*i);
				visited[*i]=true;
			}
		}
	}
}

int main()
{
	int V=7;
	vector<int>graph[V];
	add_edge(graph,0,1);
	add_edge(graph,0,3);
	add_edge(graph,1,2);
	add_edge(graph,2,6);
	add_edge(graph,3,4);
	add_edge(graph,4,5);
	add_edge(graph,5,6);
	cout<<"BFS travesal starting from node 0:"<<"  ";
	bfs(graph,0);
		return 0;

}
