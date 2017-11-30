// B. Spotlights

#include <cstdio>

using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  int **plan = new int*[n + 2];
  for(int i = 0; i < n + 2; i++){
    plan[i] = new int[m + 2];
  }

  for(int i = 0; i < n + 2; i++)
    plan[i][0] = plan[i][m + 1] = 0;
  for(int j = 0; j < m + 2; j++)
    plan[0][j] = plan[n + 1][j] = 0;

  int v;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf("%d", &v);
      plan[i][j] = v;

      plan[i][m + 1] += v;
      plan[n + 1][j] += v;
    }
  }

  int good = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(plan[i][j] == 0){
        if(plan[0][j] > 0)
          good++;
        if(plan[n + 1][j] > plan[0][j])
          good++;
        if(plan[i][0] > 0)
          good++;
        if(plan[i][m + 1] > plan[i][0])
          good++;
      }
      if(plan[i][j] == 1){
        plan[0][j]++;
        plan[i][0]++;
      }
    }
  }

  printf("%d\n", good);

  return 0;
}
