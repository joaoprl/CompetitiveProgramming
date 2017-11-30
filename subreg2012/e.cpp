#include <bits/stdc++.h>

using namespace std;

#define MAX_LL 0x7fffffff

typedef long long ll;

ll dpfour[22];
ll dptt[22];

string tostring(ll num) {
	string ret = "";
	while (num) {
		char c = '0';
		c += num % 10;
		ret += c;
		num /= 10;
	}
	for (int i = 0; i < (int)ret.size() / 2; i++) {
		swap(ret[i], ret[(int)ret.size() - 1 - i]);
	}
	return ret;
}

ll solveFour(int x) {
	if (dpfour[x] != -1) return dpfour[x];
	if (x == 0) return dpfour[x] = 0;
	if (x == 1) return dpfour[x] = 1;
	dpfour[x] = 0;
	for (int i = 0; i < x; i++) {
		ll part = 1;
		for (int j = 0; j < i; j++) {
			part *= 9;
		}
		for (int j = i + 1; j < x; j++) {
			part *= 10;
		}
		dpfour[x] += part;
	}
	return dpfour[x];
}

ll solveTT(int x) {
	if (dptt[x] != -1) return dptt[x];
	if (x < 0) return 0;
	if (x == 0) return dptt[x] = 0;
	if (x == 1) return dptt[x] = 0;
	if (x == 2) return dptt[x] = 1;
	dptt[x] = 0;
	for (int i = 1; i < x; i++) {
		ll part = 1;
		ll a = 1;
		for (int j = 0; j < i - 1; j++) {
			a *= 9;
		}
		a -= solveTT(i - 1);
		part *= a;
		for (int j = i + 1; j < x; j++) {
			part *= 9;
		}
		dptt[x] += part;
	}
	return dptt[x];
}

ll solveCompleteFour(string num) {
	ll ret = 0;
	if (num.size() == 1) {
		if (num[0] >= '4') return 1;
		return 0;
	}
	for (int i = '0'; i < num[0]; i++) {
		if (i == '4') {
			ret += pow(10, num.size() - 1);
		} else {
			ret += solveFour(num.size() - 1);
		}
	}
	ll sum = 0;
	for (int i = 1; i < (int)num.size(); i++) {
		sum *= 10;
		sum += num[i] - '0';
	}
	if (num[0] == '4') {
		ret += sum;
	} else {
		if (sum) ret += solveCompleteFour(to_string(sum));
	}
	return ret;
}

ll solveCompleteTT(string num) {
	ll ret = 0;
	if (num.size() == 1) return 0;
	for (int i = '0'; i < num[0]; i++) {
		ret += solveTT(num.size() - 1);
		if (i == '1') {
			ret += pow(9, num.size() - 2);
		}
	}
	ll sum = 0;
	for (int i = 1; i < (int)num.size(); i++) {
		sum *= 10;
		sum += num[i] - '0';
	}
	if (num[0] == '1') {
		for (int i = '0'; i < num[1]; i++) {
			ret += solveTT(num.size() - 2);
			if (i == '3') {
				ret += pow(9, num.size() - 2);
			}
		}
		sum = 0;
		for (int i = 2; i < (int)num.size(); i++) {
			sum *= 10;
			sum += num[i] - '0';
		}
		if (num[1] == '3') {
			ret += sum;
		} else {
			if (sum) ret += solveCompleteTT(tostring(sum));
		}
	} else {
		if (sum) ret += solveCompleteTT(tostring(sum));
	}
	return ret;
}

ll solve(string num) {
	ll four = solveCompleteFour(num);
	ll tt = solveCompleteTT(num);
	
	return four + tt;
}

int main() {
	ios::sync_with_stdio(false);
	memset(dpfour, -1, sizeof(dpfour));
	memset(dptt, -1, sizeof(dptt));
	cout << solveCompleteFour(tostring(24)) << endl;
	cout << solveCompleteTT(tostring(24)) << endl;
	ll n;
	while (cin >> n) {
		ll b = 0, e = MAX_LL, mid;
		while (b < e) {
			mid = (b + e) / 2;
			if (mid - solve(tostring(mid)) >= n) {
				e = mid;
			} else {
				b = mid + 1;
			}
		}
		cout << endl;
		//cout << solve(tostring(b)) << endl;
		cout << b << endl;
	}
	return 0;
}
