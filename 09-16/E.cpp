// E. Modular Fibonnacci

#include <iostream>

#define M 21

using namespace std;

int main(){
  int n, m;

  int f1, f2;

  while(cin >> n >> m){
    m = 1 << m;

    if(n == 0)
      cout << "0\n";
    else if(n == 1)
      cout << "1\n";

    else{
      f1 = 0;
      f2 = 1;

      int k = 0;
      do{
        f2 = f1 + f2;
        f1 = f2 - f1;

        f2 %= m;
        f1 %= m;
        k++;
        if(k + 1 == n)
          break;
      }while(f1 != 0 || f2 != 1);

      if(k + 1 == n){
        cout << f2 << "\n";
      }
      else{
        n = n % k;

        if(n == 0)
        cout << "0\n";

        else{
          f1 = 0;
          f2 = 1;
          for(int i = 1; i < n; i++){
            f2 = f1 + f2;
            f1 = f2 - f1;

            f2 %= m;
            f1 %= m;
          }

          cout << f2 << "\n";
        }
      }
    }
  }
  return 0;
}
