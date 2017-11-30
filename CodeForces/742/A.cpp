// A. Arpa’s hard exam and Mehrdad’s naive cheat

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if(n == 0)
    cout << "1\n";
  else{
    n %= 4;
    if(n == 1)
      cout << "8\n";
    if(n == 2)
      cout << "4\n";
    if(n == 3)
      cout << "2\n";
    if(n == 0)
      cout << "6\n";
  }

  return 0;
}
