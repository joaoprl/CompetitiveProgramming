// A. New Year and Hurry

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  k = 240 - k;

  int count = 0;
  for(int i = 1; i <= n; i++){
    if(5 * i <= k){
      k -= 5 * i;
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
