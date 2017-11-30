
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n && n != 0){
    int p = pow(n, 0.5);
    cout << 1;
    for(int i = 2; i <= p; i++){
      cout << " " << i * i;
    }
    cout << endl;
  }

  return 0;
}
