#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

priority_queue<int> pq[MAXN];
int maxi[MAXN];
int acc[MAXN];

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    memset(maxi, -1, sizeof(maxi));
    memset(acc, 0, sizeof(acc));
    for (int i = 0; i < MAXN; i++) {
      while (!pq[i].empty()) pq[i].pop();
    }
    int start = - 1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      acc[x]++;
      start = max(start, x);
    }
    int ans = 0;
    while (acc[start]) {
      ans++;
      acc[start]--;
      pq[start].push(-1);
      maxi[start] = 1;
    }
    int p = start;
    while (p) {
      while (acc[p]) {
        pq[p].push(-maxi[p + 1]);
        ans += maxi[p + 1];
        acc[p]--;
      }
      while (!pq[p].empty()) {
        int a = -pq[p].top(); pq[p].pop();
        int b = -pq[p].top(); pq[p].pop();
        pq[p-1].push(-(a + b));
        maxi[p] = max(maxi[p], b);
      }
      p--;
    }
    cout << ans << endl;
  }
  return 0;
}
