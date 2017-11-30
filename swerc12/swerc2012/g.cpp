// G. How do spiders walk on water?

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10100

typedef long long ll;

int n, power;
string s;
ll v[MAXN];
vector<pair<ll, ll> > w;

int main() {
	while (getline(cin, s)) {
		w.clear();
		stringstream ss(s);
		ss >> n >> power;
		int k = 0;
		bool cond = false;
		while (ss >> v[k]) {
			if (v[k] > 1000) {
				cond = true;
			}
			k++;
		}
		
		if (k < n + 1) {
			for (int i = 0; i < 1001; i++) {
				if (v[0] || v[1]) {
					if (v[1]) {
						if ((v[2] - v[0] * i) >= 0 &&
						 (v[2] - v[0] * i) % v[1] == 0) {
							w.push_back({i, (v[2] - v[0] * (ll)i) / v[1]});
						}
					} else {
						if ((v[2] - v[1] * i) >= 0 &&
						 (v[2] - v[1] * i) % v[0] == 0) {
							w.push_back({(v[2] - v[1] * (ll)i) / v[0], i}); 
						}
					}
				}
			}
			ll a = 0, b = 0;
			for (int i = 0; i < (int)w.size(); i++) {
				if (w[i].first * v[1] + w[i].second * v[2] == v[3]) {
					a = w[i].first;
					b = w[i].second;
					break;
				}
			}
			for (int i = k; i <= n; i++) {
				if (cond) {
					v[i] = 1001;
				} else {
					v[i] = min((ll)1001, a * v[i-2] + b * v[i-1]);
				}
			}
		}
		if (v[0] > power) {
			cout << "The spider is going to fall!" << endl;
		} else if (v[n] <= power) {
			cout << "The spider may fall!" << endl;
		} else {
			for (int i = 0; i <= n; i++) {
				if (v[i] > power) {
					cout << n + 1 - i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
