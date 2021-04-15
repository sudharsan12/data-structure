#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
void graphcoloring(vector<int>graph[],int V)
{
	vector<int>color(V,-1);
	color[0]=1;
	vector<bool>alreadyassigned(V);
	for(int u=1;u<V;u++)
	{
		for(auto av:graph[u])
			if(color[av]!=-1)
				alreadyassigned[color[av]]=true;
		int c;
		for(c=1;c<=V;c++)
			if(alreadyassigned[c]==false)
				break;
		color[u]=c;
	}
	for(int u=0;u<V;u++)
		cout<<"Vetex"<<u<<"---->color"<<color[u]<<endl;
	cout<<"number of color required: "<<*max_element(color.begin(),color.end())<<endl;
}

void add_edge(vector<int>graph[],int u,int v)
{
	graph[u].emplace_back(v);
	graph[v].emplace_back(u);

}

int main()
{
	int V=10;
	vector<int>graph[V];

	add_edge(graph,0,1);
	add_edge(graph,0,4);
	add_edge(graph,0,5);
	add_edge(graph,1,2);
	add_edge(graph,1,6);
	add_edge(graph,2,3);
	add_edge(graph,2,8);
	add_edge(graph,5,9);
	add_edge(graph,3,4);
	add_edge(graph,3,9);
	add_edge(graph,4,7);
	add_edge(graph,5,8);
	add_edge(graph,5,9);
	add_edge(graph,6,7);
	add_edge(graph,6,9);
	add_edge(graph,7,8);

	graphcoloring(graph,V);
	cout<<endl;
}
