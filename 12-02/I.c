// I. Bit Difference

#include <stdio.h>
#include <stdlib.h>

#define MOD 10000007

int main(){
  int t, n;
  int v, i, j, c, k, num;
  int *arr = (int *)malloc(sizeof(int) * 40);

  scanf("%d", &t);
  for(c = 1; c <= t; c++){
    scanf("%d", &n);

    for(i = 0; i < 32; i++)
      arr[i] = 0;

    for(i = 1; i <= n; i++){
      scanf("%d", &num);
      for(j = 0; j < 32; j++){
          arr[j] += num % 2;
          num = num >> 1;
      }
    }

    v = 0;
    for(i = 0; i < 32; i++){
      v += arr[i] * (n - arr[i]);
      v = v % MOD;
    }

    printf("Case %d: %d\n", c, (2 * v) % MOD);
  }

  return 0;
}
