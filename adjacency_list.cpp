// adjacency list
//
// An adjacency list is a collection of unordered lists used to represent a
// finite graph.each list describe the set of neighbors of vertex in the graph


// vector are same as dynmic arrays with the ablily to resize it self automatically
// when an element is inserted or deleted with their  storage handled automatically
// by the container
//
//  vector::emplace_back()
//       thsi function is used to insert a new element into the vector container the new element is added to the end of the vector
//
//
//       syntax
//             vector_name.emplace_back(value)
//              
//               parameter :
//                    the element to be inserted into the vector is passed as the parameter
//                result:
//                    the parameter is added to the end of the position




#include<iostream>
#include<vector>

using namespace std;

#define V 5

void addedge(vector<int>graph[],int u,int v)
{
	graph[u].emplace_back(v);
}
int main()
{
	vector<int>graph[V];

	addedge(graph,0,1);
	addedge(graph,0,4);
	addedge(graph,1,1);
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,1,4);
	addedge(graph,3,2);
	addedge(graph,3,4);
	cout<<"adjacency list :"<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<i;
		for(int j=0;j<graph[i].size();j++)
			cout<<" -> "<<graph[i][j];
		cout<<endl;
	}
	return 0;
}
