
#include <iostream>

using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main(){
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;
  if(x < 0)
    x = -x;

  int g = 0, a;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(g == 0)
      g = a;
    else
      g = gcd(g, a);
  }

  if(x % g == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;


  return 0;
}
