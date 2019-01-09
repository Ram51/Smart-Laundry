/*#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <utility>
#include <climits>
#include "MapClass.cpp"
*/
using namespace std;
class Edge{
	int b,w;
	public:
		Edge()
		{
			;
		}
		Edge(int b,int w)
		{
			this->b=b;
			this->w=w;
		}
		int getB()
		{
			return b;
		}
		int getW()
		{
			return w;
		}
};

class Graph{
	private:
		int v;
		int e;
		vector<Edge> adj[100]; //maximum vertex may be 100
	public:
		/*create or load map*/
		int getV()
		{
			return v;
		}
		void createGraph(string s_city)
		{
			Map m;
			string temp=s_city;
			if(m.loadMetaData(temp))
			{
				v=m.getVertex();
				e=m.getEdges();
				temp=s_city+".edg";
				ifstream file(temp.c_str());
				for(int i=0;i<e;i++)
				{
					int a,b,w;
					file>>a;
					file>>b;
					file>>w;
					Edge temp_e(b,w);
					adj[a].push_back(temp_e);
					Edge t_e(a,w);
					adj[b].push_back(t_e);
				}
				file.close();
				cout<<"\tGraph Created!!!!!!"<<endl;
			}
		}
		void showGraph()
		{
			cout<<"Vertex : "<<v<<endl;
			cout<<"Edges : "<<2*e<<endl;
			cout<<endl<<"Adjacency List : "<<endl<<endl;
			for(int i=0;i<v;i++)
			{
				cout<<i<<"==>>";
				vector<Edge> :: iterator it;
				for(it=adj[i].begin();it!=adj[i].end();it++)
				{
					cout<<it->getB()<<"("<<it->getW()<<") ->";
				}
				cout<<endl;
			}
		}
		
		/*first load create graph then call this method*/
		
		void dijkstra(int source , vector<int> &dist)
		{
			set<pair<int,int> > heap;
			dist.assign(v,INT_MAX);
			dist[source]=0;
			
			heap.insert(make_pair<int,int>(0,source));
			
			while(!heap.empty())
			{
				pair<int,int> temp_pair = *(heap.begin());
				heap.erase(heap.begin());
				int a=temp_pair.second;
				
				int size=adj[a].size();
				for(int i=0;i<size;i++)
				{
					int b=adj[a][i].getB();
					int w=adj[a][i].getW();
					
					if(dist[b] > dist[a]+w)
					{
						if(dist[b]!=INT_MAX)
							heap.erase(heap.find(make_pair<int,int>(dist[b],b)));
						dist[b]=dist[a]+w;
						heap.insert(make_pair<int,int>(dist[b],b));
					}
				}
			}
			/*for(int i=0;i<v;i++)
			{
				cout<<i<<" : "<<dist[i]<<endl;
			}*/
		}
};
/*
int main()
{
	Graph g;
	g.createGraph("Indore");
	vector<int> dist;
	g.dijkstra(0,dist);
//	g.showGraph();
}
*/	
