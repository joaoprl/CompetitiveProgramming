// C. Alyona and mex

#include <iostream>
#include <climits>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  int l, r;
  int minD = INT_MAX;
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    minD = min(minD, r - l + 1);
  }
  cout << minD << endl;
  for(int i = 0; i < n - 1; i++){
    cout << i % minD << " ";
  }
  cout << (n - 1) % minD << endl;
  return 0;
}
