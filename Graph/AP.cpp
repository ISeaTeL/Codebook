#define MAXN 10001

vector<int> v[MAXN]; //adjacency list
bool rec[MAXN];
int clk[MAXN], low[MAXN], time, ct; //ct: the # of AP

void dfs(int x, int parent){
	rec[x] = 1;
	clk[x] = low[x] = ++time;
	int child = 0;
	bool ap = 0;
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		if(y != p){
			if(!rec[y]){
				child++;
				dfs(y, x);
				low[x] = low[x] < low[y] ? low[x] : low[y];
				if(low[y] >= clk[x])
					ap = 1;
			}
			else
				low[x] = low[x] < clk[y] ? low[x] : clk[y];
		}
	}
	if(x == parent && child > 1 || x != parent && ap)
		ct++; //x-th pt is an AP
}
