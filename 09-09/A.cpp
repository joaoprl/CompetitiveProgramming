// A. Mail Stamps
// Use C++11

#include <cstdio>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void sort(int &mi, int &ma){
  int a = mi, b = ma;
  mi = min(a, b);
  ma = max(a, b);
}

int main(){
  int n, a, b, x;
  unordered_map< int, vector<int> > m;
  list<int> seq;
  scanf("%d", &n);

  while(n--){
    scanf("%d%d", &a, &b);
    m[a].push_back(b);
    m[b].push_back(a);
  }

  seq.push_back(a);
  x = m[a][0];
  seq.push_back(x);
  while(m[x].size() > 1){
    b = x;
    if(m[x][0] == a)
      x = m[x][1];
    else x = m[x][0];
    a = b;
    seq.push_back(x);
  }

  a = seq.front();
  if(m[a].size() > 1){
    x = m[a][1];
    seq.push_front(x);
    while(m[x].size() > 1){
      b = x;
      if(m[x][0] == a)
        x = m[x][1];
      else x = m[x][0];
      a = b;
      seq.push_front(x);
    }
  }

  while(seq.size() > 1){
    printf("%d ", seq.front());
    seq.pop_front();
  }
  printf("%d\n", seq.front());
  seq.pop_front();

  return 0;
}
