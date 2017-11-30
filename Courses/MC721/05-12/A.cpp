
#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

class Edge{
public:
  int u, v, w;
  Edge(int u, int v, int t){
    this->u = u;
    this->v = v;
    this->w = t;
  }
};

bool bf(vector<int> vertices, vector<Edge> edges, int source){
  int *distance = new int[vertices.size()];

  vector<int>::iterator itV;
  vector<Edge>::iterator itE;
  for(itV = vertices.begin(); itV != vertices.end(); itV++)
    distance[*itV] = INF;

  distance[source] = 0;

  for(int i = 1; i + 1 <= vertices.size(); i++){
      for(itE = edges.begin(); itE != edges.end(); itE++){
        int u = itE-> u;
        int v = itE-> v;
        int w = itE-> w;
        if(distance[u] + w < distance[v]){
          distance[v] = distance[u] + w;
        }
      }
  }

  for(itE = edges.begin(); itE != edges.end(); itE++){
      int u = itE-> u;
      int v = itE-> v;
      int w = itE-> w;
      if(distance[u] + w < distance[v]){
        return true;
      }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);

  int c;
  cin >> c;
  while(c--){
    int n, m;
    cin >> n >> m;
    vector<int> vertices;
    vector<Edge> edges;
    for(int i = 0; i < n; i++)
      vertices.push_back(i);

    int u, v, t;
    for(int i = 0; i < m; i++){
      cin >> u >> v >> t;
      edges.push_back(Edge(u, v, t));
    }

    if(bf(vertices, edges, 0))
      cout << "possible" << endl;
    else
      cout << "not possible" << endl;

  }

  return 0;
}
