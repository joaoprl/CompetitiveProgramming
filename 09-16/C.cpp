// C. Admiral

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


class Edge {
  public:
    int u, v, p;
    Edge(int, int, int);
};

Edge::Edge(int a, int b, int prob){
  u = a;
  v = b;
  p = prob;
}

// https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm#Algorithm
void bellmanFord(vector<Edge> edges, int source, double *dist, int n){
  for(int i = 0; i <= n; i++)
    dist[i] = 0;

  dist[source] = 0;
  int u, v, p;
  for(int i = 1; i <= n - 1; i++){
    for(int j = 0; j < edges.size(); j++){
      u = edges[j].u;
      v = edges[j].v;
      p = edges[j].p;

      if(dist[u] + p < dist[v]){
        dist[v] = dist[u] + p;
      }
      else if(dist[v] + p > dist[u]){
        dist[u] = dist[v] + p;
      }
    }
  }
}

int main(){
  int n, m, a, b, p;

  cin >> n;

  vector<Edge> edges;
  double *dist = new double[N];

  while(n){
    cin >> m;

    edges.clear();
    for(int i = 0; i < m; i++){
      cin >> a >> b >> p;
      edges.push_back(Edge(a, b, p));
    }

    bellmanFord(edges, 1, dist, n);
    printf("%.6lf percent\n", dist[n]);

    cin >> n;
  }
  return 0;
}
