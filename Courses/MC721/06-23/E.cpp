
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, p, out;

  while(cin >> n && n != 0){
    out = 0;
    for(int i = 0; i < n; i++){
      cin >> p;
      out = out xor p;
    }
    if(out != 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
