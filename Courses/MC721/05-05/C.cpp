
#include <iostream>
#include <vector>

using namespace std;

int powMod(int v, int e, int m){
  if(e == 0)
    return 1;
  if(e == 1)
    return v;

  return (powMod(v, e / 2, m) * powMod(v, e / 2, m) * (e % 2 == 1? v : 1)) % m;
}

int main(){
  ios::sync_with_stdio(false);

  int f1 = 2;
  int f2 = 3;
  int mod = 1000;
  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);
  while(true){
    if(f1 == fib[0] && f2 == fib[1])
      break;
    fib.push_back(f1);
    f2 += f1;
    f1 = f2 - f1;

    f2 %= mod;
    f1 %= mod;
  }

  int t;
  cin >> t;
  while(t--){
    string str;
    cin >> str;
    int acc = 0;
    mod = fib.size();
    for(int i = str.length() - 1; i >= 0; i--){
      if(str[i] == '1'){
        acc += powMod(2, str.length() - 1 - i, mod);
        acc %= mod;
      }
    }
    acc = (acc - 1 + mod) % mod;
    if(fib[acc] < 10)
      cout << "00" << fib[acc] << endl;
    else if(fib[acc] < 100)
      cout << "0" << fib[acc] << endl;
    else
      cout << fib[acc] << endl;
  }

  return 0;
}
