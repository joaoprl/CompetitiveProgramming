
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n){
    int t;
    char c;
    vector<int> d, e;
    for(int i = 0; i < n; i++){
      cin >> t >> c;
      if(c == 'E')
        e.push_back(t);
      else
        d.push_back(t);
    }
    sort(d.begin(), d.end());
    sort(e.begin(), e.end());

    int dP = 0, eP = 0, count = 0;
    while(dP < d.size() && eP < e.size()){
      if(d[dP] == e[eP]){
        count++;
        dP++;
        eP++;
      }
      else if(d[dP] > e[eP]){
        eP++;
      }
      else{
        dP++;
      }
    }
    cout << count << endl;
  }

  return 0;
}
