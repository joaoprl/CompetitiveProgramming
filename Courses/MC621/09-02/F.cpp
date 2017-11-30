// F. Block Towers

#include <iostream>

using namespace std;

int main(){
  int n, m, c, ma;
  cin >> n >> m;

  ma = max(max(2 * n, 3 * m), (n + m) * 3 / 2);
  ma -= ma % 6;
  m -= ma / 6;
  n -= ma / 3;
  c = ma / 6;

  if(n <= 0 && m > 0)
    cout << ma + 3 * (m - c) << "\n";
  else if(m <= 0 && n > 0)
    cout << ma + 2 * (n - c) << "\n";
  else{
    while(c > 0){
      if(n > m){
        n--; c--;
      }
      else if(n <= m){
        m--; c--;
      }
    }

    if(n == 2)
      ma += 4;
    else if(m == 1)
      ma += 3;
    else if(n == 1)
      ma += 2;

    cout << ma << "\n";

  }
  return 0;
}
