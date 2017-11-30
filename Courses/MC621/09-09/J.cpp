// J. Factorial

#include <iostream>

using namespace std;

int main(){
  int n, k, f;

  while(cin >> n){
    k = 0;
    f = 40320;
    while(n >= f){ // 8!
      n -= f;
      k++;
    }
    f = 5040;
    while(n >= f){ // 7!

      n -= f;
      k++;
    }
    f = 720;
    while(n >= f){ // 6!
      n -= f;
      k++;
    }
    f = 120;
    while(n >= f){ // 5!
      n -= f;
      k++;
    }
    f = 24;
    while(n >= f){ // 4!
      n -= f;
      k++;
    }
    f = 6;
    while(n >= f){ // 3!
      n -= f;
      k++;
    }
    f = 2;
    while(n >= f){ // 2!
      n -= f;
      k++;
    }
    f = 1;
    while(n >= f){ // 1!
      n -= f;
      k++;
    }

    cout << k << "\n";
  }

  return 0;
}
