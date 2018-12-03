//breadth first search
//given Vertex list V and an adjacency list for every vertex in V we represent a Graph G
//if edge from a to b exists then adj(a) has b

//maintain a queue to finish in that order

//adjacency list runs in timeO(V+E) space (V + E)
//adjacency matrix(V+E) space (V^2 )
#include <iostream> 
#include <vector> 
#include <queue>
#include <string> 
using namespace std;

class graph
{
public:
	//vector<vector<int>> vertex;
	vector <int> vertex;
	vector <bool> visited; 
	vector <int> *adj;
	queue <int> q;

	vector<vector<bool>> vertices;

	// vertices.at(i).at(j)
	// [i][j]
	graph(int v)
	{
		adj = new vector<int>[v];
		visited.assign(v,false);
	}

	void add_edge(int a,int b)
	{
		adj[a].push_back(b);
	}

	void bfs (int v)
	{
		visited[v] = true;
		q.push(v);
		
		while(!q.empty())
		{
			v = q.front();
			q.pop();
			vertex.push_back(v);
			
			for(auto x : adj[v])
			{
				if(!visited[x])
				{
					q.push(x);
					visited[x] = true;
				}

			}
		
		}

	}
};

int main()
{
	int v,a,b,e;
	cout<<"enter number of vertices";
	cin>>v;
	graph g(v);
	cout<<"enter number of edges";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"enter directed edge beg to end vertex";
		cin>>a>>b;
		g.add_edge(a,b);
	}
	cout<<"bfs from which vertex";
	cin>>v;
	g.bfs(v);

	cout<<"order is\n";
	for(auto x : g.vertex)
	{
		cout<<x<<"  ";
	}
	return 0;
}

 
  

