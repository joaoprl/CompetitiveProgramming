// B. Feynman

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;


  while(cin >> n && n != 0){
    int out = 0;
    for(int i = 1; i <= n; i++)
      out += i * i;
    cout << out << endl;
  }

  return 0;
}
