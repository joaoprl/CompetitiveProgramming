// A.  Hongcow Learns the Cyclic Shift

#include <iostream>
#include <cstring>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  string s, sc;
  cin >> s;
  int l = s.length();
  sc = s + s;

  int count = 1;
  for(int i = 1; i < l; i++){
    if(sc.compare(i, l, s) == 0)
      break;
    count++;
  }

  cout << count << endl;
  
  return 0;
}
