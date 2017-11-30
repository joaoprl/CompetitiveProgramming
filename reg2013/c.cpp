
#include <iostream>

using namespace std;
typedef long long ll;

ll compute(ll v){
  ll acc = 0, aux;
  for(ll p = 2; p < 2 * v; p *= 2){
    acc += (v / p) * (p / 2);
    aux = v - (v / p) * (p / 2) * 2;
    acc += max(0LL, aux - p / 2);
  }
  return acc;
}

int main(){
  ios::sync_with_stdio(false);
  ll a, b;
  while(cin >> a >> b)
    cout << compute(b + 1) - compute(a) << endl;
  return 0;
}
