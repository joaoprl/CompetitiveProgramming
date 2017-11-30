#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef pair<int, int> pii;
typedef vector<pii> vii;

#define MAX 100010
#define INF 1000000000
#define LIM 150000

int n;

int esq[4*MAX], dir[4*MAX], s[4*MAX];
int aesq[MAX], adir[MAX], a[MAX];

void build(int id = 1, int l = 0, int r = n){
  if(r - l < 2){
    s[id] = a[l];
    return;
  }
  int mid = (l + r)/2;
  build(id*2, l, mid);
  build(id*2 + 1, mid, r);
  s[id] = min(s[id*2], s[id*2 + 1]);
}

int menor(int x, int y, int id = 1, int l = 0, int r = n){
  //printf("menor %d %d %d %d %d\n", x, y, id, l, r);
  if(x >= r or l >= y)  return INF;
  if(x <= l && r <= y)  return s[id];
  int mid = (l + r)/2;
  return min(menor(x, y, id*2, l, mid), menor(x, y, id*2 + 1, mid, r));
}

//dir
void builddir(int id = 1, int l = 0, int r = n){
  if(r - l < 2){
    dir[id] = adir[l];
    return;
  }
  int mid = (l + r)/2;
  builddir(id*2, l, mid);
  builddir(id*2 + 1, mid, r);
  dir[id] = min(dir[id*2], dir[id*2 + 1]);
}

void modifydir(int p, int x, int id = 1, int l = 0, int r = n){
  dir[id] = min(x, dir[id]);
  if(r - l < 2){
    adir[p] = x;
    return;
  }

  int mid = (l + r)/2;
  if(p < mid)
    modifydir(p, x, 2*id, l, mid);
  else
    modifydir(p, x, 2*id + 1, mid, r);
}

int menordir(int x, int y, int id = 1, int l = 0, int r = n){
  if(x >= r or l >= y)  return INF;
  if(x <= l && r <= y)  return dir[id];
  int mid = (l + r)/2;
  return min(menordir(x, y, id*2, l, mid), menordir(x, y, id*2 + 1, mid, r));
}

//esq
void buildesq(int id = 1, int l = 0, int r = n){
  if(r - l < 2){
    esq[id] = aesq[l];
    return;
  }
  int mid = (l + r)/2;
  buildesq(id*2, l, mid);
  buildesq(id*2 + 1, mid, r);
  esq[id] = max(esq[id*2],esq[id*2 + 1]);
}

void modifyesq(int p, int x, int id = 1, int l = 0, int r = n){
  esq[id] = max(x, esq[id]);
  if(r - l < 2){
    aesq[p] = x;
    return;
  }

  int mid = (l + r)/2;
  if(p < mid)
    modifyesq(p, x, 2*id, l, mid);
  else
    modifyesq(p, x, 2*id + 1, mid, r);
}

int maioresq(int x, int y, int id = 1, int l = 0, int r = n){
  if(x >= r or l >= y)  return -1;
  if(x <= l && r <= y)  return esq[id];
  int mid = (l + r)/2;
  return max(maioresq(x, y, id*2, l, mid), maioresq(x, y, id*2 + 1, mid, r));
}

int main(){
  while(cin >> n){
    memset(esq, 0, sizeof(esq));
    memset(dir, 0, sizeof(dir));
    memset(s, 0, sizeof(s));
    memset(aesq, -1, sizeof(aesq));
    for(int i = 0; i < n; i++)
      adir[i] = INF;


    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    build();
    builddir();
    buildesq();

  //  printf("ok2\n");

    vii v;

    for(int i = 0; i < n; i++)
      v.pb({a[i], i});

    sort(v.begin(), v.end());

    queue<pii> fila;

    vector<int> ultra;

  //  printf("ok3\n");

    for(int i =  n - 1; i >= 0; i--){
      //printf("int i = %d\n", i);
      while(!fila.empty() && v[i].F < fila.front().F){
        int pos = fila.front().S;
        fila.pop();
        modifyesq(pos, pos);
        modifydir(pos, pos);
      }

      //printf("ok4\n");
      int d;
      int h = v[i].F;
      int pos = v[i].S;
      int es, dr;
      es = maioresq(0, pos);
      dr = menordir(pos, n - 1);

      //printf("ok5\n");

      //printf("%d %d\n", es, dr);

      if(es == -1 && dr == INF){
      //  cout << "ok6" << endl;
        ultra.pb(v[i].S);
      //  printf("ok7\n");
      }

      else if(es == -1){
        //cout << "ok8" << endl;
        int posm = menor(pos, dr);
        if(h - posm >= LIM)
          ultra.pb(v[i].S);
      }

      else if(dr == INF){
        //cout << "ok9" << endl;
        int posm = menor(es, pos);
        //printf("posm = %d\n", posm);
        if(h - posm >= LIM)
          ultra.pb(v[i].S);
      }

      else{
        //cout << "ok10" << endl;
        int posm1 = menor(es, pos);
        int posm2 = menor(pos, dr);
        if(h - max(posm1, posm2) >= LIM)
          ultra.pb(v[i].S);
      }

      fila.push(v[i]);
    }

    sort(ultra.begin(), ultra.end());

    for(int i = 0; i < ultra.size(); i++)
      printf("%d%c", ultra[i] + 1, " \n"[i == ultra.size() - 1]);
  }

  return 0;
}
/*ok2
ok3
int i = 4
ok4
ok5
-1 1000000000
ok6
ok7
int i = 3
ok4
ok5
-1 3
ok8
int i = 2
ok4
ok5
-1 2
ok8
int i = 1
ok4
ok5
3 1000000000
ok9
Segmentation fault
*/
