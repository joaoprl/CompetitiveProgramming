
#include <iostream>

using namespace std;

const int N = 310;
const int INF = 1000000000;

int count(int lu[N][N], int x1, int y1, int x2, int y2){
  int a = lu[x2][y2];
  int b = (x1 > 0 ? lu[x1 - 1][y2] : 0);
  int c = (y1 > 0 ? lu[x2][y1 - 1] : 0);
  int d = (x1 > 0 && y1 > 0 ? lu[x1 - 1][y1 - 1] : 0);

  return a - b - c + d;
}

int main(){
  ios::sync_with_stdio(false);
  int r, c, k, map[N][N], lu[N][N];
  char ch;
  while(cin >> r >> c >> k && (r != 0 || c != 0 || k != 0)){
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        cin >> ch;
        map[i][j] = (ch == '.' ? 1 : 0);
      }
    }

    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        int a = (i > 0 && j > 0 ? lu[i - 1][j - 1] : 0);
        int b = (i > 0 ? lu[i - 1][j] : 0);
        int c = (j > 0 ? lu[i][j - 1] : 0);

        lu[i][j] = b + c - a + map[i][j];
      }
    }

    int ar = INF;
    for(int a = 0; a < r; a++){
      for(int b = a; b < r; b++){
        int c1 = 0, c2 = 0;
        while(c2 < c){
          int curr = count(lu, a, c1, b, c2);
          if(curr < k)
            c2++;
          else{
            ar = min(ar, (c2 - c1 + 1) * (b - a + 1));
            c1++;
          }
        }
      }
    }
    cout << ar << endl;
  }

  return 0;
}
