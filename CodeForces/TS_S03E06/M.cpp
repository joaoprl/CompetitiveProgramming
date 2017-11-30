
// M. A multiplication game

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
map<long long, bool> wins;

bool solve(ll p) {
  if (wins.find(p) != wins.end()) return wins[p];
  if (p * 9 >= n) return wins[p] = true;
  for (int i = 2; i <= 9; i++) {
    if (!solve(p * i)) return wins[p] = true;
  }
  return wins[p] = false;
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> n) {
    wins.clear();
    if (solve(1)) {
      cout << "Stan wins." << endl;
    } else {
      cout << "Ollie wins." << endl;
    }
  }

  return 0;
}
