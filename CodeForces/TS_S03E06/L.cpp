
// L. Subway

#include <bits/stdc++.h>

using namespace std;

#define MAXN 220

typedef long long ll;

ll n;
double g[MAXN][MAXN];
double walkspd;
ll x[MAXN];
ll y[MAXN];

double dist(int a, int b) {
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int main() {
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      if (i == j) g[i][j] = 0;
      else g[i][j] = 9999999999999;
    }
  }
  walkspd = 10000;
  scanf("%lld %lld", &x[0], &y[0]);
  scanf("%lld %lld", &x[1], &y[1]);
  g[0][1] = g[1][0] = dist(0, 1) / walkspd;
  bool cond = false; n = 2;
  while (scanf("%lld %lld", &x[n], &y[n]) != EOF) {
    if (x[n] == -1 && y[n] == -1) {
      cond = false;
    } else {
      for (int i = 0; i < n; i++) {
        g[i][n] = g[n][i] = dist(i, n) / walkspd;
      }
      if (cond) {
        g[n-1][n] = g[n][n-1] = dist(n-1, n) / (4 * walkspd);
      }
      cond = true;
      n++;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  printf("%.0lf\n", g[0][1] * 60);


  return 0;
}
