// E. Qwerty78 Trip

#include <iostream>
#include <cstdio>

using namespace std;

int factorial(int n){
  if(n < 1)
    return 1;
  
  int v = 1;
  for(int i = 1; i <= n; i++)
    v *= i;
  
  return v;
}

int partialFactorial(int n, int m){
  int v = 1;
  while(n != m){
    v *= n;
    n--;
  }

  return v;
}

int combinatory(int a, int b){
  return partialFactorial(a, a - b) / factorial(b);
}

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int ways = 0;
    int x, y;
    
    x = r - 1;
    y = c + 1;
    while(x >= 1 && y <= m){
      ways += combinatory(x + y - 2, y - 1) * combinatory(n - x + m - y, m - y) % ((int)1e9 + 7);
      
      x--; y++;
      ways %= (int)1e9 + 7;
    }

    x = r + 1;
    y = c - 1;
    while(x <= n && y >= 1){
      ways += combinatory(x + y - 2, y - 1) * combinatory(n - x + m - y, m - y) % ((int)1e9 + 7);

      x++; y--;
      ways %= (int)1e9 + 7;
    }
    
    cout << ways << "\n";
    
  }
  return 0;
}
