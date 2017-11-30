
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

const int INF = 1e9;
const double EPS = 1e-6;
const double PI = acos(-1);

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define MAXX 500100
#define MAXN 50010
#define eps 1e-9

vector<vi> adj;
vector<vii> star;

double hip(double x1, double y1, double x2, double y2){
	return sqrt( abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2) ); 
}

int vis[MAXN];

pii dfs(int pos, int cor){
	pii res = {0, 0};
	if(cor)
		res.S++;
	else
		res.F++;
		
	vis[pos] = cor;
		
	for(int i = 0; i < adj[pos].size(); i++){
		int nx = adj[pos][i];
		
		if(vis[nx] == -1){
			pii aux = dfs(nx, 1 - cor);
			res.F += aux.F;
			res.S += aux.S;
		}
	}
	
	return res;
}

int main(){
	int n;
	
	while(cin >> n){
		adj.clear();
		star.clear();
		
		adj.resize(n + 1);
		star.resize(MAXX);
		
		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			star[a].pb({b, i});
		}
		
		for(int i = 1; i < MAXX; i++)
			sort(star[i].begin(), star[i].end());
		
		for(int i = 1; i < MAXX; i++){
			for(int j = 0; j < star[i].size(); j++){
				for(int k = j + 1; k < star[i].size() && (star[i][k].F - star[i][j].F) <= 5 ; k++){
					adj[star[i][j].S].pb(star[i][k].S);
					adj[star[i][k].S].pb(star[i][j].S);
				}
				
				for(int k = i + 1; k <= i + 5 && k < MAXX; k++){
					for(int w = 0; w < star[k].size(); w++){
						if( hip(i, star[i][j].F, k, star[k][w].F) <= 5 + eps){
							adj[star[i][j].S].pb(star[k][w].S);
							adj[star[k][w].S].pb(star[i][j].S);
						}
						else
							break;
					}
				}
			}
		}
		
		int res = 0;
		pii aux;
		memset(vis, -1, sizeof(vis));
		
		for(int i = 0; i < n; i++){
			if(vis[i] == -1){
				aux = dfs(i, 0);
				res += min(aux.F, aux.S);
			}
		}
		
		printf("%d\n", res);
	}
	
	return 0;
}
