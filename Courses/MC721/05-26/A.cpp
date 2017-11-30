
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{
public:
  int u, v, w;
  Edge(int u, int v, int w){
    this->u = u;
    this->v = v;
    this->w = w;
  }
};

bool comp(Edge a, Edge b){
  return a.w < b.w;
}

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  while(cin >> n >> m && (n != 0 || m != 0)){
    vector<Edge> edges;
    bool *nodes = new bool[n];
    int u, v, w;

    for(int i = 0; i < n; i++)
      nodes[i] = false;

    for(int i = 0; i < m; i++){
      cin >> u >> v >> w;
      edges.push_back(Edge(u, v, w));
    }

    nodes[0] = true;
    bool cont = true;
    while(cont){
      for(int k = 0; k < n; k++){
        int pos = -1;
        for(int i = 0; i < m; i++){
          if((nodes[edges[i].u] == false && nodes[edges[i].v] == true) || (nodes[edges[i].u] == true && nodes[edges[i].v] == false)){
            if(pos == -1 || edges[i].w < edges[pos].w)
                pos = i;
          }
        }
        if(pos != -1){
          nodes[edges[pos].u] = nodes[edges[pos].v] = true;
          edges[pos].w = -1;
        }
        else{
          break;
        }
      }

      cont = false;
      for(int i = 0; i < n; i++){
        if(nodes[i] == false){
          nodes[i] = true;
          cont = true;
          break;
        }
      }
    }

    sort(edges.begin(), edges.end(), comp);

    int pos = 0;
    while(pos < n && edges[pos].w == -1)
      pos++;

    if(pos == m)
      cout << "forest" << endl;
    else{
      for(int i = 1; i < m; i++){
        if(edges[i].w != -1)
          cout << edges[i].w << " ";
      }
      cout << endl;
    }

  }

  return 0;
}
