
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int dp[15];
  int fact[15];

  for(int i = 0; i < 15; i++)
    dp[i] = -1;
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;

  fact[0] = 1;
  fact[1] = 1;
  fact[2] = 2;

  for(int i = 3; i < 15; i++){
    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    fact[i] = i * fact[i - 1];
  }


  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    cout << dp[num] << "/" << fact[num] << endl;
  }

  return 0;
}
