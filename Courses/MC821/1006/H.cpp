
#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  string s1, s2;
  int n;
  cin >> s1 >> n;

  vector<string> v;

  for(int i = 0; i < n; i++){
    cin >> s2;
    v.push_back(s2);
  }

  bool pos = false;
  for(int i = 0; i < n; i++){
    if(s1 == v[i])
      pos = true;
    for(int j = 0; j < n; j++){
      string st = v[i] + v[j];
      if(s1[0] == st[1] && s1[1] == st[2])
        pos = true;
    }
  }

  if(pos)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
