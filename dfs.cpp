// depth first search graph

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void add_edge(vector<int>graph[],int u,int v)
{
	graph[u].emplace_back(v);
	graph[u].emplace_back(u);
}

void dfs_iterative(vector<int>graph[],int start)
{
	vector<bool>visited(graph->size(),false);
	stack<int>st;
	st.push(start);
	visited[start]=true;
	while(!st.empty())
	{
		int v=st.top();
		cout<<v<<"  ";
		st.pop();
		for(auto i=graph[v].begin();i!=graph[v].end();i++)
		{
			if(!visited[*i])
			{
				st.push(*i);
				visited[*i]=true;
			}
		}
	}
}

void dfs_recursive(vector<int>graph[],vector<bool>&visited,int node)
{
	visited[node]=true;
	cout<<node<<"  ";
	for(auto i=graph[node].begin();i!=graph[node].end();i++)
	{
		if(!visited[*i])
		{
			dfs_recursive(graph,visited,*i);
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
	cout<<"DFS travesal iterative starting from node 0:"<<"  ";
	dfs_iterative(graph,0);
	cout<<endl;
	cout<<"DFS travesal recursive starting from node 0:"<<"  ";
	vector<bool>visited(graph->size(),false);
	dfs_recursive(graph,visited,0);
	cout<<endl;

		return 0;

}
