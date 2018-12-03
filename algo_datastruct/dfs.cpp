#include <iostream> 
#include <vector> 
#include <queue>
#include <string> 
using namespace std;

class graph
{
	public:

		vector <int> vertex;
		vector <bool> visited;
		// 0 white 1 grey 2 black 
		vector <int> *adj;

		graph(int v)
		{
			adj = new vector<int>[v];
			visited.assign(v,false);
		}

		void add_edge(int a,int b)
		{
			adj[a].push_back(b);
		}

		void dfs(int v)
		{
			visited[v] = true;
			//vertex.push_back(v);
			for(auto x : adj[v])
			{
				if(visited[x] == false)
				{
					//visited[x] = true;
					dfs(x);
				}
			}
			//visited[v] = 2;
			vertex.push_back(v);
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

	for(int i=0;i<v;i++)
	{
		if(g.visited[i] == false)
			g.dfs(i);
	}

	for (auto x : g.vertex)
	{
		cout<<x<<"  ";
	}
	return 0;
	
}		