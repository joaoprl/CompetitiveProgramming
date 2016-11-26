// A. Alyona and copybooks

#include <iostream>
#include <climits>

#define min3(x, y , z) min(x, min(y, z))

using namespace std;

long long compute(int n, int a, int b, int c){
  if(n > 12)
    return INT_MAX;
  if(n % 4 == 0)
    return 0;

  return min3(a + compute(n + 1, a, b, c), b + compute(n + 2, a, b, c), c + compute(n + 3, a, b, c));
}

int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  n = n % 4;
  cout << compute(n, a, b, c) << endl;

  return 0;
}
