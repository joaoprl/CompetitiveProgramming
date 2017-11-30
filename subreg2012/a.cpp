#include <bits/stdc++.h>

using namespace std;

int n, L, C;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> L >> C) {
		int l, c;
		l = c = 0;
		bool first = true;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (first) {
				l++;
				c = s.size();
				first = false;
			} else {
				if (c + 1 + (int)s.size() > C) {
					l++;
					c = s.size();
				} else {
					c += 1 + s.size();
				}
			}
		}
		if (l % L == 0) {
			cout << l / L << endl;
		} else {
			cout << (l / L) + 1 << endl;
		}
	}
	
	return 0;
}
