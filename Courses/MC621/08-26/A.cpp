// A. Beat the Spread!

#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  while(n > 0){
    int s, d;
    cin >> s >> d;

    if(s >= d && (s + d) % 2 == 0)
      cout << (s + d) / 2 << " " << (s - d) / 2 << "\n";
    else
      cout << "impossible\n";

    n--;
  }
  
  return 0;
}
