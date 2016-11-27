// C. Tennis Championship

#include <iostream>
#include <cmath>

using namespace std;



int main(){
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long n1 = 1;
  long long n2 = 2;
  int i;
  for(i = 1; n2 < n; i++){
    n2 = n1 + n2;
    n1 = n2 - n1;
  }
  if(n2 == n)
    cout << i << endl;
  else
    cout << i - 1 << endl;

  return 0;
}
