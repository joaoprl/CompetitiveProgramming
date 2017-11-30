// C. Star sky

#include <iostream>

#define X 101

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, q, c;
  cin >> n >> q >> c;

  int *x, *y, *s;
  x = new int[n];
  y = new int[n];
  s = new int[n];


  int ***sky = new int**[X];
  for(int i = 0; i < X; i++){
    sky[i] = new int*[X];
    for(int j = 0; j < X; j++){
      sky[i][j] = new int[c + 1];
      for(int k = 0; k <= c; k++)
        sky[i][j][k] = 0;
    }
  }

  int xi, yi, si;
  for(int i = 0; i < n; i++){
    cin >> xi >> yi >> si;
    sky[xi][yi][si]++;
  }

  for(int i = 1; i < X; i++){
    for(int j = 1; j < X; j++){
      for(int k = 0; k <= c; k++){
        sky[i][j][k] += sky[i][j - 1][k] + sky[i - 1][j][k] - sky[i - 1][j - 1][k];
      }
    }
  }

  int t, x1, y1, x2, y2, br;
  for(int i = 0; i < q; i++){
    cin >> t >> x1 >> y1 >> x2 >> y2;
    br = 0;

    for(int k = 0; k <= c; k++){
      br += (sky[x2][y2][k] - sky[x1 - 1][y2][k] - sky[x2][y1 - 1][k] + sky[x1 - 1][y1 - 1][k]) * ((k + t) % (c + 1));
    }

    cout << br << "\n";
  }

  return 0;
}
