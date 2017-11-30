// I. The Lazy Lumberjacks

#include <iostream>

using namespace std;

int main(){
  int n, a, b, c;
  cin >> n;

  while(n--){
    cin >> a >> b >> c;
    if(a + b > c && a + c > b && b + c > a)
      cout << "OK\n";
    else
      cout << "Wrong!!\n";
  }

  return 0;
}
