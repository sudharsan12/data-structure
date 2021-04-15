#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

#define V 6

bool bfs(vector<vector<int>>&residualgraph,vector<int>&level,int source,int sink)
{
	fill(level.begin(),level.end(),-1);
	level[source]=0;
	queue<int>q;
	q.push(source);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=0;v<V;v++)
		{
			if(u!=v && residualgraph[u][v] >0 && level[v]<0)
			{
				level[v]=level[u]+1;
				q.push(v);
			}
		}
	}

	return level[sink]<0 ?false :true;
}

int sendflow(vector<vector<int>>& residualgraph,vector<int>&level,vector<int>&count,int u,int sink,int flow)
{
	if(u==sink)
		return flow;
	if(count[u]==residualgraph[u].size())
		return 0;
	for(int v=0;v<V;v++){
		if(residualgraph[u][v]>0)
		{
			count[u]++;
			if(level[v]==level[u]+1)
			{
				int curr_flow=min(flow,residualgraph[u][v]);
				int min_cap=sendflow(residualgraph,level,count,v,sink,curr_flow);
				if(min_cap>0)
				{
					residualgraph[u][v]-=min_cap;
					residualgraph[u][v]+=min_cap;
					return min_cap;
				}
			}
		}
	}
	return 0;
}

int dinic_algorithm(vector<vector<int>>&graph, int source,int sink)
{
	if(source==sink)
		return -1;
	int max_flow=0;
	vector<vector<int>>residualgraph=graph;
	vector<int>level(V,-1);
	while(bfs(residualgraph,level,source,sink)==true)
	{
		vector<int>count(V,0);
		while(int flow=sendflow(residualgraph,level,count,source,sink,INT_MAX))
			max_flow+=flow;
	}
	return max_flow;
}
void add_edge(vector<vector<int>>& graph,int u,int v,int w)
{
graph[u][v]=w;
}

int main()
{
	vector<vector<int>>graph(V,vector<int>(V,0));
	add_edge(graph,0,1,10);
	add_edge(graph,0,2,10);
	add_edge(graph,1,2,2);
	add_edge(graph,1,3,4);
	add_edge(graph,1,4,8);
	add_edge(graph,2,4,9);
	add_edge(graph,3,5,10);
	add_edge(graph,4,3,6);
	add_edge(graph,4,5,10);

	cout<<"maximum flow: "<<dinic_algorithm(graph,0,5);
	return 0;
}
