
#include <iostream>

#define N 100
#define INF 1000000000

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  int **map = new int*[N];
  for(int i = 0; i < N; i++)
    map[i] = new int[N];

  for(int y = 1; y <= t; y++){
    int n, r;
    cin >> n >> r;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        map[i][j] = INF;
      map[i][i] = 0;
    }

    int u, v;
    for(int i = 0; i < r; i++){
      cin >> u >> v;
      map[u][v] = 1;
      map[v][u] = 1;
    }

    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(map[i][j] > map[i][k] + map[k][j])
            map[i][j] = map[i][k] + map[k][j];
        }
      }
    }

    int s, d;
    cin >> s >> d;
    int m = 0;
    for(int i = 0; i < n; i++)
      m = max(m, map[s][i] + map[i][d]);
    
    cout << "Case " << y << ": ";
    cout << m << endl;
  }

  return 0;
}
