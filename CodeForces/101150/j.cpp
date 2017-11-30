
// J. Snapper Chain

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll mem[31];
  mem[1] = 1;
  for(int i = 2; i < 31; i++)
    mem[i] = 2*mem[i-1] + 1;

  int t;
  cin >> t;
  while(t--){
    int n;
    ll k;
    scanf("%d %I64d", &n, &k);
    if(n == 0){
      printf("OFF\n");
      continue;
    }

    if(k == mem[n] || (k - mem[n])%(mem[n] + 1) == 0)
      printf("ON\n");
    else
      printf("OFF\n");
  }

  return 0;
}
