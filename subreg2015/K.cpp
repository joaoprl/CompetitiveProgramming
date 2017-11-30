// K. Palindrome

#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

#define S 2010

using namespace std;

template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first+r.first,l.second+r.second};
}

pair<int, int> dp[S][S];

pair<int, int> compute(char *str, int i, int j, int *sp){
  if(j < i)
    return make_pair(0, 0);

  if(i == j)
    return (dp[i][j] = make_pair(sp[i], 1));

  if(dp[i][j].first != -1)
    return dp[i][j];

  dp[i][j].first = dp[i][j].second = 0;
  if(str[i] == str[j])
    dp[i][j] = max(dp[i][j], compute(str, i + 1, j - 1, sp) + make_pair(sp[i] + sp[j], 2));

  dp[i][j] = max(dp[i][j], compute(str, i + 1, j, sp));
  dp[i][j] = max(dp[i][j], compute(str, i, j - 1, sp));

  return dp[i][j];
}

int main(){
  char *str = new char[S];
  int *sp = new int[S];
  int n, size, num;

  while(scanf("%s", str) != EOF){

    for(int i = 0; i < S; i++){
      if(str[i] == 0){
        size = i;
        break;
      }
    }

    for(int i = 0; i <= size; i++){
      for(int j = 0; j <= size; j++)
        dp[i][j].first = dp[i][j].second = -1;
      sp[i] = 0;
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &num);
      sp[num - 1] = 1;
    }

    compute(str, 0, size - 1, sp);

    printf("%d\n", dp[0][size - 1].second);

  }

  return 0;
}
