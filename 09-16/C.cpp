// C. Admiral

#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

#define V 1001
#define E 100000

using namespace std;

class Edge {
  public:
    int u, v, w;
    Edge(int, int, int);
};

Edge::Edge(int a, int b, int weight){
  u = a;
  v = b;
  w = weight;
}

// https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm#Algorithm
void bellmanFord(vector<Edge> *edges, int source, int *dist, int n, int *pred, int *valid){
  for(int i = 0; i <= n; i++){
    dist[i] = INT_MAX;
    pred[i] = 0;
  }

  dist[source] = 0;
  int u, v, w;
  for(int i = 1; i <= n - 1; i++){
    for(int j = 1; j <= n; j++){
      for(int k = 0; k < edges[j].size(); k++){
        u = edges[j][k].u;
        v = edges[j][k].v;
        w = edges[j][k].w;

        if((valid[u] == true || (valid[u] == false && valid[pred[u]] == false)
          || (valid[u] == false && valid[v] == false)) &&
          v != 0 && dist[u] != INT_MAX && dist[u] + w < dist[v]){
          dist[v] = dist[u] + w;
          pred[v] = u;
        }

        if(valid[u] == false && valid[v] == false && dist[u] != INT_MAX && false){
          for(int l = 0; l < edges[v].size(); l++){
            if(dist[u] + w + edges[v][l].w < dist[l]){
              dist[l] = dist[u] + w + edges[v][l].w;
              pred[l] = v;
              pred[v] = u;
            }
          }
        }
      }
    }
  }
}

int main(){
  int v, e, a, b, c, cballs;

  vector<Edge> *edges = new vector<Edge>[V];
  int *dist = new int[V];
  int *pred = new int[V];
  int *valid = new int[V];

  while(cin >> v >> e){
    cballs = 0;

    for(int i = 0; i <= v; i++){
      edges[i].clear();
      valid[i] = true;
    }

    for(int i = 0; i < e; i++){
      cin >> a >> b >> c;
      edges[a].push_back(Edge(a, b, c));
    }

    bellmanFord(edges, 1, dist, v, pred, valid);
    cballs = dist[v];

    c = v;
    while(c != 1){
      for(int i = 0; i < edges[pred[c]].size(); i++){
        if(edges[pred[c]][i].v == c)
          edges[pred[c]][i].v = 0;
      }
      valid[c] = false;
      edges[c].push_back(Edge(c, pred[c], dist[pred[c]] - dist[c]));
      c = pred[c];
    }
    valid[v] = true;
    for(int i = 1; i <= v; i++)
      cout << valid[i] << " ";
      cout << endl;

    for(int i = 1; i <= v; i++)
      cout << pred[i] << " ";

    bellmanFord(edges, 1, dist, v, pred, valid);
    cout << endl;
    for(int i = 1; i <= v; i++)
      cout << pred[i] << " ";
      cout << endl;
    for(int i = 1; i <= v; i++)
      cout << dist[i] << " ";



    cballs += dist[v];
    cout << cballs << "\n";

  }

  delete[] edges, dist, pred;

  return 0;
}
