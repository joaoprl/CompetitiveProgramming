// J. Torres de Hanói

#include <cstdio>

using namespace std;

int main(){
  int n, c;

  scanf("%d", &n);
  c = 1;
  while(n){
    printf("Teste %d\n%d\n\n", c, ((int)(1 << n) - 1));
    c++;
    scanf("%d", &n);
  }

  return 0;
}
