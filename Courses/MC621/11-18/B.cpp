
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void dfsDel(set<int> *edges, int u, int &n, const int &b, const int &a, vector<bool> &active){
  if(active[u] && ((int)edges[u].size() > n - b - 1 || edges[u].size() < a)){
    active[u] = false;

    for(set<int>::iterator it = edges[u].begin(); it != edges[u].end(); it++)
      edges[*it].erase(u);

    n--;

    for(set<int>::iterator it = edges[u].begin(); it != edges[u].end(); it++)
      dfsDel(edges, *it, n, b, a, active);

    edges[u].clear();
  }
}

int main(){
  ios::sync_with_stdio(false);

  int n, m, a, b;
  cin >> n >> m >> a >> b;
  set<int> *edges = new set<int>[n + 1];

  int x, y;
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    edges[x].insert(y);
    edges[y].insert(x);
  }
  int k = n;

  vector<bool> active(n + 1, true);
  for(int j = 0; j < 2; j++){
    for(int i = 1; i <= n; i++){
      dfsDel(edges, i, k, b, a, active);
    }
  }

  cout << k << endl;

  return 0;
}
