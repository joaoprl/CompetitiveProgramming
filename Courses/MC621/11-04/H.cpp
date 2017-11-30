// H. Front

#include <cstdio>
#include <algorithm>

using namespace std;

bool pairComp(pair<int, int> i, pair<int, int> j){
  return i.first < j.first || (i.first == j.first && i.second < j.second);
}

int main(){
  int n;
  scanf("%d", &n);
  pair<int, int> *coor = new pair<int, int>[n];

  for(int i = 0; i < n; i++)
    scanf("%d %d", &(coor[i].first), &(coor[i].second));

  sort(coor, coor + n, pairComp);

  int count = 0, max = -1;
  for(int i = n - 1; i >= 0; i--){
    if(coor[i].second > max){
      count++;
      max = coor[i].second;
    }
  }

  printf("%d\n", count);

  return 0;
}
