// H. Lunch in Grid City

#include <iostream>
#include <cstdio>
#include <algorithm>

#define F 50001

using namespace std;

int main(){
  int t, s, a, f;
  int *x, *y;
  x = new int[F];
  y = new int[F];

  cin >> t;
  while(t--){
    cin >> s >> a >> f;

    for(int i = 1; i <= f; i++)
      cin >> x[i] >> y[i];

    sort(x + 1, x + f + 1);
    sort(y + 1, y + f + 1);

    printf("(Street: %d, Avenue: %d)\n", x[(f + 1) / 2], y[(f + 1) / 2]);
  }

  return 0;
}
