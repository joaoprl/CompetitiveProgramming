// A. Bachgold Problem

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int k;
  cin >> k;
  int n = k / 2;
  cout << n << "\n";
  for(int i = 0; i < n - 1; i++){
    cout << "2 ";
  }
  if(k % 2 == 0)
    cout << 2 << endl;
  else
    cout << 3 << endl;

  return 0;
}
