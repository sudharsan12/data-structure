#include<iostream>
#include<vector>
#include<tuple>
#include<bits/stdc++.h>

using namespace std;

void make_set(vector<int>&parent)
{
	for(int i=0;i<parent.size();i++)
		parent[i]=i;
}

int find(vector<int>&parent,int x)
{
	if(x!=parent[x])
		parent[x]=find(parent,parent[x]);
	return parent[x];
}

void union_set(vector<int>&parent,vector<int>& rank,int x,int y)
{
	int rootX=find(parent,x);
	int rootY=find(parent,y);
	if(rootX==rootY)
		return;
	if(rank[rootX]>rank[rootY])
		parent[rootY]=rootX;
	else
	{
		parent[rootX]=rootY;
		if(rank[rootX]==rank[rootY])
			rank[rootY]++;
	}

}

bool comp(const tuple<int,int,int>&a,const tuple<int,int,int>&b)
{

	int first=get<2>(a);
	int second=get<2>(b);
	if(first<second)
		return true;
	return false;
}

vector<tuple<int,int,int>>kruskal(vector<vector<pair<int,int>>>&graph,vector<tuple<int,int,int>>& alledge)
{
	vector<int>parent(graph.size());
	vector<int>rank(graph.size());
	vector<tuple<int,int,int>>result;
	make_set(parent);
	sort(alledge.begin(),alledge.end(),comp);
	for(tuple<int,int,int>t:alledge)
	{
		int u=get<0>(t);
		int v=get<1>(t);
		int weight=get<2>(t);
		if(find(parent,u)!=find(parent,v))
		{
			result.emplace_back(make_tuple(u,v,weight));
			union_set(parent,rank,u,v);
		}

	}
	return result;
}

void addedge(vector<vector<pair<int,int>>>&graph,vector<tuple<int,int,int>>&alledge,int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
	alledge.emplace_back(make_tuple(u,v,w));
}
int main()
{
	int V=7;
	vector<vector<pair<int,int>>>graph(V,vector<pair<int,int>>(V));
	vector<tuple<int,int,int>>alledge;

	addedge(graph,alledge,0,1,2);
	addedge(graph,alledge,0,3,7);
	addedge(graph,alledge,0,5,2);
	addedge(graph,alledge,1,2,1);
	addedge(graph,alledge,1,3,4);
	addedge(graph,alledge,1,4,3);
	addedge(graph,alledge,1,5,5);
	addedge(graph,alledge,2,4,4);
	addedge(graph,alledge,2,5,4);
	addedge(graph,alledge,3,4,1);
	addedge(graph,alledge,3,6,5);
	addedge(graph,alledge,4,6,7);

	vector<tuple<int,int,int>>res =kruskal(graph,alledge);
	cout<<"Minimum spanning tree"<<endl;
	for(tuple<int,int,int>t:res)
		cout<<get<0>(t)<<" - "<<get<1>(t)<<" ,"<<get<2>(t)<<endl;
	return 0;
}
