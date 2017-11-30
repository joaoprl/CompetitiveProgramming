
#include <iostream>
#include <vector>

#define MAXN 100100
#define MAXLOG 20
#define int long long

using namespace std;


int par[MAXN][MAXLOG]; // initially all -1
int h[MAXN];
vector< pair<int, int> > adj[MAXN];

void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v])	if(p - u.first)
		dfs(u.first, v);
}

void dfs2(vector<int> &dists, int d, int u){
  if(dists[u] != -1)
    return;
  dists[u] = d;

  for(int i = 0; i < adj[u].size(); i++)
    dfs2(dists, d + adj[u][i].second, adj[u][i].first);
}

int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int32_t main(){
  ios::sync_with_stdio(false);

  int n;
  while(cin >> n && n != 0){
    for(int i = 0; i < MAXN; i++){
      for(int j = 0; j < MAXLOG; j++)
        par[i][j] = -1;
      adj[i].clear();
    }

    int u, l, v;
    for(int i = 1; i < n; i++){
      cin >> u >> l;
      adj[i].push_back({u, l});
      adj[u].push_back({i, l});
    }
    vector<int> dists(n + 1, -1);

    dfs2(dists, 0, 0);
    dfs(0);

    int q, a;
    cin >> q;
    for(int i = 0; i < q; i++){
      cin >> u >> v;
      a = LCA(u, v);
      cout << (i != 0 ? " " : "") << dists[u] + dists[v] - 2 * dists[a];
    }
    cout << endl;
  }

  return 0;
}
