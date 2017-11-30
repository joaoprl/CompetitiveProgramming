
#include <iostream>

using namespace std;

class Tree{
  Tree *zero, *one;
  int number;
  const int START = 31;

  void insert(int num, int n, int pos){
    if(n < 0){
      if(number == -1)
        number = pos;
      return;
    }

    if(((num >> n) & 1) != 0){
      if(one == NULL)
        one = new Tree();

      one->insert(num, n - 1, pos);
    }
    else{
      if(zero == NULL)
        zero = new Tree();

      zero->insert(num, n - 1, pos);
    }
  }

  int query(int num, int n){
    if(n < 0)
      return number;

    if(((num >> n) & 1) == 0){
      if(one == NULL)
        return zero->query(num, n - 1);

      return one->query(num, n - 1);
    }
    else{
      if(zero == NULL)
        return one->query(num, n - 1);

      return zero->query(num, n - 1);
    }
  }

public:
  Tree(){
    zero = one = NULL;
    number = -1;
  }

  ~Tree(){
    if(one != NULL)
      delete one;
    if(zero != NULL)
      delete zero;
  }

  void insert(int num, int pos){
    insert(num, START, pos);
  }

  int query(int num){
    return query(num, START);
  }
};

int main(){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for(int c = 0; c < t; c++){
    int n, q, num;
    cin >> n >> q;
    Tree tr;

    for(int i = 0; i < n; i++){
      cin >> num;
      tr.insert(num, i + 1);
    }

    for(int i = 0; i < q; i++){
      cin >> num;
      cout << tr.query(num) << endl;
    }
    cout << endl;
  }

  return 0;
}
