
#include <iostream>

using namespace std;

class tree{
public:
  int min, max;
  int p;

  tree *l;
  tree *r;

  tree(int min, int max){
    this->min = min;
    this->max = max;

    if(min != max){
      l = new tree(min, (min + max) / 2);
      r = new tree((min + max) / 2 + 1, max);
      p = -1;
    }
    else{
      p = min;
      l = NULL;
      r = NULL;
    }
  }

  int query(int n){
    if(min <= n && max >= n){
      if(p != -1)
        return p;

      if(n <= (min + max) / 2)
        return l->query(n);
      return r->query(n);
    }
    return -1;
  }

  void set(int a, int b, int p){
    if(a > max || b < min)
      return;

    if((a <= min && b >= max) || this->p != -1){
      this->p = p;
      return;
    }

    l->set(a, b, p);
    r->set(a, b, p);

    if(l->p == r->p)
      this->p = l->p;
  }
};

int main(){
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  tree tr = tree(1, n);

  int t, x, y;
  for(int i = 0; i < q; i++){
    cin >> t >> x >> y;

    if(t == 1){
      while(tr.query(x) != x)
        x = tr.query(x);

      while(tr.query(y) != y)
        y = tr.query(y);

      tr.set(x, x, y);
    }
    else if(t == 2){
      int y1 = y;
      int x1 = x;
      while(tr.query(y) != y)
        y = tr.query(y);

      while(tr.query(x) != x)
        x = tr.query(x);

      tr.set(x, x, y);
      tr.set(x1, y1, y);

    }
    else if(t == 3){
      while(tr.query(x) != x)
        x = tr.query(x);

      while(tr.query(y) != y)
        y = tr.query(y);

      if(x != y)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }

  return 0;
}
