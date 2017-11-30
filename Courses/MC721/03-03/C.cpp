// C. Consecutive Integers

#include <iostream>
#include <cmath>

using namespace std;

bool isPot2(int n){
  int i = 1;
  while(n > i){
    i *= 2;
  }
  if(i == n)
    return true;
  return false;
}

int main(){
  ios::sync_with_stdio(false);

  long long n;
  while(cin >> n && n != -1){
    long long a, b;

    if(isPot2(n))
      a = n, b = n;

    else{
      a = 1;
      b = (long long)(pow(8 * n + 1, 0.5) - 1) / 2;
      long long sum = (a + b) * ( b - a + 1) / 2;

      while(sum != n){
        if(sum < n){
          b++;
          sum += b;
        }
        if(sum > n){
          sum -= a;
          a++;
        }
      }
    }

    cout << n << " = " << a << " + ... + " << b << endl;

  }

  return 0;
}
