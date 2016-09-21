// E. Vigilância

#include <iostream>

using namespace std;

int getEnergia(){

}

int main(){
  int n, m, c;
  cin >> n >> m >> c;

  int *w = new int[m];
  for(int i = 0; i < m; i++)
    cin >> w[i];

  int **d = new int*[c];

  for(int i = 0; i < c; i++){
    d[i] = new int[4];

    // a(i), b(i), c(i), d(i)
    cin >> d[i][0] >> d[i][1] >> d[i][2] >> d[i][3];
  }



  return 0;
}
