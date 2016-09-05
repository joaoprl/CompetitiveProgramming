// J. The Check of the Point

#include <iostream>

using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  s[0] -= '0';
  s[1] -= '0';
  s[3] -= '0';
  s[4] -= '0';

  t[0] -= '0';
  t[1] -= '0';
  t[3] -= '0';
  t[4] -= '0';

  int h = 10 * s[0] + s[1];
  int min = 10 * s[3] + s[4];

  min = min - 10 * t[3] - t[4];
  if(min < 0){
    min -= 60;
    h--;
  }
  min = (min + 120) % 60;

  h = h - 10 * t[0] - t[1];

  h = (h + 48) % 24;

  if(h < 10)
    cout << 0;
  cout << h << ":";
  if(min < 10)
    cout << 0;
  cout << min << "\n";

  return 0;
}
