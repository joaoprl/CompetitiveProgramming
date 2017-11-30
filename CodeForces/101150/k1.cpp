
// K1. Fair Warning

#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;

int main(){
  int n;

  scanf("%d", &n);

  int v[3];

  int maxi = 0;

  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
    maxi = max(maxi, v[i]);
  }

  int mx = 1;

  for(int k = 2; k <= maxi; k++){
    int eq = 1;
    for(int i = 1; i < n; i++)
      if(v[i]%k != v[i-1]%k)
        eq = 0;

    if(eq)
      mx = max(mx, k);
  }

  //printf("mx = %d\n", mx);

  if(maxi%mx == 0){
    printf("0\n");
    return 0;
  }

  printf("%d\n", mx - maxi%mx);

  return 0;
}
