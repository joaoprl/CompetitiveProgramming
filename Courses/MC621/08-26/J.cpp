// J. Ilya and Queries

#include <iostream>

using namespace std;

int main(){
  string s;

  cin >> s;
  
  int l, r, m, *d = new int [s.size() + 1];

  d[0] = 0;
  for(int l = 1; l <= s.size(); l++){
    d[l] = d[l - 1] + (s[l - 1] == s[l]);        
  }

  cin >> m;
  while(m--){
    cin >> l >> r;
    cout << d[r - 1] - d[l - 1] << "\n";
  }
  
  return 0;
}
