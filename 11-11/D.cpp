// D. Picos do Átlas

#include <iostream>
#include <climits>

#define S 1002

using namespace std;

int main(){
  int **map = new int*[S];
  for(int i = 0; i < S; i++){
    map[i] = new int[S];
  }

  int n, m, h;
  while(cin >> n >> m){
    for(int i = 0; i <= n + 1; i++)
      map[i][0] = map[i][m + 1] = INT_MIN;
    for(int j = 0; j <= m + 1; j++)
      map[0][j] = map[n + 1][j] = INT_MIN;

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        cin >> h;
        map[i][j] = h;
      }
    }
    bool isPeakless = true;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        bool isPeak = true;
        for(int x = i - 1; x <= i + 1; x++){
          for(int y = j - 1; y <= j + 1; y++){
            if(x != i || y != j){
              if(map[x][y] >= map[i][j])
                isPeak = false;
            }
          }
        }
        if(isPeak){
          cout << i << " " << j << "\n";
          isPeakless = false;
        }
      }
    }
    if(isPeakless)
      cout << "-1\n";
    cout << "\n";
  }

  return 0;
}
