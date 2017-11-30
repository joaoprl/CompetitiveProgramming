
#include <iostream>

using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  ll a, b, out;
  cin >> a >> b;
  if(b - a >= 10)
    cout << 0 << endl;
  else{
    out = 1;
    for(a += 1; a <= b; a++){
      out *= a;
      out %= 10;
    }
    cout << out << endl;
  }


  return 0;
}
