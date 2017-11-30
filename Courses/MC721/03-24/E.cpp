
#include <iostream>

#define N 10
#define FLAG 2000
#define INF 10000

using namespace std;

bool isValid(int *values, int v, int n){
  for(int i = 0; i < n; i++)
    if(values[i] == v)
      return false;
  return true;
}

int compute(int **grid, int n, int *bob, int turn){
  if(turn >= n)
    return 0;

  int total = INF;
  for(int i = 0; i < n; i++){
    if(isValid(bob, i, turn)){
      bob[turn] = i;

      int chosen = grid[turn][bob[turn]];
      total = min(chosen + compute(grid, n, bob, turn + 1), total);
    }
  }
  return total;
}

int main(){
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  int **grid = new int*[N];
  for(int i = 0; i  < N; i++)
    grid[i] = new int[N];

  int *bob = new int[N];

  while(t--){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        cin >> grid[i][j];
    }

    int total = 0;

    cout << compute(grid, n, bob, 0) << endl;
  }

  return 0;
}
