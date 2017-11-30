
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int count = 0;
  for(int i = 0; i < n; i++){
    bool ev = true;
    for(int j = 0; j < m; j++){
      int num;
      cin >> num;
      if(num == 0)
        ev = false;
    }
    if(ev)
      count++;
  }

  cout << count << endl;


  return 0;
}
