// B. Hongcow Solves A Puzzle

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  char** grid = new char*[n];
  int x, y, r, b;
  x = y = 0;
  r = b = -1;

  bool unset = true;
  for(int i = 0; i < n; i++){
    grid[i] = new char[m];
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
      if(grid[i][j] == 'X'){
        if(unset){
          unset = false;
          x = i;
          y = j;
        }
        b = max(b, i);
        r = max(r, j);
      }
    }
  }
  
  bool p = true;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i >= x && i <= b && j >= y && j <= r){
        if(grid[i][j] != 'X')
          p = false;
      }


      else{
        if(grid[i][j] != '.')
          p = false;
      }



    }
  }

  if(p)
    cout << "YES\n";
  else
    cout << "NO\n";


  return 0;
}
