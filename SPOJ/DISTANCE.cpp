
#include <iostream>
#include <vector>

using namespace std;

int mask(int m, vector<int> x){
  int r = 0;
  for(int i = 0; i < x.size(); i++){
    if((m >> i) & 1)
      r += x[i];
    else
      r -= x[i];
  }
  return r;
}

int main(){
  ios::sync_with_stdio(false);

  int n, d;
  cin >> n >> d;

  int M = 1 << d;
  int dp[M];

  vector<int> x(d, 0);
  for(int i = 0; i < d; i++)
    cin >> x[i];
  for(int m = 0; m < M; m++)
    dp[m] = mask(m, x);

  int ma = 0;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < d; j++)
      cin >> x[j];

    for(int m = 0; m < M; m++)
      dp[m] = max(dp[m], mask(m, x));

    for(int m = 0; m < M; m++)
      ma = max(ma, mask(-m - 1, x) + dp[m]);
  }

  cout << ma << endl;

  return 0;
}
