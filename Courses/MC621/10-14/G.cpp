// G. Verse Pattern

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int n, v;
  int *pattern = new int[n];
  bool matches = true;
  char c;

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &pattern[i]);
  scanf("%c", &c);

  for(int i = 0; i < n; i++){
    v = 0;
    c = 0;
    while(c != '\n'){
      scanf("%c", &c);
      if(c == 'a' || c == 'i' || c == 'u' || c == 'e'
      || c == 'o' || c == 'y')
        v++;
    }
    if(v != pattern[i])
      matches = false;
  }

  if(matches)
    printf("YES\n");
  else printf("NO\n");

  return 0;
}
