
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int p;
  cin >> p;
  int n = p / 2;
  int c = 1;

  int count = 0;
  do{
    if(c <= n)
      c = 2 * c;
    else
      c = 2 * c - 2 * n - 1;
    count++;
  }while(c != 1);

  cout << count << endl;

  return 0;
}
