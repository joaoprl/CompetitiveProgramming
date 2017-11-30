#include <cstdio>
#include <vector>

#define F 9

using namespace std;

void sum(const vector<int> &a, const vector<int> &b, vector<int> &r){
  for(int i = 0; i < F; i++)
    r[i] = a[i] + b[i];
}

class LazySegmentTree{

  LazySegmentTree *left, *right;
  vector<int> freq;
  vector<int> newFreq;
  int lazyF;
  int lo, mid, hi;

  void shift(){
    if(lo != hi){
      left->update(lazyF);
      right->update(lazyF);
    }
    lazyF = 0;
  }

  void update(int v){
    v %= F;
    if(v == 0)
      return;

    lazyF += v;

    newFreq = freq;
    for(int i = 0; i < F; i++)
      freq[i] = newFreq[(i + F - v) % F];
  }

public:
  // O(n)
  LazySegmentTree(int n) : LazySegmentTree(0, n - 1) { }

  // O(q - p)
  LazySegmentTree(int p, int q){
    freq.assign(F, 0);
    newFreq.assign(F, 0);
    lazyF = 0;
    lo = p;
    mid = (p + q) / 2;
    hi = q;

    left = right = NULL;
    if(p != q){
      left = new LazySegmentTree(lo, mid);
      right = new LazySegmentTree(mid + 1, hi);

      sum(left->freq, right->freq, freq);
    }
    else
      freq[1] = 1;
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
    sum(left->freq, right->freq, freq);
  }

  // O(log(n))
  void query(int p, int q, vector<int> &ans){
    if(p == lo && q == hi){
      for(int i = 0; i < F; i++)
        ans[i] += freq[i];
      return;
    }

    shift();

    if(p <= mid)
      left->query(p, min(mid, q), ans);

    if(q >= mid + 1)
      right->query(max(p, mid + 1), q, ans);
  }

  void print(){
    shift();
    if(lo != hi){
      left->print();
      right->print();
    }
    else{
      for(int i = 0; i < F; i++){
        if(freq[i] != 0){
          printf("%d\n", i);
          return;
        }
      }
    }
  }

};
int main(){
  int n, q;
  scanf("%d%d", &n, &q);
  LazySegmentTree st(n);
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

  st.print();

  return 0;
}
