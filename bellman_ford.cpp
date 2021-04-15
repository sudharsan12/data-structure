#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

bool bellman_ford(map<pair<int,int>,int>&edge,vector<int>&dist,int V)
{
	for(int i=1;i<V;i++)
	{
		for(auto e:edge)
		{
			int u=e.first.first;
			int v=e.first.second;
			int weight=e.second;
			if(dist[v]>dist[u]+weight)
				dist[v]=dist[u]+weight;
		}
	}
	for(auto e:edge)
	{
		int u=e.first.first;
		int v=e.first.second;
		int weight=e.second;
		if(dist[v]>dist[u]+weight)
			return false;
	}

	return true;
}

void add_edge(map<pair<int,int>,int>&edge,int u,int v,int w)
{
	edge[make_pair(u,v)]=w;
}

int main()
{
	int V=5;
	map<pair<int,int>,int>edge;
	add_edge(edge,0,1,4);
	add_edge(edge,0,2,2);
	add_edge(edge,1,3,2);
	add_edge(edge,1,4,3);
	add_edge(edge,1,2,3);
	add_edge(edge,2,1,1);
	add_edge(edge,2,4,5);
	add_edge(edge,2,3,4);
	add_edge(edge,4,3,-5);
/*
        // this for negative value is exist
	add_edge(edge,0,1,4);
	add_edge(edge,0,2,2);
	add_edge(edge,1,3,2);
	add_edge(edge,1,4,3);
	add_edge(edge,1,2,3);
	add_edge(edge,2,1,-6);
	add_edge(edge,2,4,5);
	add_edge(edge,2,3,4);
	add_edge(edge,4,3,-5);

	*/

	vector<int>dist(V,INT_MAX);
	dist[1]=0;
	bool res=bellman_ford(edge,dist,V);

	if(!res)
		cout<<"negative-weight cycle exists"<<endl;
	else
	{
		cout<<"shortest path distance from start vertex(0) :"<<endl;
		for(int i=0;i<V;i++)
			cout<<"0- "<<i<<" : "<<dist[i]<<endl;
	}
	return 0;
}
