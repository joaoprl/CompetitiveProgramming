// C. Hongcow Builds A Nation

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int> *edges, int v, int &nEdges, int &nNodes, bool *visited){
  if(visited[v])
    return 0;

  visited[v] = true;

  for(int i = 0; i < edges[v].size(); i++){
    dfs(edges, edges[v][i], nEdges, nNodes, visited);
  }
  nNodes++;
  nEdges += edges[v].size();
}

int main(){
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> ks;
  int num;
  for(int i = 0; i < k; i++){
    cin >> num;
    ks.push_back(num);
  }

  int u, v;
  vector<int> *edges = new vector<int>[n + 1];
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector< pair<int, int> > comp;
  int nEdges, nNodes;

  bool *visited = new bool[n + 1];
  int maxNodes = -1, maxPos = -1;
  for(int i = 0; i <= n; i++)
    visited[i] = false;
  for(int i = 0; i < k; i++){
    nEdges = 0;
    nNodes = 0;
    dfs(edges, ks[i], nEdges, nNodes, visited);
    nEdges /= 2;

    comp.push_back(make_pair(nNodes, nEdges));

    if(nNodes > maxNodes){
      maxNodes = nNodes;
      maxPos = i;
    }
  }

  int count = 0;
  nNodes = 0;
  nEdges = 0;
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      dfs(edges, i, nEdges, nNodes, visited);
    }
  }
  nEdges /= 2;

  comp[maxPos].first += nNodes;
  comp[maxPos].second += nEdges;

  int newEdges = 0;

  for(int i = 0; i < k; i++){
    newEdges += comp[i].first * (comp[i].first - 1) / 2 - comp[i].second;
  }

  cout << newEdges << endl;

  return 0;
}
