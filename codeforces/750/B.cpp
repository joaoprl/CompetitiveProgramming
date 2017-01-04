// B. New Year and North Pole

#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  int y;
  y = 20000;
  int t;
  string dir;
  bool possible = true;
  for(int i = 0; i < n; i++){
    cin >> t >> dir;

    if(dir == "East" || dir == "West"){
      if(y == 0 || y == 20000)
        possible = false;
    }
    else if(dir == "North"){
      if(y + t > 20000)
        possible = false;
      y += t;
    }
    else if(dir == "South"){
      if(y - t < 0)
        possible = false;
      y -= t;
    }
  }

  if(y == 20000 && possible)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
