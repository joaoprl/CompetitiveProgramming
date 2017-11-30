// E. Números Par-Primos

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  long long a, b;
  long long rA, rB;
  while(cin >> a >> b){
    if(a == 0 && b == 0)
      return 0;
    rB = (int)sqrt(b);
    rA = (int)sqrt(a);

    while(rB * rB > b)
      rB--;
    while(rA * rA > a)
      rA--;

    long long c = b - a + 1;
    c -= rB - rA;
    if(rA * rA == a)
      c--;

    cout << c << "\n";
  }

  return 0;
}
