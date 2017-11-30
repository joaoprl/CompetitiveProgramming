
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int acc = 0, num;
  for(int i = 0; i < n; i++){
    cin >> num;
    acc += num;
  }
  int m, l, r, ma = -1;
  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> l >> r;
    if(acc <= l && ma == -1)
      ma = l;
    else if(acc <= r && ma == -1)
      ma = acc;
  }

  cout << ma << endl;

  return 0;
}
