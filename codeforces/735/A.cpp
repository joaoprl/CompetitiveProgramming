// A. Ostap and Grasshopper

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;

  int p = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == 'G' || str[i] == 'T'){
      p = i;
      break;
    }
  }
  for(int i = p + k; i < str.size(); i += k){
    if(str[i] == '#')
      break;

    if(str[i] == 'T' || str[i] == 'G'){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}
