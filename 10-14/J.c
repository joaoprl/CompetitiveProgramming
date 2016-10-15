// J. Philosophers Stone

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 101
#define max(x, y) (x > y)? x : y


int maximizePD(int **pd, int **grid, int h, int w, int i, int j){
  if(i == h)
    return 0;
  if(j < 0 || j >= w)
    return INT_MIN;
  if(pd[i][j] != -1)
    return pd[i][j];

  int m = 0;
  m = max(m, maximizePD(pd, grid, h, w, i + 1, j - 1));
  m = max(m, maximizePD(pd, grid, h, w, i + 1, j));
  m = max(m, maximizePD(pd, grid, h, w, i + 1, j + 1));

  return (pd[i][j] = m + grid[i][j]);
}

int maximize(int **pd, int **grid, int h, int w){
  int m = 0, j;
  for(j = 0; j < w; j++)
    m = max(m, maximizePD(pd, grid, h, w, 0, j));

  return m;
}

int main(){
  int t, h, w, i, j;

  int **grid = (int**)malloc(sizeof(int*) * MAX_SIZE);
  for(i = 0; i < MAX_SIZE; i++)
    grid[i] = (int*)malloc(sizeof(int) * MAX_SIZE);

  int **pd = (int**)malloc(sizeof(int*) * MAX_SIZE);
  for(i = 0; i < MAX_SIZE; i++)
    pd[i] = (int*)malloc(sizeof(int) * MAX_SIZE);

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &h, &w);

    for(i = 0; i < h; i++){
      for(j = 0; j < w; j++){
        scanf("%d", &grid[i][j]);
        pd[i][j] = -1;
      }
    }
    printf("%d\n", maximize(pd, grid, h, w));
  }

  return 0;
}
