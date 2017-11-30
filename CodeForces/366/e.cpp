
#include <iostream>

using namespace std;

int mask(int m, int i, int j){
  if(m == 0)
    return i + j;
  if(m == 1)
    return i - j;
  if(m == 2)
    return -i + j;
  if(m == 3)
    return -i - j;
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  int n, m, k, s;
  cin >> n >> m >> k >> s;

  int grid[n][m];
  int dp[k + 1][4];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];

      for(int v = 0; v < 4; v++)
        dp[grid[i][j]][v] = mask(v, i, j);
    }
  }

  int ss[s];
  for(int i = 0; i < s; i++)
    cin >> ss[i];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      for(int v = 0; v < 4; v++)
        dp[grid[i][j]][v] = max(dp[grid[i][j]][v], mask(v, i, j));

  int ma = 0;
  for(int i = 1; i < s; i++)
    for(int v = 0; v < 4; v++)
      ma = max(ma, dp[ss[i - 1]][v] + dp[ss[i]][3 - v]);

  cout << ma << endl;



  return 0;
}
