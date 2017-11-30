// F. A Ilha

#include <iostream>

#define N 1025

using namespace std;

void wet(int **map, int n, int t, int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= n)
    return;

  if(map[x][y] == 0 || map[x][y] == -1)
    return;

  if(map[x][y] < t){
    map[x][y] = 0;
    wet(map, n, t, x - 1, y);
    wet(map, n, t, x + 1, y);
    wet(map, n, t, x, y - 1);
    wet(map, n, t, x, y + 1);
    return;
  }

  map[x][y] = -1;
}

int main(){
  ios::sync_with_stdio(false);

  int n, t;

  int **map = new int*[N];
  for(int i = 0; i < N; i++)
    map[i] = new int[N];
  while(cin >> n >> t){
    if(n == 0 && t == 0)
      return 0;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> map[i][j];

    for(int i = 0; i < n; i++){
      wet(map, n, t, 0, i);
      wet(map, n, t, n - 1, i);
      wet(map, n, t, i, 0);
      wet(map, n, t, i, n - 1);
    }

    int count = 0;
    cout << endl;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(map[i][j] == -1 || map[i][j] > 0)
          count++;
      }
    }

    cout << count << "\n";
  }

  return 0;
}
