#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using std::vector;
using std::fill;
using std::numeric_limits;
using std::cout;
void bellman_ford(vector<vector<int>>graph)
{
	int v=graph.size();
	vector<int>dist(v);
	fill(dist.begin(),dist.end(),numeric_limits<int>::max());
	dist[0]=0;
	for(int c=0;c<v-1;c++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(graph[i][j]&&dist[i]!=numeric_limits<int>::max()&&dist[i]+graph[i][j]<dist[j])
					dist[j]=dist[i]+graph[i][j];
			}

		}
	}

	cout<<"vertex distance \n";
	for(int i=0;i<v;i++)
		cout<<i<<"\t\t"<<dist[i]<<"\n";


}
int main()
{
	vector<vector<int>>graph={
		{0,8,0,0,0,10},
		{0,0,1,0,0,0},
		{0,0,0,-1,0,-3},
		{0,0,0,0,-2,0},
		{0,0,0,0,0,1},
		{0,0,0,1,0,0}
	};

	bellman_ford(graph);
	return 0;
}

