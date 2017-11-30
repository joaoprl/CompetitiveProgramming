// Verbose Lazy Segment Tree

#include <iostream>

#define L 100000

using namespace std;

class LazySegmentTree{

  LazySegmentTree *left, *right;
  int ma;
  int lazySum;
  int lo, mid, hi;

  void shift(){
    if(lo != hi){
      left->update(lazySum);
      right->update(lazySum);
    }
    lazySum = 0;
  }

  void update(int v){
    lazySum += v;
    ma += v;
  }

public:
  // O(n)
  LazySegmentTree(int n) : LazySegmentTree(1, n) { }

  // O(q - p)
  LazySegmentTree(int p, int q){
    ma = 0;
    lazySum = 0;
    lo = p;
    mid = (p + q) / 2;
    hi = q;

    left = right = NULL;
    if(p != q){
      left = new LazySegmentTree(lo, mid);
      right = new LazySegmentTree(mid + 1, hi);

      ma = max(left->ma, right->ma);
    }
  }

  // O(hi - lo)
  ~LazySegmentTree(){
    if(lo != hi){
      delete left;
      delete right;
    }
  }

  // O(log(n))
  void increase(int p, int q, int v){
    if(p == lo && q == hi){
      update(v);
      return;
    }
    shift();

    if(p <= mid)
      left->increase(p, min(mid, q), v);
    if(q >= mid + 1)
      right->increase(max(p, mid + 1), q, v);
    ma = max(left->ma, right->ma);
  }

  // O(log(n))
  int query(int p, int q){
    if(p == lo && q == hi)
      return ma;
    shift();
    int s = 0;
    if(p <= mid)
      s = max(s, left->query(p, min(mid, q)));
    if(q >= mid + 1)
      s = max(s, right->query(max(p, mid + 1), q));
    return s;
  }

};

int main(){
  ios::sync_with_stdio(false);

  LazySegmentTree tr(L);

  int n, l, r;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> l >> r;
    int ql = tr.query(l, l);
    int qr = tr.query(r, r);

    tr.increase(l, l, -ql);
    tr.increase(r, r, -qr);
    if(l + 1 <= r - 1)
      tr.increase(l + 1, r - 1, 1);

    cout << ql + qr << endl;
  }

  return 0;
}
