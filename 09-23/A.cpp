// A. 05-2 Rendezvous

#include <iostream>
#include <climits>

#define N 25
#define M 250
#define INF 100000

using namespace std;

void floydWarshall(int **dist, int n){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main(){
  string *names = new string[N];

  int n, m, x, y, p, k;

  int *dist = new int[N];

  int **mat;
  mat = new int*[N];
  for(int i = 0; i < N; i++)
    mat[i] = new int[N];

  k = 1;
  cin >> n >> m;
  while(n != 0){
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
        mat[i][j] = INF;
      }
      mat[i][i] = 0;
      dist[i] = 0;
    }

    for(int i = 1; i <= n; i++){
      cin >> names[i];
    }

    for(int i = 0; i < m; i++){
      cin >> x >> y >> p;
      mat[x][y] = p;
      mat[y][x] = p;
    }

    floydWarshall(mat, n);

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(mat[i][j] == INF)
          dist[i] = INF;
        else if(dist[i] != INF)
          dist[i] += mat[i][j];
      }
    }
    x = 1;
    for(int i = 1; i <= n; i++){
      if(dist[i] < dist[x])
        x = i;
    }

    cout << "Case #" << k++ << " : " << names[x] << "\n";
    cin >> n >> m;
  }

  return 0;
}
