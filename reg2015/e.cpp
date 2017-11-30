#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define MAXD 110
#define MAXB 10100

typedef struct{
	int p = 0, d = 0;
	int cost = 0;
} grupo;

int vis[210];
int d, p, r, b;
vector<vector<int> > adj;
vector<int> depd(MAXD), depp(MAXD);

int mem[MAXD][MAXB];

void dfs(int p, int pos, grupo &g){
	vis[pos] = 1;

	if(p){
		g.cost += depp[pos - d];
		g.p++;
	}

	else{
		g.cost += depd[pos];
		g.d++;
	}

	for(int i = 0; i < adj[pos].size(); i++){
		int nx = adj[pos][i];

		if(vis[nx] == 0)
			dfs(1 - p, nx, g);
	}

}

int dp(vector<grupo> v, int pos, int bug, int p){
	if(pos >= v.size())
		return 0;

	if(mem[pos][bug] == -1){
		int res = 0;
	//	printf("entra aki\n");
		if(bug >= v[pos].cost)
			res = (p == 1 ? v[pos].d - v[pos].p : v[pos].p - v[pos].d) + dp(v, pos + 1, bug - v[pos].cost, p);

		//printf("res = %d\n", res);

		res = max(res,  dp(v, pos + 1, bug, p));

		mem[pos][bug] = res;
	}

	//printf("dp %d %d retorna %d\n", pos, bug, mem[pos][bug]);

	return mem[pos][bug];
}

int main(){

	while(cin >> d >> p >> r >> b){

		adj.clear();

		adj.resize(p + d + 1);

		for(int i = 1; i <= d; i++){
			scanf("%d", &depd[i]);
		}

		for(int i = 1; i <= p; i++){
			scanf("%d", &depp[i]);
		}


		for(int i = 0; i < r; i++){
			int a, b;

			scanf("%d %d", &a, &b);
			adj[a].pb(d + b);
			adj[d + b].pb(a);
		}


		vector<grupo> v;

		memset(mem, -1, sizeof(mem));
		memset(vis, 0, sizeof(vis));

		for(int i = 1; i <= p; i++){
			grupo g;
			if(vis[i + d] == 0){
				dfs(1 ,i + d, g);
				v.pb(g);
			}
		}

		//for(int i = 0; i < v.size(); i++){
		//	printf("(%d %d %d) ", v[i].d, v[i].p, v[i].cost);
		//}
		//cout << endl;

		cout << dp(v, 0, b, 0) + d << " ";

		v.clear();

		memset(mem, -1, sizeof(mem));
		memset(vis, 0, sizeof(vis));

		for(int i = 1; i <= d; i++){
			grupo g;
			if(vis[i] == 0){
				dfs(0 ,i, g);
				v.pb(g);
			}
		}

	//	for(int i = 0; i < v.size(); i++){
	//		printf("(%d %d %d) ", v[i].d, v[i].p, v[i].cost);
	//	}

		cout << dp(v, 0, b, 1) + p;
		cout << endl;
	}

	return 0;
}
