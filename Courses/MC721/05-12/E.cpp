
#include <iostream>
#include <vector>

#define INF 1000000000
#define MOD 10000

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int l, u, r;

  int k = 1;
  while(cin >> l >> u >> r && (l != 0 || u != 0 || r != 0)){
    vector<int> rv;
    int num;
    for(int i = 0; i < r; i++){
      cin >> num;
      rv.push_back(num);
    }

    vector<int> v;
    int p = 0;
    v.push_back(l);

    int *dist = new int[MOD];
    for(int i = 0; i < MOD; i++)
      dist[i] = INF;
    dist[l] = 0;

    while(p < v.size()){
      l = v[p];
      p++;

      for(int i = 0; i < rv.size(); i++){
        if(dist[(rv[i] + l) % MOD] == INF){
          dist[(rv[i] + l) % MOD] = dist[l] + 1;
          v.push_back((rv[i] + l) % MOD);
        }
      }
    }

    cout << "Case " << k << ": ";
    if(dist[u] != INF)
       cout << dist[u] << endl;
    else
      cout << "Permanently Locked" << endl;
    k++;
  }

  return 0;
}
