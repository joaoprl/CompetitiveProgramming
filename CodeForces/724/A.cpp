// A. Checking the Calendar

#include <iostream>

using namespace std;

int main(){
  string week[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
  string first, second;
  int f, s;
  cin >> first >> second;

  for(int i = 0; i < 7; i++){
    if(first == week[i])
      f = i;
    if(second == week[i])
      s = i;
  }
  if((31 + f) % 7 == s || (30 + f) % 7 == s || (28 + f) % 7 == s)
    cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
