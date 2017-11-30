
// H. Kid's Play

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int, int> pi;

#define MAX 100010

vector<vi> adj;
vector<vi> ciclos;
vector<pi> ql;

int vis[MAX];

void dfs(int pos, int cic, int ord){
 // printf("pos = %d\n", pos);

  vis[pos] = 1;
  ciclos[cic].pb(pos);
  ql[pos] = mkp(cic, ord);

  for(int i = 0; i < adj[pos].size(); i++){
    int nx = adj[pos][i];
    if(vis[nx] == 0){
      dfs(nx, cic, ord + 1);
    }
  }
}

int main(){
  int n, k;
  cin >> n >> k;
  adj.resize(n+1);

  int deskup[MAX], deskdown[MAX];

  for(int i = 1; i <= n; i++){
    int u, d;
    scanf("%d %d", &u, &d);
    deskup[u] = i;
    deskdown[d] = i;
  }


  for(int i = 1; i <=n ; i++)
    adj[deskdown[i]].pb(deskup[i]);

  ql.resize(n + 1);

  for(int i = 1; i <= n; i++)
    if(vis[i] == 0){
     // printf("i = %d\n", i);
      ciclos.resize(ciclos.size() + 1);
      dfs(i, ciclos.size() - 1, 0);
    }

  //printf("ok\n");

  for(int i = 1; i <= k; i++){
    int des, ar;
    scanf("%d %d", &des, &ar);
    printf("%d\n", ciclos[ql[des].F][(ql[des].S + ar)%ciclos[ql[des].F].size()]);
  }
}
