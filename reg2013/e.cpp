#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define MOD 1000000007

typedef long long ll;

ll fact[MAXN][MAXN];
ll ret[MAXN];
ll freq[12];
ll acc[12];
ll dv[12];
ll dp[12][12][MAXN];
string s;

ll calcFact(int a) {
  memset(fact[a], 0, sizeof(fact[a]));
  for (int i = 1; i <= a; i++) {
    ll x = i;
    bool cond = true;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) cond = false;
    }
    ll y = a;
    while (y >= x) {
      fact[a][i] += (ll)y / x;
      x *= i;
    }
  }
}

ll solve(ll obj, ll num, ll par) {
  if (dp[obj][num][par] != -1) return dp[obj][num][par];
  dp[obj][num][par] = 0;
  if (num == 10) {
    if (obj == 0) {
      dp[obj][num][par] = 1;
      memset(ret, 0, sizeof(ret));
      for (int i = 0; i < MAXN; i++) {
        ret[i] = fact[s.size() / 2][i] + fact[s.size() - 1 - (s.size() / 2)][i];
        for (int j = 0; j <= 9; j++) {
          ret[i] -= fact[dv[j]][i];
          ret[i] -= fact[freq[j] - dv[j]][i];
        }
        while (ret[i]) {
          dp[obj][num][par] *= i;
          dp[obj][num][par] %= MOD;
          ret[i]--;
        }
      }
      return dp[obj][num][par];
    } else {
      return 0;
    }
  } else {
    ll impar = num ? s.size() - 1 - acc[num-1] - par : s.size() - 1 - par;
    for (ll i = 0; i <= min(par, freq[num]); i++) {
      if (freq[num] - i > impar) continue;
      dv[num] = i;
      dp[obj][num][par] += solve((obj - (2 * i - freq[num]) * num + (ll)11 * 999999999) % 11,
                                  num + 1, par - i);
      dp[obj][num][par] %= MOD;
    }
    return dp[obj][num][par];
  }
}

int main() {
  ios::sync_with_stdio(false);
  memset(fact, 0, sizeof(fact));
  for (int i = 1; i < MAXN; i++) {
    calcFact(i);
  }
  ll ans;
  while (cin >> s) {
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - '0']++;
    }
    ans = 0;
    for (int i = 1; i <= 9; i++) {
      if (!freq[i]) continue;
      memset(dp, -1, sizeof(dp));
      freq[i]--;
      acc[0] = freq[0];
      for (int j = 1; j <= 9; j++) {
        acc[j] = acc[j-1] + freq[j];
      }
      ans += solve(11 - i, 0, s.size() / 2);
      ans %= MOD;
      freq[i]++;
    }
    cout << ans << endl;
  }
  return 0;

}
