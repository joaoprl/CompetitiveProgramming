
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <unordered_set>

#define INF 1000000000

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
}

void dfs(vector< pair<int, int> > *edges, int v, int *dist, int d, int n){
  dist[v] = d;

  unordered_set<int> q;

  for(int i = 1; i <= n; i++)
    q.insert(i);

  while(!q.empty()){
    unordered_set<int>::iterator it, u;
    u = q.begin();
    for(it = q.begin(); it != q.end(); it++){
      if(dist[*it] < dist[*u])
        u = it;
    }

    for(int v = 0; v < edges[*u].size(); v++){
      if(dist[*u] + edges[*u][v].second < dist[edges[*u][v].first])
        dist[edges[*u][v].first] = dist[*u] + edges[*u][v].second;
    }

    q.erase(u);
  }
}

int main(){
  ios::sync_with_stdio(false);

  int n, m, k;
  double p;
  while(cin >> n >> m >> k >> p){
    int u, v;

    vector< pair<int, int> > *edges = new vector< pair<int, int> >[n + 1];
    for(int i = 0; i < m; i++){
      cin >> u >> v;

      edges[u].push_back(make_pair(v, 0));
      edges[v].push_back(make_pair(u, 0));
    }

    int a;
    cin >> a;
    int *av = new int[n + 1];
    for(int i = 0; i <= n; i++)
      av[i] = 0;
    for(int i = 0; i < a; i++){
      cin >> u;
      av[u]++;
    }

    for(int i = 0; i <= n; i++){
      for(int j = 0; j < edges[i].size(); j++){
        edges[i][j].second = av[edges[i][j].first];
      }
    }

    int *dist = new int[n + 1];
    for(int i = 0; i <= n; i++)
      dist[i] = INF;
    int sor, dest;
    cin >> sor >> dest;

    dfs(edges, sor, dist, av[sor], n);

    if(dist[dest] <= k)
      cout << fixed << setprecision(3) << pow(p, dist[dest]) << endl;
    else
      cout << "0.000" << endl;

  }

  return 0;
}
