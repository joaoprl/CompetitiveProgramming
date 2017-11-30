#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class LazySegmentTree{

  LazySegmentTree *left, *right;
  int values;
  vector<int> lazyVal;
  int lo, mid, hi;
  int countSize;

  void shift(){
    if(lo != hi && lazyVal.size() != 0){
      left->update(lazyVal);
      right->update(lazyVal);

      if(left->values != -1 && right->values != -1)
        values = 0;

    }
    lazyVal.clear();
  }

  void update(const vector<int> &v){
    if(values != -1)
      return;

    lazyVal.insert(lazyVal.end(), v.begin(), v.end());

    if(lo == hi){
      if(countSize + v.size() >= lo)
        values = v[lo - countSize  - 1];

      countSize += v.size();
      lazyVal.clear();
    }
  }

public:
  // O(n)
  LazySegmentTree(int n) : LazySegmentTree(1, n) { }

  // O(q - p)
  LazySegmentTree(int p, int q){
    lo = p;
    mid = (p + q) / 2;
    hi = q;
    countSize = 0;
    values = -1;

    left = right = NULL;
    if(p != q){
      left = new LazySegmentTree(lo, mid);
      right = new LazySegmentTree(mid + 1, hi);
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
  void insert(int p, int q, int v){
    if(values != -1)
      return;

    if(p == lo && q == hi){
      update({v});
      return;
    }
    shift();

    if(p <= mid)
      left->insert(p, min(mid, q), v);
    if(q >= mid + 1)
      right->insert(max(p, mid + 1), q, v);

    if(left->values != -1 && right->values != -1){
      values = 0;
      lazyVal.clear();
    }
  }

  // O(log(n))
  int query(int p, int q){
    if(p == lo && q == hi)
      return values;
    shift();
    int s = -1;
    if(p <= mid)
      s = left->query(p, min(mid, q));
    if(q >= mid + 1)
      s = right->query(max(p, mid + 1), q);
    return s;
  }

};


int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<int> ns(n + 2, 0);
  int a, b;
  LazySegmentTree ltr(n);
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    ltr.insert(a, b, i + 1);
  }

  for(int i = 1; i <= n; i++){
    cout << ltr.query(i, i) << " ";
  }
  cout << endl;

  return 0;
}
