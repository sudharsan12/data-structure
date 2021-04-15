#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
                                   
vector<int>dijkstra(vector<vector<pair<int,int>>>graph,int start)
{
	vector<int>dist(graph.size(),INT_MAX);

	// <weight,vertex> pair first element of prority queue will be the minimum
	//    priority_queue(int value,int *a[],*greater);// value,strored arrary, greater funtion
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

	// add start to pq where distance is 0
	pq.push(make_pair(0,start));
	dist[start]=0;
	while(!pq.empty())
	{
		// get min distance vertex from pq
		int u=pq.top().second;
		pq.pop();
		for(int i=0;i<graph[u].size();i++)
		{
			int v=graph[u][i].first;
			int weight=graph[u][i].second;

			// if the distance to v is shorter by using through 

			if(dist[v]>dist[u]+weight)
			{
				dist[v]=dist[u]+weight;
				pq.push(make_pair(dist[v],v));
			}
		}
	
	}
return dist;
}

void add_edge(vector<vector<pair<int,int>>>&graph,int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

int main()
{
	vector<vector<pair<int,int>>>graph(9,vector<pair<int,int>>(9));

	        
	add_edge(graph,0,1,4); // vertex,vertex,weight
	add_edge(graph,0,7,8);
	add_edge(graph,1,2,8);
	add_edge(graph,1,7,11);
	add_edge(graph,2,3,7);
	add_edge(graph,2,8,2);
	add_edge(graph,2,5,4);
	add_edge(graph,3,4,9);
	add_edge(graph,3,5,14);
	add_edge(graph,4,5,10);
	add_edge(graph,5,6,2);
	add_edge(graph,6,7,1);
	add_edge(graph,6,8,6);
	add_edge(graph,7,8,7);

	vector<int>dist=dijkstra(graph,0);

	cout<<"vertex  distance from source"<<endl;

	for(int i=0;i<9;i++)
		cout<<i<<"\t\t"<<dist[i]<<endl;
	return 0;

}
