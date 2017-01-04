// G. New Roads

#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, t, k;
  cin >> n >> t >> k;

  int *ks = new int[t];
  int maxL = 0;
  for(int i = 0; i < t; i++){
    cin >> ks[i];
    maxL += ks[i] - 1;
  }

  int minL = 0;
  for(int i = 0; i < t - 1; i++){
    if(ks[i] > ks[i + 1]){
      minL += ks[i] - ks[i + 1];
    }
  }
  minL += ks[t - 1];

  if(k < minL || k > maxL){
    cout << "-1\n";
    return 0;
  }

  maxL += t - 1;
  vector<int> *edges = new vector<int>[n + 1];
  vector<int> last;
  for(int i = 0; i < ks[0]; i++){
    edges[1].push_back(i + 2);
    last.push_back(i + 2);
  }

  int node = ks[0] + 2;
  for(int i = 1; i < t; i++){
    vector<int> last1;
    int put = 0;
    for(int j = 0; j < last.size(); j++){
      if(maxL > k){
        edges[last[j]].push_back(node);
        node++;
        maxL--;
        last1.push_back(node);
      }else{
        break;
      }
      put++;

      if(put == ks[i])
        break;
    }
    for(int j = 0; j < ks[i] - put; j++){
      edges[last[0]].push_back(node);
      last1.push_back(node);
      node++;
    }
    last = last1;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < edges[i].size(); j++)
      cout << i << " " << edges[i][j] << endl;
  }

  return 0;
}
