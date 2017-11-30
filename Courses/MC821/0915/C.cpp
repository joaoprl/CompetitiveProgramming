// C. Horrible Queries

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class LazySegmentTree{
  vector<ll> sum, lazy; // sum and lazy-sum of given node
  vector<int> lo, hi; // low and high limits of given node
  const vector<ll> val; // initial values

  int l(int i) { return i * 2; } // left child
  int r(int i) { return i * 2 + 1; } // right child
  int m(int i) { return (lo[i] + hi[i]) / 2; } // mid of given node

  void shift(int i){
    if(lo[i] != hi[i]){
      update(l(i), lazy[i]);
      update(r(i), lazy[i]);
    }
    lazy[i] = 0;
  }

  void update(int i, ll v){
    lazy[i] += v;
    sum[i] += (hi[i] - lo[i] + 1) * v;
  }

  void build(int i, int p, int q){
    lo[i] = p;
    hi[i] = q;
    int m = (p + q) / 2;

    if(p != q){
      build(l(i), p, m);
      build(r(i), m + 1, q);
      sum[i] = sum[l(i)] + sum[r(i)];
    }else
      sum[i] = val[p];
  }

  void increase(int i, int p, int q, ll v){
    if(p == lo[i] && q == hi[i]){
      update(i, v);
      return;
    }
    shift(i);

    if(p <= m(i))
      increase(l(i), p, min(m(i), q), v);
    if(q >= m(i) + 1)
      increase(r(i), max(p, m(i) + 1), q, v);
    sum[i] = sum[l(i)] + sum[r(i)];
  }

  ll query(int i, int p, int q){
    if(p == lo[i] && q == hi[i])
      return sum[i];
    shift(i);

    return (p <= m(i) ? query(l(i), p, min(m(i), q)) : 0) +
      (q >= m(i) + 1 ? query(r(i), max(p, m(i) + 1), q) : 0);
  }

public:
  // O(n)
  LazySegmentTree(int n, const vector<ll> &val) : LazySegmentTree(1, n, val) { }

  // O(h - l)
  LazySegmentTree(int p, int q, const vector<ll> &val) : val(val) {
    int n = q - p + 1;

    sum.assign(4 * n, 0);
    lazy.assign(4 * n, 0);

    lo.assign(4 * n, 0);
    hi.assign(4 * n, 0);

    build(1, p, q);
  }

  // O(log(n))
  void increase(int p, int q, ll v){ increase(1, p, q, v); }

  // O(log(n))
  ll query(int p, int q){ return query(1, p, q); }
};

int main(){
  ios::sync_with_stdio(false);
  int t, n, c, k, p, q, v;
  cin >> t;

  vector<ll> vi;
  while(t--){
    cin >> n >> c;
    vi.assign(n + 1, 0);
    LazySegmentTree st(1, n, vi);

    while(c--){
      cin >> k >> p >> q;
      if(k == 0){
        cin >> v;

        st.increase(p, q, v);
      }
      else
        cout << st.query(p, q) << endl;

    }
  }
  return 0;
}
