#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list<int>*adj;

public :
	Graph(int V);
	int is_intersecting(bool *s_visited,bool *t_visited);
	void add_edge(int u,int v);
	void print_path(int *s_parent,int *t_parent,int s,int t,int intersect_node);
	void bfs(list<int>*queue,bool *visited,int *parent);
	int bidir_search(int s,int t);
};


Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::add_edge(int u,int v)
{
	this->adj[u].push_back(v);
	this->adj[v].push_back(u);
}

void Graph::bfs(list<int> *queue,bool *visited,int *parent)
{
	int current=queue->front();
	queue->pop_front();
	list<int>::iterator i;
	for(i=adj[current].begin();i!=adj[current].end();i++)
	{
		if(!visited[*i])
		{
			parent[*i]=current;
			visited[*i]=true;
			queue->push_back(*i);
		}
	}
}

int Graph::is_intersecting(bool *s_visited,bool *t_visited)
{
	for(int i=0;i<V;i++)
		  if(s_visited[i]&&t_visited[i])
			  return i;
	return -1;
}

void Graph::print_path(int *s_parent,int *t_parent,int s,int t,int intersect_node)
{
	vector<int>path;
	path.push_back(intersect_node);
	int i=intersect_node;
	while(i!=s)
	{
		path.push_back(s_parent[i]);
		i=s_parent[i];
	}
	reverse(path.begin(),path.end());
	i=intersect_node;
	while(i!=t)
	{
		path.push_back(t_parent[i]);
		i=t_parent[i];
	}
	vector<int>::iterator it;
	cout<<"********path*******\n";
	for(it=path.begin();it!=path.end();++it)
		cout<<*it<<"  ";
	cout<<"\n";
}

int Graph::bidir_search(int s,int t)
{
	bool s_visited[V],t_visited[V];
	int s_parent[V],t_parent[V];
	list<int>s_queue,t_queue;
	int intersect_node=-1;
	for(int i=0;i<V;i++)
	{
		s_visited[i]=false;
		t_visited[i]=false;

	}
	s_queue.push_back(s);
	s_visited[s]=true;
	s_parent[s]=-1;
	t_queue.push_back(t);
	t_visited[s]=true;
	t_parent[s]=-1;

	while(!s_queue.empty()&&!t_queue.empty())
	{
		bfs(&s_queue,s_visited,s_parent);
		bfs(&t_queue,t_visited,t_parent);
		intersect_node=is_intersecting(s_visited,t_visited);
		if(intersect_node!=-1)
		{
			cout<<"path exist between"<<s<<" and "<<t<<"\n";
			cout<<"intersection at:"<<intersect_node<<"\n";

			print_path(s_parent,t_parent,s,t,intersect_node);
			exit(0);
		}
	}
	return -1;

}



int main()
{
	int n=15;
	int s=0;
	int t=14;
	Graph g(n);
	g.add_edge(0,4);
	g.add_edge(1,4);
	g.add_edge(2,5);
	g.add_edge(3,5);
	g.add_edge(4,6);
	g.add_edge(5,6);
	g.add_edge(6,7);
	g.add_edge(7,8);
	g.add_edge(8,9);
	g.add_edge(8,10);
	g.add_edge(9,11);
	g.add_edge(9,12);
	g.add_edge(10,13);
	g.add_edge(10,14);

	if(g.bidir_search(s,t)==-1)
		cout<<"path don't exist between "<<s <<"and "<< t<<"\n";
}
