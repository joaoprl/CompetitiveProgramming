
#include <iostream>


using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int old = -1, num;
  int acc = 0;
  for(int i = 0; i < n; i++){
    cin >> num;
    if(old == -1)
      old = num;
    acc += min(num - old, 10);
    old = num;

  }

  cout << acc + 10 << endl;


  return 0;
}
