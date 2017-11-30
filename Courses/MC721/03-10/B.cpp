// B. Dobradura 

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, i = 1;
  while(cin >> n && n >= 0){
    cout << "Teste " << i++ << endl;  
    cout << (int)pow(pow(2, n) + 1, 2) << endl << endl;
  }
  return 0;
}
