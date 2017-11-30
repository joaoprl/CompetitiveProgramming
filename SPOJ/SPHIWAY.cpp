
#include <iostream>
#include <queue>

#define INF ((long long)1e18)
#define INF2 2000000001

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void SPFA(vector<pii> *edges, vector<ll> &d, vector<bool> &vs, vector<int> &par, int v, int n){
  d.assign(n + 1, INF);
  d[v] = 0;
  queue<int> q;
  q.push(v);

  par.assign(n + 1, - 1);

  vs.assign(n + 1, false);
  vs[v] = true;
  par[v] = -1;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    vs[u] = false;

    for(pii p : edges[u]){
      int i = p.first;
      ll w = p.second;

      if(d[i] > d[u] + w && w != INF2){
        d[i] = d[u] + w;
        par[i] = u;
        if(!vs[i]){
          q.push(i);
          vs[i] = true;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  int u, v, c;
  vector<pii> *edges1 = new vector<pii>[n + 1];
  vector<pii> *edges2 = new vector<pii>[n + 1];
  vector<ll> dist;
  vector<bool> vs;
  vector<int> par;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> c;

    edges1[u].push_back({v, c});
    edges1[v].push_back({u, c});
  }
  SPFA(edges1, dist, vs, par, s, n);
  ll d1 = dist[t];

  vs.assign(n + 1, false);
  for(u = t; u != -1; u = par[u])
    vs[u] = true;

  for(u = 0; u <= n; u++){
    for(pii p : edges1[u]){
      v = p.first;
      c = p.second;

      if(vs[u] && vs[v]){
        if(par[v] == u)
          edges2[u].push_back({v, INF2});
        else if(par[u] == v)
          edges2[u].push_back({v, -c});
        else
          edges2[u].push_back({v, c});
      }
      else
        edges2[u].push_back({v, c});
    }
  }

  SPFA(edges2, dist, vs, par, s, n);
  ll d2 = dist[t];

  if(d2 == INF)
    cout << -1 << endl;
  else
    cout << d1 + d2 << endl;


  return 0;
}
