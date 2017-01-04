// B. Decoding

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  string s, out = "";
  cin >> n >> s;

  if(n % 2 == 1){
    for(int i = 0; i < n; i++){
      if(i % 2 == 0)
        out = out + s[i];
      else
        out = s[i] + out;
    }
  }
  else{
    for(int i = 0; i < n; i++){
      if(i % 2 == 0)
      out = s[i] + out;
      else
        out = out + s[i];
    }
  }


  cout << out << endl;

  return 0;
}
