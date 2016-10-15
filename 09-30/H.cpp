// H. Suffix Equal Prefix

#include <iostream>
#include <cstdio>

#define N 1000005

using namespace std;

int main(){
  int t, k;
  int *b = new int[N];

  string s;
  cin >> t;
  for(int c = 1; c <= t; c++){
    cin >> s;

    k = 0;
    int i = 0, j = -1;
    b[0] = -1;
    while(i < s.size()){
      while(j >= 0 && s[i] != s[j]) j = b[j];
      i++; j++;
      b[i] = j;
    }

    i = 0; j = 0; k = 0;
    while(i < s.size()){
      while(j >= 0 && s[i] != s[j]) j = b[j];
      i++; j++;
      if(j == s.size()){
        printf("%d %d\n", i, j);
        k++;
        j = b[j];
      }
    }

    // a b a b c
    //-1 0 0 1 2 0
    // c b a b a
    //-1 0 0 0 0 0

    // a b a b a b
    //-1 0 0 1 2 3 4
    // b a b a b a
    //-1 0 0 1 2 3 4


    printf("Case %d: %d\n", c, k);
  }
  return 0;
}
