// C. Contaminação

#include <iostream>
#include <cstdio>

using namespace std;
#define N 100
#define M 100

void contaminate(char **map, int x, int y){
  if(map[x][y] == 'A'){
    map[x][y] = 'T';
    contaminate(map, x - 1, y);
    contaminate(map, x + 1, y);
    contaminate(map, x, y + 1);
    contaminate(map, x, y - 1);
  }
}

int main(){
  int n, m;
  char **map;
  map = new char*[N];
  for(int i = 0; i < N; i++)
    map[i] = new char[M];

  cin >> n >> m;

  while(n != 0 && m != 0){
    for(int j = 0; j <= m + 1; j++)
      map[0][j] = map[n + 1][j] = 'X';
    for(int i = 1; i <= n; i++){
      map[i][0] = map[i][m + 1] = 'X';
      for(int j = 1; j <= m; j++)
        cin >> map[i][j];
    }
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        if(map[i][j] == 'T'){
          contaminate(map, i - 1, j);
          contaminate(map, i + 1, j);
          contaminate(map, i, j + 1);
          contaminate(map, i, j - 1);
        }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++)
        cout << map[i][j];
      cout << "\n";
    }
    cout << "\n";





    cin >> n >> m;
  }

  for(int i = 0; i < N; i++)
    delete[] map[i];
  delete[] map;
  return 0;
}
