
#include <cstdio>
#include <vector>
#include <iostream>

#define N 25
#define M 25
#define T 2010

using namespace std;

class App{
public:
  int x, y, t;
  App(int x, int y, int t){
    this-> x = x;
    this-> y = y;
    this-> t = t;
  }
  App(){

  }
};

int ***map;

int compute(App *app, int x, int y, int t, int k, int size){
  if(k >= size)
    return 0;

  if(map[x][y][t] != -1)
    return map[x][y][t];

  if(max(abs(x - app[k].x), abs(y - app[k].y)) <= app[k].t - t)
    return (map[x][y][t] = max(compute(app, x, y, t, k + 1, size), compute(app, app[k].x, app[k].y, app[k].t, k + 1, size) + 1));
  else
    return (map[x][y][t] = compute(app, x, y, t, k + 1, size));
}

int main(){
  int n, m, k;
  App *app = new App[T];
  map = new int**[N];
  for(int i = 0; i < N; i++){
    map[i] = new int*[M];
    for(int j = 0; j < M; j++){
      map[i][j] = new int[T];
    }
  }
  while(scanf("%d %d %d", &n, &m, &k) && (n != 0 || m != 0 || k != 0)){

    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= m; j++)
        for(int b = 0; b <= 2 * k; b++)
          map[i][j][b] = -1;

    int x, y, t;

    for(int i = 0; i < k; i++){
      scanf("%d %d %d", &x, &y, &t);
      app[i] = App(x, y, t);
    }

    scanf("%d %d", &x, &y);
    cout << compute(app, x, y, 0, 0, k) << endl;
  }


  return 0;
}
