// G. Preparing Olympiad

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int combinations(int *c, int i, int j, int l, int r, int x, int min, int max){
  if(r < 0)
    return 0;
    
  if(i == j){
    if(max - min >= x && l <= 0 && r >= 0)
      return 1;
    else
      return 0;
  }

  int total = 0;

  if(min == -1)
    total += combinations(c, i + 1, j, l - c[i], r - c[i], x, c[i], c[i]);
  else
    total += combinations(c, i + 1, j, l - c[i], r - c[i], x, min, c[i]);

  total += combinations(c, i + 1, j, l, r, x, min, max);

  return total;
}

int main(){
  int n, l, r, x;
  cin >> n >> l >> r >> x;

  int *c = new int[n];
  for(int i = 0; i < n; i++)
    cin >> c[i];

  sort(c, c + n);

  cout << combinations(c, 0, n, l, r, x, -1, -1) << "\n";
}
