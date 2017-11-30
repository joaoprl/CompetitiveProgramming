
#include <iostream>

using namespace std;

int findTotal(int a){
  int total = 0;

  total += min(100, a) * 2;

  if(a > 100)
    total += (min(10000, a) - 100) * 3;

  if(a > 10000)
    total += (min(1000000, a) - 10000) * 5;

  if(a > 1000000)
    total += (a - 1000000) * 7;

  return total;
}

bool findSum(int v, int a, int b, int &r){
  int tA = findTotal(a);
  int tB = findTotal(b);
  tA = max(tA, 0);
  tB = max(tB, 1000000001);
  cout << a << " " << b << " " << tA << " " << tB << endl;
  if(tA == v){
    r = a;
    return true;
  }
  if(tB == v){
    r = b;
    return true;
  }
  if(v < tA || v > tB || a == b)
    return false;

  return findSum(v, a, (a + b) / 2, r) || findSum(v, (a + b) / 2, b, r);
}

int main(){
  ios::sync_with_stdio(false);

  int a, b;
  while(cin >> a >> b && (a != 0 || b != 0)){
    int r;
    findSum(a, 0, 1000000000, r);

    cout << findTotal(a) << endl;
    cout << r << endl;
  }

  return 0;
}
