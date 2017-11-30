// Verbose Lazy Segment Tree

#include <iostream>

using namespace std;

typedef long long ll;

class LazySegmentTree{

  LazySegmentTree *left, *right;
  ll sum;
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
  }

public:
  // O(n)
  LazySegmentTree(int n) : LazySegmentTree(1, n) { }

  // O(q - p)
  LazySegmentTree(int p, int q){
    sum = 0;
    lazySum = 0;
    lo = p;
    mid = (p + q) / 2;
    hi = q;

    left = right = NULL;
    if(p != q){
      left = new LazySegmentTree(lo, mid);
      right = new LazySegmentTree(mid + 1, hi);

      sum = left->sum + right->sum;
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

};

