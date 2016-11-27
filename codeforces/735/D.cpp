// D. Taxes

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  if(n == 2)
    cout << "1\n";

  else if(n % 2 == 0)
    cout << "2\n";

  else{
    int sq = sqrt(n) + 1;
    for(int i = 3; i <= sq; i += 2){
      if(n % i == 0){
        sq = sqrt(n - 2) + 1;
        for(int i = 3; i <= sq; i += 2){
          if((n - 2) % i == 0){
            cout << "3\n";
            return 0;
          }
        }
        cout << "2\n";
        return 0;
      }
    }
    cout << "1\n";
  }

  return 0;
}
