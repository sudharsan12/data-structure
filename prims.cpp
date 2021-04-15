#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>>prim(vector<vector<pair<int,int>>>&graph,int start)
{
	vector<int>parent(graph.size(),-1);
	vector<int>key(graph.size(),INT_MAX);
	vector<bool>inMST(graph.size(),false);
	key[start]=0;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push(make_pair(0,start));
	
		
	vector<tuple<int,int,int>>result;
	while(!pq.empty())
	{
	int v=pq.top().second;
	pq.pop();
	if(parent[v]!=-1 && inMST[v]==false)
	result.emplace_back(make_tuple(parent[v],v,key[v]));

			inMST[v]=true;
			cout<<v<<"  "<<pq.top().first<<endl;
			for(auto x: graph[v])
			{
			int av=x.first;
			int weight=x.second;
			if(inMST[av]==false && key[av]>weight)
			{
			parent[av]=v;
			key[av]=weight;
			pq.push(make_pair(key[av],av));
			}
			}
	}
	return result;
}

void add_edge(vector<vector<pair<int,int>>>&graph,int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

int main()
{
	int v=7;
	vector<vector<pair<int,int>>>graph(v,vector<pair<int,int>>(v));
	add_edge(graph,0,1,2);
	add_edge(graph,0,3,7);
	add_edge(graph,0,5,2);
	add_edge(graph,1,2,1);
	add_edge(graph,1,3,4);
	add_edge(graph,1,4,3);
	add_edge(graph,1,5,5);
	add_edge(graph,2,4,4);
	add_edge(graph,2,5,4);
	add_edge(graph,3,4,1);
	add_edge(graph,3,6,5);
	add_edge(graph,4,6,7);

	vector<tuple<int,int,int>>res=prim(graph,0);

	cout<<"minimum spanning tree:"<<endl;
	for(tuple<int,int,int>t:res)
		cout<<get<0>(t)<<" - "<<get<1>(t)<<" , "<<get<2>(t)<<endl;
}
