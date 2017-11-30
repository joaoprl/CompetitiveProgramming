// Salary Management

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

class LazySegmentTree{
  LazySegmentTree *left, *right;
  ll sum;
  ll mi;
  ll lazySum;
  int lo, mid, hi;

  void shift(){
    if(lo != hi){
      left->update(lazySum);
      right->update(lazySum);
    }
    lazySum = 0;
  }

  void update(ll v){
    lazySum += v;
    sum += (hi - lo + 1) * v;
    mi += v;
  }

public:
  // O(n)
  LazySegmentTree(int n, const vector<int> &val) : LazySegmentTree(1, n, val) { }

  // O(q - p)
  LazySegmentTree(int p, int q, const vector<int> &val){
    mi = sum = 0;
    lazySum = 0;
    lo = p;
    mid = (p + q) / 2;
    hi = q;

    left = right = NULL;
    if(p != q){
      left = new LazySegmentTree(lo, mid, val);
      right = new LazySegmentTree(mid + 1, hi, val);

      sum = left->sum + right->sum;
      mi = min(left->mi, right->mi);
    }
    else
      mi = sum = val[lo];
  }

  // O(hi - lo)
  ~LazySegmentTree(){
    if(lo != hi){
      delete left;
      delete right;
    }
  }

  // O(log(n))
  void increase(int p, int q, ll v){
    if(p == lo && q == hi){
      update(v);
      return;
    }
    shift();

    if(p <= mid)
      left->increase(p, min(mid, q), v);
    if(q >= mid + 1)
      right->increase(max(p, mid + 1), q, v);
    sum = left->sum + right->sum;
    mi = min(left->mi, right->mi);
  }

  // O(log(n))
  ll query(int p, int q){
    if(p == lo && q == hi)
      return sum;
    shift();
    ll s = 0;
    if(p <= mid)
      s += left->query(p, min(mid, q));
    if(q >= mid + 1)
      s += right->query(max(p, mid + 1), q);
    return s;
  }

  ll queryMin(int p, int q){
    if(p == lo && q == hi)
      return mi;
    shift();
    ll s = LLONG_MAX;
    if(p <= mid)
      s = min(s, left->queryMin(p, min(mid, q)));
    if(q >= mid + 1)
      s = min(s, right->queryMin(max(p, mid + 1), q));
    return s;
  }

};

void DFS(vector<int> *edges, int u, vector< pair<int, int> > &tim, int &tCount, vector<int> &sal, vector<int> &salOut){
  tim[u].first = ++tCount;
  salOut[tCount] = sal[u];

  for(int i = 0; i < edges[u].size(); i++)
    DFS(edges, edges[u][i], tim, tCount, sal, salOut);

  tim[u].second = tCount;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; k++){
    int n, q;
    scanf("%d%d", &n, &q);

    vector<int> *edges = new vector<int>[n + 1];
    vector<int> sal(n + 1, -1);
    int p, s;
    for(int i = 1; i <= n; i++){
      scanf("%d%d", &p, &s);

      edges[p].push_back(i);
      sal[i] = s;
    }

    vector< pair<int, int> > tim(n + 1, {-1, -1});
    vector<int> salOut(n + 1, -1);
    int t = 0;
    DFS(edges, 1, tim, t, sal, salOut);

    LazySegmentTree tr(n, salOut);
    printf("Case %d:\n", k);

    int c, v;
    for(int i = 0; i < q; i++){
      scanf("%d%d", &c, &v);
      if(c == 1)
        printf("%lld\n", tr.query(tim[v].first, tim[v].second));
      else
        tr.increase(tim[v].first, tim[v].second, min((ll)1000, tr.queryMin(tim[v].first, tim[v].second)));
    }
  }

  return 0;
}
