
#include <iostream>
#include <climits>

#define M 100
#define P 50

using namespace std;

typedef long long ll;

ll ***dp;

ll compute(int i, int j, int p){
  if(i == P && j == P && p == 0)
    return 1;
  else if(p <= 0)
    return 0;
  if(dp[i][j][p] != -1)
    return dp[i][j][p];

  int x1, x2, x3, x4, x5, x6;
  x1 = compute(i - 1, j - 1, p - 1);
  x2 = compute(i - 1, j + 1, p - 1);
  x3 = compute(i - 2, j, p - 1);
  x4 = compute(i + 2, j, p - 1);
  x5 = compute(i + 1, j - 1, p - 1);
  x6 = compute(i + 1, j + 1, p - 1);

  return (dp[i][j][p] = x1 + x2 + x3 + x4 + x5 + x6);
}

int main(){
    ios::sync_with_stdio(false);

    dp = new ll**[M];
    for(int i = 0; i < M; i++){
      dp[i] = new ll*[M];
      for(int j = 0; j < M; j++){
        dp[i][j] = new ll[M];
        for(int k = 0; k < M; k++){
          dp[i][j][k] = -1;
        }
      }
    }

    int n;
    cin >> n;
    for(int c = 0; c < n; c++){
      int v;
      cin >> v;
      cout << compute(P, P, v) << endl;
    }


    return 0;
}
