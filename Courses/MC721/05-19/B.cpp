
#include <iostream>

#define min3(x, y, z) min(x, min(y, z))

using namespace std;

int pow2(int b, int e){
  if(e == 0)
    return 1;
  return pow2(b, e / 2) * pow2(b, e / 2) * (e % 2 == 1? b : 1);
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  int i = 0, v;
  int count = 1;
  n++;
  while(n > 10){
    v = n % 10;
    if(v != 0){
      count += (10 - v) * pow2(10, i);
      n += 10 - v;
    }
    i++;
    n /= 10;
  }

  cout << count << endl;

  return 0;
}
