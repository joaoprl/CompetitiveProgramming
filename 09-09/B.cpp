// B. Planning Poker

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_VALUE (int)1e7+1
#define N 100000

int main(){
  int *v = new int[N];
  int n, a, b;
  scanf("%d", &n);
  while(n){

    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);

    sort(v, v + n);
    int a, b;
    a = 0;
    b = 1;

    for(int i = 0; i < n; i++){
      if(2 * (v[i] - b) < a){
        printf("%d ", b);
      }
      else{
        while(2 * (v[i] - b) >= a){
          b = a + b;
          a = b - a;
        }
        printf("%d ", b);
      }
    }
    printf("\n");
    scanf("%d", &n);
  }

  return 0;
}
