// H. Longest Run on a Snowboard

#include <iostream>
#include <climits>

#define C 102
#define R 102
#define INF 10000

using namespace std;

int maximize(int i, int j, int **edges, int **grid){
  if(edges[i][j] != -1)
    return edges[i][j];

  edges[i][j] = 0;
  if(grid[i][j] > grid[i - 1][j])
    edges[i][j] = max(edges[i][j], maximize(i - 1, j, edges, grid) + 1);
  if(grid[i][j] > grid[i + 1][j])
    edges[i][j] = max(edges[i][j], maximize(i + 1, j, edges, grid) + 1);
  if(grid[i][j] > grid[i][j - 1])
    edges[i][j] = max(edges[i][j], maximize(i, j - 1, edges, grid) + 1);
  if(grid[i][j] > grid[i][j + 1])
    edges[i][j] = max(edges[i][j], maximize(i, j + 1, edges, grid) + 1);

  return edges[i][j];
}

int main(){
  int t;
  cin >> t;

  int **grid = new int*[C];
  for(int i = 0; i < C; i++)
    grid[i] = new int[R];
  int **edges = new int*[C];
  for(int i = 0; i < C; i++)
    edges[i] = new int[R];

  string name;
  int c, r;
  while(t--){
    cin >> name >> c >> r;

    for(int i = 1; i <= c; i++){
      for(int j = 1; j <= r; j++){
        cin >> grid[i][j];
        edges[i][j] = -1;
      }
      grid[i][0] = grid[i][r + 1] = INF;
    }
    for(int j = 1; j <= r; j++)
      grid[0][j] = grid[c + 1][j] = INF;
    int m = 0;
    for(int i = 1; i <= c; i++){
      for(int j = 1; j <= r; j++){
        m = max(m, maximize(i, j, edges, grid));
      }
    }

    cout << name << ": " << m + 1 << "\n";
  }
  return 0;
}
