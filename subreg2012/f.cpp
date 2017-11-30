#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

int n, A, B, C;
int prv[MAXN];
vector<int> g[MAXN];
vector<int> rig;
vector<int> wrong;

int main() {
	while (scanf("%d %d %d %d", &n, &A, &B, &C) != EOF) {
		for (int i = 0; i < MAXN; i++) g[i].clear();
		memset(prv, -1, sizeof(prv));
		rig.clear();
		wrong.clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		queue<int> myq;
		myq.push(A);
		while (!myq.empty()) {
			int p = myq.front();	myq.pop();
			for (int i = 0; i < (int)g[p].size(); i++) {
				int to = g[p][i];
				if (prv[to] == -1) {
					prv[to] = p;
					myq.push(to);
				}
			}
		}
		int x = B;
		while (x != A) {
			rig.push_back(x);
			x = prv[x];
		}
		x = C;
		while (x != A) {
			wrong.push_back(x);
			x = prv[x];
		}
		double ans;
		bool cond = false;
		for (int i = 0; i < (int)rig.size(); i++) {
			if (rig[i] == C) {
				ans = 0;
				printf("%.6lf\n", ans);
				cond = true;
				break;
			}
		}
		if (cond) continue;
		int nb = rig.size(), nc = wrong.size();
		while (rig[nb-1] == wrong[nc-1]) {
			nb--;	nc--;
		}
		ans = ((double)(nc) / (double)(nc + nb));
		printf("%.6lf\n", ans);
		
	}
	
	
	return 0;
}
