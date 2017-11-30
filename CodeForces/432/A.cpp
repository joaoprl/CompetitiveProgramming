// A. Choosing Teams

#include <iostream>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  int count = 0, num;
  for(int i = 0; i < n; i++){
    cin >> num;
    if(num + k <= 5)
      count++;
  }
  cout << count / 3 << "\n";

  return 0;
}
