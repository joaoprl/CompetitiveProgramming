// B. Princess Farida

#include <iostream>
#include <cstdio>

#define N (int)1e4+1

using namespace std;

int main(){
  int t, n;

  long long *monsters = new long long[N];

  cin >> t;

  for(int u = 1; u <= t; u++){
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> monsters[i];

    if(n > 1)
      monsters[1] = max(monsters[0], monsters[1]);
    for(int i = 2; i < n; i++)
      monsters[i] = max(monsters[i - 2] + monsters[i], monsters[i - 1]);

    if(n > 0)
      printf("Case %d: %lld\n", u, monsters[n - 1]);
    else
      printf("Case %d: 0\n", u);
  }

  return 0;

}
