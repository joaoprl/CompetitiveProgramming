// F. black-white

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    int n, w, b;
    cin >> n >> w >> b;

    if((b - w) % 2 != 0)
      cout << "Mikael\n";
    else
      cout << "Steven\n";
    
  }
  return 0;
}
