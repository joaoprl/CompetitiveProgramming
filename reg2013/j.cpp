#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define MAX 40100

int distn1[MAX], distn2[MAX], distq1[MAX], distq2[MAX];
int dist[MAX];

vector<vector<int> > adjn, adjq;

void dfs(int pos, int dist[], vector<vector<int> > adj, int deb = 0){
  if(deb == 1)
    printf("dfs %d\n", pos);
  for(int i = 0; i < adj[pos].size(); i++){
    int nx = adj[pos][i];
    if(deb) printf("nx = %d\n", nx);
    if(dist[nx] == -1){
      dist[nx] = dist[pos] + 1;
      dfs(nx, dist, adj, deb);
    }
  }
}

int main(){
  int n, q;
  while(cin >> n >> q){
    adjn.clear();
    adjq.clear();

    adjn.resize(n + 1);
    adjq.resize(q + 1);

    for(int i = 0; i < n - 1; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      adjn[a].pb(b);
      adjn[b].pb(a);
    }

    for(int i = 0; i < q - 1; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      adjq[a].pb(b);
      adjq[b].pb(a);
    }

    int exn1, exn2, exq1, exq2;

    memset(dist, -1, sizeof(dist));
    memset(distn1, -1, sizeof(distn1));
    memset(distn2, -1, sizeof(distn2));
    memset(distq1, -1, sizeof(distq1));
    memset(distq2, -1, sizeof(distq2));
;

    dist[1] = 0;
    dfs(1, dist, adjn);


    int mx = -1;
    for(int i = 1; i <= n; i++){
      if(dist[i] > mx){
        mx = dist[i];
        exn1 = i;
      }
    }

    distn1[exn1] = 0;
    dfs(exn1, distn1, adjn);

    mx = -1;
    for(int i = 1; i <= n; i++){
      if(distn1[i] > mx){
        mx = distn1[i];
        exn2 = i;
      }
    }

    distn2[exn2] = 0;


    dfs(exn2, distn2, adjn);


    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    dfs(1, dist, adjq);

    mx = -1;
    for(int i = 1; i <= q; i++){
      if(dist[i] > mx){
        mx = dist[i];
        exq1 = i;
      }
    }

    distq1[exq1] = 0;
    dfs(exq1, distq1, adjq);
    mx = -1;
    for(int i = 1; i <= q; i++){
      if(distq1[i] > mx){
        mx = distq1[i];
        exq2 = i;
      }
    }

    distq2[exq2] = 0;
    dfs(exq2, distq2, adjq);

    vector<int> contn(n+1), contq(q + 1);

    for(int i = 1; i <= n; i++){
      contn[i] = max(distn1[i], distn2[i]);
    }


    for(int i = 1; i <= q; i++){
      contq[i] = max(distq1[i], distq2[i]);
    }

    sort(contq.begin() + 1, contq.end());

    vector<int> acc(q+1);

    acc[1] = contq[1];
    for(int i = 2; i <= q; i++)
      acc[i] = acc[i-1] + contq[i];

    ll res = 0LL;

    int maximo = max(distn1[exn2], distq1[exq2]);

    for(int i = 1; i <= n; i++){
      int mn = 1;
      int mx = q;

      while(mx > mn){
        int md = (mn + mx)/2;

        if(contq[md] + contn[i] + 1 > maximo)
          mx = md;
        else
          mn = md + 1;
      }

        if(contq[mn] + contn[i] + 1 > maximo){
          res += (acc[q] - acc[mn - 1]) + (contn[i] + 1)*(q - mn + 1);
          res += (mn - 1)*maximo;
        }
        else
          res += maximo*q;

    }

    printf("%.3lf\n", (double)(res/(double)(n*q)));

  }

  return 0;
}
/*
3 1 2 1
contn = 7
contq = 13
5.350
1 1 5 1
contn = 0
contq = 16
4.200

*/
