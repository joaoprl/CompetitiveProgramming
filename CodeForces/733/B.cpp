// B. Parade

#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
  int n, l, r;
  scanf("%d", &n);

  int maxR, maxRCol, maxL, maxLCol, totalL, totalR, maxDistL, maxDistR;
  maxR = maxL = totalL = totalR = maxDistR = maxDistL = 0;
  maxRCol = maxLCol = -1;
  for(int i = 1; i <= n; i++){
    scanf("%d %d", &l, &r);
    if(l > r){
      if(l - r > maxDistL){ // best upgrade toward L leg
        maxDistL = l - r;
        maxLCol = i;
      }
      maxL++;
    }
    if(r > l){
      if(r - l > maxDistR){ // best upgrade toward R leg
        maxDistR = r - l;
        maxRCol = i;
      }
      maxR++;
    }
    totalL += l;
    totalR += r;
  }

  if(maxL == 0 || maxR == 0)
    printf("0\n");
  else if(totalL + maxDistR >= totalR + maxDistL)
    printf("%d\n", maxRCol);
  else if(totalR + maxDistL > totalL + maxDistR)
    printf("%d\n", maxLCol);

  return 0;
}
