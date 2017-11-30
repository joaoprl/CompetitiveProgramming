
#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int c, p, u, v;
  while(cin >> c >> p){
    vector<int> *par = new vector<int>[c + 1];
    for(int i = 0; i < p; i++){
      cin >> u >> v;
      par[v].push_back(u);
    }
    int st = 1;
    vector<int> sts(c + 1, 0);
    for(int i = 2; i <= c; i++){
      sts[i] = sts[par[i].front()];
      for(int j = 0; j < par[i].size(); j++){
        if(sts[par[i][j]] != sts[par[i][0]] || par[i][j] == 1){
          sts[i] = st++;
          break;
        }
      }
    }

    int count = 0;
    for(int i = 1; i <= c; i++)
      for(int j = i + 1; j <= c; j++)
        if(sts[i] != sts[j])
          count++;

    cout << count << endl;
  }
  return 0;
}
