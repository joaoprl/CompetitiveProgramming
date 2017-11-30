
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100100
#define MAXLOG 20
#define INF 1000000000

using namespace std;


pair<int, int> par[MAXN][MAXLOG]; // initially all -1
int h[MAXN];
vector< pair<int, int> > adj2[MAXN];
vector< pair<int, int> > adj[MAXN];

void dfs(int v,int p = -1, int w = INF){
	par[v][0].first = p;
  par[v][0].second = w;

	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1].first + 1)
			par[v][i] = {par[par[v][i-1].first][i-1].first, min(par[v][i - 1].second, par[par[v][i - 1].first][i-1].second)};
	for(auto u : adj[v])	if(p - u.second)
		dfs(u.second, v, u.first);
}

pair<int, int> LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
  int ma = INF;
  for(int i = MAXLOG - 1;i >= 0; i--)
		if(par[v][i].first + 1 and h[par[v][i].first] >= h[u]){
      ma = min(ma, par[v][i].second);
			v = par[v][i].first;
    }
	// now h[v] = h[u]
	if(v == u)
		return {v, ma};
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i].first - par[u][i].first){
      ma = min(ma, par[v][i].second);
      ma = min(ma, par[u][i].second);
      v = par[v][i].first, u = par[u][i].first;
    }
  ma = min(ma, par[v][0].second);
  ma = min(ma, par[u][0].second);
	return {par[v][0].first, ma};
}

int main(){
  ios::sync_with_stdio(false);

  int n, m, s;
  while(cin >> n >> m >> s ){
    for(int i = 0; i < MAXN; i++){
      for(int j = 0; j < MAXLOG; j++)
        par[i][j] = {-1, INF};
      adj[i].clear();
      adj2[i].clear();
    }

    int u, l, v;
    for(int i = 0; i < m; i++){
      cin >> v >> u >> l;
      adj2[u].push_back({l, v});
      adj2[v].push_back({l, u});
    }

    vector<bool> visited(n + 1, false);
    vector< pair<int, pair<int, int> > > heap;
    make_heap(heap.begin(), heap.end());

    for(int i = 0; i < adj2[1].size(); i++){
      heap.push_back({adj2[1][i].first, {1, adj2[1][i].second} });
      push_heap(heap.begin(), heap.end());
    }
    visited[1] = true;

    while(heap.size() != 0){
      pair<int, pair<int,int> > min = heap.front();
      pop_heap(heap.begin(), heap.end());
      heap.pop_back();

      if(!visited[min.second.second]){
        visited[min.second.second] = true;

        adj[min.second.first].push_back({min.first, min.second.second});
        adj[min.second.second].push_back({min.first, min.second.first});

        for(int i = 0; i < adj2[min.second.second].size(); i++){
          heap.push_back({adj2[min.second.second][i].first, {min.second.second, adj2[min.second.second][i].second}});
          push_heap(heap.begin(), heap.end());
        }
      }
    }
    dfs(1);

    for(int i = 0; i < s; i++){
      cin >> u >> v;
      cout << LCA(u, v).second << endl;
    }
  }

  return 0;
}
