
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int x, y, z;
  int **map = new int*[n + 1];
  for(int i = 0; i <= n; i++){
    map[i] = new int[n + 1];
    for(int j = 0; j <= n; j++)
      map[i][j] = 0;
  }
  for(int i = 0; i < m; i++){
    cin >> x >> y >> z;
    map[x][y] = map[y][x] = z;
  }

  int total = -1;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      for(int k = j + 1; k <= n; k++){
        if(map[i][j] + map[i][k] + map[j][k] > total){
          total = map[i][j] + map[i][k] + map[j][k];
          x = i;
          y = j;
          z = k;
        }
      }
    }
  }

  cout << x << " " << y << " " << z << endl;

  return 0;
}
