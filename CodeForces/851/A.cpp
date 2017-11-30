// A. Arpa and research in Mexican Wave

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, k, t;
  cin >> n >> k >> t;
  cout << min(min(t, k), n + k - t) << endl;

  return 0;
}
