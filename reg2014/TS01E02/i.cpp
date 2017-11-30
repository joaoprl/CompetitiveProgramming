
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

#define MAX 100010

typedef struct{
	int custo = 0, volta = 0, util = 0;
} retorno;

vector< vii > adj;

int amigo[MAX];

retorno dfs(int pos){
//	printf("dfs de %d\n", pos);
	retorno r;
	
	if(amigo[pos])
		r.util = 1;
	
	for(int i = 0; i < adj[pos].size(); i++){
		int nx = adj[pos][i].F;
		//printf("%d chama %d\n", pos, nx);
		retorno a = dfs(nx);
		if(a.util){
			r.util = 1; 
			r.custo += a.custo + adj[pos][i].S;
			if(a.volta + adj[pos][i].S > r.volta)
				r.volta = a.volta + adj[pos][i].S;
			//if(pos == 1)
				//printf("custo = %d\n", r.custo);
		}
	}
	
//	printf("%d retorna %d %d %d\n", pos, r.custo, r.volta, r.util);
	//
	return r;
	
}

int main(){
	
	int n, f;
	
	while(cin >> n >> f){
		adj.clear();
		adj.resize(n+1);
		
		memset(amigo, 0, sizeof(amigo));
		
		for(int i = 0; i < n - 1 ; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a].pb({b, c});
		}
		
		for(int i = 0; i < f; i++){
			int a;
			scanf("%d", &a);
			amigo[a] = 1;
		}
		
		retorno r = dfs(1);
		
		printf("%d\n", r.custo - r.volta);
	}
	
	return 0;
}
