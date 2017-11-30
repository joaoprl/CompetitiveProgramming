// C. The Bottom of a Graph

#include <cstdio>
#include <vector>
#include <list>

#define V 5001

using namespace std;

void visit(int u, bool *visited, list<int> &l, vector<int> *edges){
  if(visited[u] == false){
    visited[u] = true;
    for(int i = 0; i < edges[u].size(); i++)
      visit(edges[u][i], visited, l, edges);
    l.push_front(u);
  }
}

void assign(int u, int root, vector<int> *edgesT, int *assigned){
  if(assigned[u] == -1){
    assigned[u] = root;
    for(int v = 0; v < edgesT[u].size(); v++)
      assign(edgesT[u][v], root, edgesT, assigned);
  }
}

void kosaraju(vector<int> *edges, vector<int> *edgesT, int *assigned, int n){
  bool *visited = new bool[n + 1];
  for(int u = 1; u <= n; u++)
    visited[u] = false;
  list<int> l;

  for(int u = 1; u <= n; u++)
    visit(u, visited, l, edges);

  for(list<int>::iterator u = l.begin(); u != l.end(); u++){
    assign(*u, *u, edgesT, assigned);
  }
  delete[] visited;
}

int main(){
  int v, e, u, w;

  vector<int> *edges = new vector<int>[V];
  vector<int> *edgesT = new vector<int>[V];

  vector<int> bottom;
  bool isSink;

  int *assigned = new int[V];
  int *root = new int[V];

  while(true){
    scanf("%d", &v);
    if(v == 0)
      break;

    scanf("%d", &e);

    for(int i = 1; i <= v; i++){
      edges[i].clear();
      edgesT[i].clear();
      assigned[i] = -1;
      root[i] = 0;
    }
    for(int i = 1; i <= e; i++){
      scanf("%d %d", &u, &w);
      edges[u].push_back(w);
      edgesT[w].push_back(u);
    }

    kosaraju(edges, edgesT, assigned, v);

    for(int u = 1; u <= v; u++){
      for(int w = 0; w < edges[u].size(); w++){
        if(assigned[edges[u][w]] != assigned[u])
          root[assigned[u]] = -1;
      }
    }

    bottom.clear();
    for(int u = 1; u <= v; u++){
      if(root[assigned[u]] == 0)
        bottom.push_back(u);
    }

    for(int u = 0; u < bottom.size() - 1; u++)
      printf("%d ", bottom[u]);
    if(bottom.size() > 0)
      printf("%d\n", bottom.back());
    else
      printf("\n");

  }

  delete[] edges, edgesT, assigned;

  return 0;
}
