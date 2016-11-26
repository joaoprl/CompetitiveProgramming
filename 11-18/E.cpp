// E. Farm Robot

#include <iostream>

using namespace std;

int main(){
  int n, c, s, com;
  cin >> n >> c >> s;
  int pos = 0, count = 0;

  if(pos == s - 1)
    count++;

  while(c--){
    cin >> com;
    if(com == 1)
      pos = (pos + 1) % n;

    else if(com == -1)
      pos = (pos + n - 1) % n;

    if(pos == s - 1)
      count++;
  }

  cout << count << endl;

  return 0;
}
