
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  while(q--){
    int u;
    string s;
    cin >> u >> s;

    for(int i = 0; i < s.length(); i++){
      if(s[i] == 'L'){
        if(u % 2 == 0)
          u--;
      }
      else if(s[i] == 'R'){

      }
      else if(s[i] == 'U')

    }

    cout << u << endl;
  }

  return 0;
}
