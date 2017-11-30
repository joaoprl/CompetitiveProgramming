
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int mat[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      mat[i][j] = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j && k > 0){
        mat[i][j] = 1;
        k--;
      }
      else if(k > 1 && mat[i][j] == 0){
        mat[i][j] = mat[j][i] = 1;
        k -= 2;
      }
    }
  }

  if(k > 0)
    cout << -1 << endl;
  else{
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  }


  return 0;
}
