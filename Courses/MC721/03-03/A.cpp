// A. Campo de Minhocas

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  int ma = 0, num, sum;

  int *col = new int[m];
  for(int j = 0; j < m; j++)
    col[j] = 0;

  for(int i = 0; i < n; i++){
    sum = 0;
    for(int j = 0; j < m; j++){
      cin >> num;
      sum += num;
      col[j] += num;
    }
    ma = max(ma, sum);
  }

  for(int j = 0; j < m; j++)
    ma = max(ma, col[j]);

  cout << ma << endl;

  return 0;
}
