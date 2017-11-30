
#include <iostream>

#define max3(x, y, z) max(x, max(y, z))

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int m, n;
  while(cin >> m >> n && (m != 0 || n != 0)){

    int count[m];
    for(int i = 0; i < m; i++)
      count[i] = 0;

    int dp[max(n, m)];

    int map[m][n];
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        cin >> map[i][j];

    int ma;
    for(int i = 0; i < m; i++){
      ma = 0;
      for(int j = 0; j < n; j++)
        dp[j] = 0;

      ma = dp[0] = map[i][0];
      if(n > 1){
        dp[1] = map[i][1];
        ma = max(ma, dp[1]);
      }
      if(n > 2){
        dp[2] = map[i][0] + map[i][2];
        ma = max(ma, dp[2]);
      }

      for(int j = 3; j < n; j++){
        dp[j] = max(dp[j - 2], dp[j - 3]) + map[i][j];
        ma = max(dp[j], ma);
      }

      count[i] = ma;
    }

    if(m == 2){
      cout << max(count[0], count[1]) << endl;
      continue;
    }else if(m == 1){
      cout << count[0] << endl;
      continue;
    }

    ma = 0;
    for(int i = 0; i < m; i++)
      dp[i] = 0;
    dp[0] = count[0];
    dp[1] = count[1];
    dp[2] = count[0] + count[2];
    ma = max(dp[1], dp[2]);
    for(int i = 3; i < m; i++){
      dp[i] = max(dp[i - 2] + count[i], dp[i - 3] + count[i]);
      ma = max(ma, dp[i]);
    }

    cout << ma << endl;
  }

  return 0;
}
