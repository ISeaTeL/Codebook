#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
#define MAX_V 1000
// Edge structure (Target, capacity, reverse edge)
struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];// adjacency list to store graph
int level[MAX_V];// distance to s
int iter[MAX_V];// iteration to where, those edge which is in front of the edge is useless

// Add an edge which is from 'from' to 'to' and its capacity is cap
void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size()-1});
}
// Get min dis to s by BFS
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int>que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}

	}
}
// Search and add path by DFS
int dfs(int v, int t, int f)
{
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
			if(e.cap>0&&level[v]<level[e.to]){
				int d=dfs(e.to, t, min(f, e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
	}
	return 0;	
}

// get max flow from s to t
int max_flow(int s, int t)
{
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while((f=dfs(s, t, INF))>0){
			flow+=f;
		}
	}
}
void init()
{
	int i;
	for(i=0;i<=N+1;i++){
		G[i].clear();
	}
	//memset(level, 0, sizeof(level));
}
