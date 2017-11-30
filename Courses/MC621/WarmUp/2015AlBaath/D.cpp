// D. The Three Kings of Asgard

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    int n;
    cin >> n;

    if(n % 8 == 0){
      printf("%d %d %d\n", 11 * n / 8, 7 * n / 8, 3 * n / 4);
    }
    else
      cout << "Impossible\n";
    
  }
  return 0;
}
