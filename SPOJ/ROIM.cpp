
#include <iostream>
#include <queue>

#define int long long

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e18;
const int M = 1e8;

void SPFA(vector<pii> *edges, vector<int> &d, vector<bool> &vs, vector<int> &par, int v, int n){
  d.assign(n, INF);
  d[v] = 0;

  queue<int> q;
  q.push(v);

  par.assign(n, -1);

  vs.assign(n, false);
  vs[v] = true;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    vs[u] = false;

    for(pii p : edges[u]){
      int i = p.first;
      int w = p.second;

      if(d[i] > d[u] + w){
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

int32_t main(){
  ios::sync_with_stdio(false);
  int n, R, C, s, t;
  while(cin >> n >> R >> C && (n != 0 || R != 0 || C != 0)){
    s = 0;
    t = n - 1;

    int u, v, c;
    vector<pii> *edges1 = new vector<pii>[n];
    vector<pii> *edges2 = new vector<pii>[n];
    vector<int> dist;
    vector<bool> vs;
    vector<int> par;

    for(int i = 0; i < R; i++){
      cin >> u >> v >> c;

      edges1[u].push_back({v, c});
    }

    for(int i = 0; i < C; i++){
      cin >> u >> v >> c;

      edges1[u].push_back({v, c * M});
    }
    SPFA(edges1, dist, vs, par, s, n);
    int d1 = dist[t];
    int count = 0;

    vs.assign(n, false);
    for(u = t; u != -1; u = par[u])
      vs[u] = true;

    for(u = 0; u < n; u++){
      for(pii p : edges1[u]){
        v = p.first;
        c = p.second;

        if(vs[u] && vs[v] && par[v] == u){
          edges2[v].push_back({u, -c});
          if(c > M)
            count++;
        }
        else
          edges2[u].push_back({v, c});
      }
    }

    SPFA(edges2, dist, vs, par, s, n);
    int d2 = dist[t];

    vs.assign(n, false);
    for(u = t; u != -1; u = par[u])
      vs[u] = true;

    for(u = 0; u < n; u++){
      for(pii p : edges1[u]){
        v = p.first;
        c = p.second;

        if(vs[u] && vs[v] && par[v] == u){
          if(c > M)
            count++;
          else if(c < -M)
            count--;
        }
      }
    }

    if(d1 == INF || d2 == INF)
      cout << "Boa viagem, Roim" << endl;
    else
      cout << count << " " << (d1 + d2) % M + (d1 + d2) / M << endl;

    delete[] edges1;
    delete[] edges2;
  }

  return 0;
}
