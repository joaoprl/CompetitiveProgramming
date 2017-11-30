
#include <iostream>
#include <vector>
#include <cstring>

#define F 9
#define MAXN 100010

using namespace std;

int sum[MAXN * 4][F];
int lazy[MAXN * 4];
int lo[MAXN * 4];
int hi[MAXN * 4];
int temp[F];
int val[MAXN][F]; // initial values

void sumV(int *a, int *b, int *r){
  for(int i = 0; i < F; i++)
    r[i] = a[i] + b[i];
}

void equals(int *a, int *r){
  for(int i = 0; i < F; i++)
    r[i] = a[i];
}

class LazySegmentTree{

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

  void update(int i, int v){
    v %= F;
    if(v == 0)
      return;

    lazy[i] += v;
    equals(sum[i], temp);

    for(int k = 0; k < F; k++)
      sum[i][k] = temp[(k - v + F) % F];
  }

  void build(int i, int p, int q){
    lo[i] = p;
    hi[i] = q;
    int m = (p + q) / 2;

    if(p != q){
      build(l(i), p, m);
      build(r(i), m + 1, q);
      sumV(sum[l(i)], sum[r(i)], sum[i]);
    }else
      equals(val[p], sum[i]);
  }

  void increase(int i, int p, int q, int v){
    if(p == lo[i] && q == hi[i]){
      update(i, v);
      return;
    }

    shift(i);

    if(p <= m(i))
      increase(l(i), p, min(m(i), q), v);
    if(q >= m(i) + 1)
      increase(r(i), max(p, m(i) + 1), q, v);
    sumV(sum[l(i)], sum[r(i)], sum[i]);
  }

  void query(int i, int p, int q, vector<int> &ans){
    if(p == lo[i] && q == hi[i]){
      for(int k = 0; k < F; k++)
        ans[k] += sum[i][k];
      return;
    }

    shift(i);

    if(p <= m(i))
      query(l(i), p, min(m(i), q), ans);

    if(q >= m(i) + 1)
      query(r(i), max(p, m(i) + 1), q, ans);
  }

public:
  // O(n)
  LazySegmentTree(int n) : LazySegmentTree(1, n) { }

  // O(h - l)
  LazySegmentTree(int p, int q){
    int n = q - p + 1;

    memset(sum, 0, sizeof(int) * 4 * n);
    memset(lazy, 0, sizeof(int) * 4 * n);

    memset(lo, 0, sizeof(int) * 4 * n);
    memset(hi, 0, sizeof(int) * 4 * n);

    build(1, p, q);
  }

  // O(log(n))
  void increase(int p, int q, int v){ increase(1, p, q, v); }

  // O(log(n))
  void query(int p, int q, vector<int> &ans){ return query(1, p, q, ans); }
};

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < F; j++)
      val[i][j] = 0;
    val[i][1] = 1;
  }

  LazySegmentTree st(0, n - 1);

  int a, b, f;
  vector<int> freq;
  for(int i = 0; i < q; i++){
    scanf("%d%d", &a, &b);
    freq.assign(F, 0);
    st.query(a, b, freq);

    f = 0;
    for(int i = 1; i < F; i++)
      if(freq[f] <= freq[i])
        f = i;

    st.increase(a, b, f);
  }

  for(int i = 0; i < n; i++){
    freq.assign(F, 0);
    st.query(i, i, freq);
    for(int k = 0; k < F; k++)
      if(freq[k] != 0)
        cout << k << endl;
  }

  return 0;
}
