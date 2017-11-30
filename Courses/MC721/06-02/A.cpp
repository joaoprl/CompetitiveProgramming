
#include <iostream>
#include <vector>
#include <set>

#define R 10010
#define UNVISITED -1

using namespace std;

vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;
vector<bool> articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
set< pair<int, int> > articulation_edges;

void articulationPoint(vector< pair<int, int>> * edges, int u){
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(int j = 0; j < edges[u].size(); j++){
    pair<int, int> v = edges[u][j];
    if(dfs_num[v.first] == UNVISITED){
      dfs_parent[v.first] = u;

      if(u == dfsRoot) rootChildren++;
      articulationPoint(edges, v.first);

      if(dfs_num[u] < dfs_low[v.first]){
        articulation_vertex[u] = true;
        articulation_edges.insert(make_pair(min(u, v.first), max(u, v.first)));
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }
    else if(v.first != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
  }
}

void dfs(vector<int> *edges, int u, int *p, bool *cl, int par){
  if(cl[u])
    return;

  cl[u] = true;
  p[u] = par;

  for(int i = 0; i < edges[u].size(); i++)
    dfs(edges, edges[u][i], p, cl, par);
}

int main(){
  ios::sync_with_stdio(false);

  vector< pair<int, int> > *edges = new vector< pair<int, int> >[R];
  vector<int> *edges2 = new vector<int>[R];
  int * p = new int[R];
  bool *cl = new bool[R];

  int r, c, q;
  int u, v;
  while(cin >> r >> c >> q && (r != 0 || c != 0 || q != 0)){

    for(int i = 0; i < r; i++){
      edges[i].clear();
      edges2[i].clear();
      p[i] = i;
      cl[i] = false;
    }

    for(int i = 0; i < c; i++){
      cin >> u >> v;
      u--;
      v--;

      edges[u].push_back(make_pair(v, 0));
      edges[v].push_back(make_pair(u, 0));
    }

    dfsNumberCounter = 0;
    dfs_num.clear(); dfs_num.assign(r, UNVISITED);
    dfs_low.clear(); dfs_low.assign(r, 0);
    dfs_parent.clear(); dfs_parent.assign(r, -1);
    articulation_vertex.clear(); articulation_vertex.assign(r, false);
    articulation_edges.clear();

    for(int i = 0; i < r; i++){
      if(dfs_num[i] == UNVISITED){
        dfsRoot = i; rootChildren = 0;
        articulationPoint(edges, i);
        articulation_vertex[dfsRoot] = (rootChildren > 1);
      }
    }

    for(set<pair<int, int> >::iterator it = articulation_edges.begin(); it != articulation_edges.end(); it++){
      edges2[it->first].push_back(it->second);
      edges2[it->second].push_back(it->first);
    }

    for(int i = 0; i < r; i++){
      if(!cl[i])
        dfs(edges2, i, p, cl, i);
    }


    for(int i = 0; i < q; i++){
      cin >> u >> v;
      u--; v--;

      if(p[u] == p[v])
        cout << "Y\n";
      else
        cout << "N\n";

    }
    cout << "-\n";

  }

  return 0;
}
