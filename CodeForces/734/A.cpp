// A. Anton and Danik

#include <iostream>

using namespace std;

int main(){
  int dif = 0, n;
  char c;
  cin >> n;
  while(n--){
    cin >> c;
    if(c == 'A')
      dif++;
    else
      dif--;
  }
  
  if(dif > 0)
    cout << "Anton\n";
  else if(dif < 0)
    cout << "Danik\n";
  else
    cout << "Friendship\n";

  return 0;
}
