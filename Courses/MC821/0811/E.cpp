
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, m;
  while(cin >> n >> m && (n != -1 || m != -1)){
    long long c, count = 0;
    for(int i = 0; i < n; i++){
      cin >> c;
      count += c * (n - i);
    }
    cout << count * m << endl;
  }
  return 0;
}
