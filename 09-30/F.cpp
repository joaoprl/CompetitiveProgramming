// F. Monkey King

#include <iostream>

using namespace std;

#define N 105

int main(){
  int t, r, c;
  char ch;
  int grid[N][N];
  int grid2[N][N];
  cin >> t;
  while(t--){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        cin >> ch;
        if(ch == 'B')
          grid2[i][j] = grid[i][j] = 1;
        else if(ch == '.')
          grid2[i][j] = grid[i][j] = 0;
        else
          grid2[i][j] = grid[i][j] = -1;
      }
    }
    int sum;
    for(int n = 1; n <= min(r, c); n++){
      for(int i = 0; i + n <= r; i++){
        for(int j = 0; j + n <= c; j++){
          sum = 0;
          for(int k = 0; k < n; k++){
            sum += grid[i + k][j + n - 1] + grid[i + n - 1][j + k];
          }
          grid2[i][j] = max(grid2[i][j], sum);
        }
      }
    }

    cout << grid2[0][0] << "\n";

  }
  return 0;
}
