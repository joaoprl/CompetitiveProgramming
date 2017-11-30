
// I. Odd Factor

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> *edges, int u, vector<bool> &visited, vector< pair<int, int> > &output){
  if(visited[u])
    return false;

  visited[u] = true;

  int count = 0;
  for(int i = 0; i < edges[u].size(); i++){
    if(dfs(edges, edges[u][i], visited, output)){
      count++;
      output.push_back({ u, edges[u][i] } );
    }
  }

  return count % 2 == 0;
}

int main(){
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<int> *edges = new vector<int>[n + 1];
  int u, v;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  bool flag = true;
  vector<bool> visited(n + 1, false);
  vector< pair<int, int> > output;
  for(int i = 1; i <= n; i++){
    if(dfs(edges, i, visited, output))
      flag = false;
  }

  if(flag){
    cout << output.size() << endl;
    for(int i = 0; i < output.size(); i++)
      cout << output[i].first << " " << output[i].second << endl;
  }
  else
    cout << -1 << endl;


  return 0;
}
