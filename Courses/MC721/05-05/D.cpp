
#include <iostream>

#define R 110
#define K 10100
#define INF 100000

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int r, k;
  int *v = new int[R];

  int **m = new int*[R];
  for(int i = 0; i < R; i++)
    m[i] = new int[K];

  while(cin >> r >> k){
    for(int i = 0; i <= r; i++)
      v[i] = 0;

    for(int i = 0; i <= r; i++){
      for(int j = 0; j <= k; j++)
        m[i][j] = 0;
    }

    int a, b;
    for(int i = 1; i <= k; i++){
      cin >> a >> b;
      v[a]++;
      v[b]++;
    }

    for(int i = 1; i <= r; i++){
      for(int j = 0; j <= k; j++){
        if(v[i] > j)
          m[i][j] = m[i - 1][j];
        else
          m[i][j] = max(m[i - 1][j], m[i - 1][j - v[i]] + v[i]);
      }
    }

    if(m[r][k] == k)
      cout << "S\n";
    else
      cout << "N\n";
  }

  return 0;
}
