// B. Decipher

#include <cstdio>

using namespace std;

int main(){
  long long n;
  scanf("%lld", &n);

  while(n--){
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld\n", a * a - 2 * b);
  }


  return 0;
}
