
// L1. Theme Park

#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;

#define MAX 1000

vector<vector<pair<int, int> > > adj;

int prim = 0;
int cic = -1;
int tam;
ll gan = 0;

int vis1[MAX];

void dfs1(int pos){

  for(int i = 0; i < adj[pos].size(); i++){
    int nx = adj[pos][i].F;

    if(vis1[nx] == -1){
      vis1[nx] = vis1[pos] + 1;
      dfs1(nx);
    }

    else{
      cic = nx;
      tam = vis1[pos] - vis1[nx] + 1;
      return;
    }
  }

}

ll dfs2(int pos){
  if(pos == cic){
    if(prim == 0)
      prim = 1;
    else
      return 0LL;
  }
  nx = adj[pos][0].F;

  return dfs2(nx) + (ll)adj[pos][0].S;
}

ll dfs3(int pos, int vol){
  ll res = 0;

  if(pos == cic){
    res += ((ll)(vol/tam))*gan;
    vol %= tam;
  }

  if(vol == 0)
    return res;

  return res + adj[pos][0].S + dfs3(adj[pos][0].F, vol - 1);

}

int main(){
  int n, r, k;

  cin >> r >> k >> n;

  adj.resize(r);

  deque<int> fila;

  memset(vis1, -1, sizeof(vis1));

  for(int i = 0; i < n; i++){
    int aux;
    scanf("%d", &aux);
    fila.push(aux);
  }

  queue<int> car;
  for(int i = 0; i < r; i++){
    ll lot = 0;
    int j = 0;

    while(!fila.empty() && lot + (ll)fila.front() <= (ll)k){
      j++;
      lot += (ll)fila.front();
      car.push_back(fila.front());
      fila.pop_front();
    }

    while(!car.empty()){
      fila.push_front(car.back());
      car.pop_back();
    }

    adj[i].push_back(make_pair((i + j)%n, lot));

    fila.push_back(fila.front());

    fila.pop_front();
  }

  vis1[0] = 0;
  dfs1(0);
  gan = dfs2(cic);

  ll res = dfs3(cic, r);

  cout << res << endl;

  return 0;
}
