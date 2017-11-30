// SPFA

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
