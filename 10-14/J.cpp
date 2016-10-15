// J. Philosophers Stone

#include <iostream>
#include <climits>

#define MAX_SIZE 101

using namespace std;

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
  int m = 0;
  for(int j = 0; j < w; j++)
    m = max(m, maximizePD(pd, grid, h, w, 0, j));

  return m;
}

int main(){
  int t, h, w;

  int **grid = new int*[MAX_SIZE];
  for(int i = 0; i < MAX_SIZE; i++)
    grid[i] = new int[MAX_SIZE];

  int **pd = new int*[MAX_SIZE];
  for(int i = 0; i < MAX_SIZE; i++)
    pd[i] = new int[MAX_SIZE];

  cin >> t;
  while(t--){
    cin >> h >> w;

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> grid[i][j];
        pd[i][j] = -1;
      }
    }
    cout << maximize(pd, grid, h, w) << "\n";
  }

  return 0;
}
