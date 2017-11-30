// F. Two Buttons

#include <iostream>

using namespace std;

int main(){
  int n, m, t, x = 0;
  cin >> n >> m;

  while(n != m){
    t = m;
    while(t > n)
	t = (t + 1) / 2;
    
    if(t == n)
      n *= 2;
    else n--;
    
    x++;
  }

  cout << x << "\n";
  
  return 0;
}
