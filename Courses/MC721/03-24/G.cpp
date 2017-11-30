
#include <iostream>
#include <vector>
#include <algorithm>

#define N 100010
#define K 100010

using namespace std;

class Tree{
public:
  Tree(){
  }
  int initialize(int *seq, int n){
    initialize(seq, 0, n);
  }

  int initialize(int *seq, int a, int b){
    begin = a;
    end = b - 1;

    if(b - a == 1){
      value = seq[a];
      sep = b;
      size = 1;
    }

    if(b - a > 1){
      size = b - a;
      sep = size / 2 + a;

      left = new Tree();
      right = new Tree();

      value = left->initialize(seq, a, sep) + right->initialize(seq, sep, b);
    }

    return value;
  }

  void addAt(int p, int n){
    if(p < begin || p > end)
      return;

    value += n;

    if(size > 1){
      right->addAt(p, n);
      left->addAt(p, n);
    }
  }

  int countSeq(int i, int j){
    if(j < begin || i > end)
      return 0;
    if(i <= begin && j >= end)
      return value;

    int total = 0;
    total = left->countSeq(i, j);
    total += right->countSeq(i, j);

    return total;
  }

private:
  int value, begin, end;
  int size, sep;
  Tree *left, *right;

};

int main(){
  int n, k;

  int *negatives = new int[N];
  int *zeroes = new int[N];
  int *seq = new int[N];
  while(cin >> n >> k){

    int num;
    for(int i = 0; i < n; i++){
      cin >> num;

      if(num == 0)
        zeroes[i] = 1;
      else
        zeroes[i] = 0;

      if(num < 0)
        negatives[i] = 1;
      else
        negatives[i] = 0;

      seq[i] = num;
    }

    Tree zeroesTree, negativesTree;
    zeroesTree.initialize(zeroes, n);
    negativesTree.initialize(negatives, n);

    char c;
    int x, y;
    for(int i = 0; i < k; i++){
      cin >> c >> x >> y;

      if(c == 'C'){
        x--;

        if(seq[x] == 0 && y != 0)
          zeroesTree.addAt(x, -1);
        if(seq[x] != 0 && y == 0)
          zeroesTree.addAt(x, 1);

        if(seq[x] < 0 && y >= 0)
          negativesTree.addAt(x, -1);
        if(seq[x] >= 0 && y < 0)
          negativesTree.addAt(x, 1);

        seq[x] = y;
      }
      else if(c == 'P'){
        x--; y--;
        if(zeroesTree.countSeq(x, y) > 0)
          cout << "0";
        else if(negativesTree.countSeq(x, y) % 2 != 0)
          cout << "-";
        else
          cout << "+";
      }

    }
    cout << endl;
  }

  return 0;
}
