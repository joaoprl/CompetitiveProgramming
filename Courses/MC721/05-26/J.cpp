

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;
int main(){
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for(int k = 0; k < t; k++){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > *edges = new vector<pair<int, int> >[n + 1];
    int u, v, w;
    int totalValue = 0;
    for(int i = 0; i < m; i++){
      cin >> u >> v >> w;
      totalValue += w;
      edges[u].push_back(make_pair(w, v));
      edges[v].push_back(make_pair(w, u));
    }

    bool *chosen = new bool[n + 1];
    for(int i = 0; i < n + 1; i++)
      chosen[i] = false;

    chosen[1] = true;
    vector<pair<int, int> > minDist;

    for(int i = 0; i < edges[1].size(); i++){
      minDist.push_back(edges[1][i]);
      push_heap(minDist.begin(), minDist.end());
    }

    int totalCost = 0;
    while(!minDist.empty()){
      pop_heap(minDist.begin(), minDist.end());
      pair<int, int> e = minDist.back();
      minDist.pop_back();

      if(!chosen[e.second]){
        chosen[e.second] = true;
        totalCost += e.first;
        for(int i = 0; i < edges[e.second].size(); i++){
          minDist.push_back(edges[e.second][i]);
          push_heap(minDist.begin(), minDist.end());
        }
      }
    }
    cout << totalValue - totalCost << endl;
  }
  cin >> t;
  return 0;
}
