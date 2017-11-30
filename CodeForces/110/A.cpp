// A. Nearly Lucky Number

#include <iostream>

using namespace std;

int main(){
  char c;
  int lucky = 0;
  while(cin >> c && c != '\n'){
    if(c == '4' || c == '7')
      lucky++;
  }

  bool isLucky = lucky > 0;
  while(lucky > 0){
    if(lucky % 10 != 4 && lucky % 10 != 7)
      isLucky = false;
    lucky /= 10;
  }

  if(isLucky)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
