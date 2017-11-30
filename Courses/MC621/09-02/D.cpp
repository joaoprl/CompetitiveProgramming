// D. Strange Dialog

#include <cstdlib>
#include <cstdio>

#define MAX_SIZE (int)1e7+10

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  char *s = (char*)malloc(sizeof(char) * MAX_SIZE);
  bool b;
  int i;
  while(n--){
    scanf("%s", s);
    b = true;
    i = 0;
    while(b && s[i] != '\0'){
      if(s[i] == 'p'){
        if(s[i + 1] == 'u' &&s[i + 2] == 't' &&s[i + 3] == 'o' &&s[i + 4] == 'n')
          i += 5;
        else b = false;
      }
      else if(s[i] == 'o'){
        if(s[i + 1] == 'u' &&s[i + 2] == 't' &&s[i + 3] == 'p' &&s[i + 4] == 'u' &&s[i + 5] == 't' && s[i + 6] == 'o' && s[i + 7] == 'n' && s[i + 8] == 'e')
          i += 9;

        else if(s[i + 1] == 'u' &&s[i + 2] == 't' &&s[i + 3] == 'p' &&s[i + 4] == 'u' &&s[i + 5] == 't' && s[i + 6] == 'o' && s[i + 7] == 'n')
          i += 8;
        else if(s[i + 1] == 'n' &&s[i + 2] == 'e')
          i += 3;
        else if(s[i + 1] == 'u' &&s[i + 2] == 't' &&s[i + 3] == 'p' &&s[i + 4] == 'u' &&s[i + 5] == 't')
          i += 6;
        else if(s[i + 1] == 'u' &&s[i + 2] == 't')
          i += 3;
        else b = false;
      }
      else if(s[i] == 'i'){
        if(s[i + 1] == 'n' &&s[i + 2] == 'p' &&s[i + 3] == 'u' &&s[i + 4] == 't' &&s[i + 5] == 'o' && s[i + 6] == 'n' && s[i + 7] == 'e')
          i += 8;
        else if(s[i + 1] == 'n' &&s[i + 2] == 'p' &&s[i + 3] == 'u' &&s[i + 4] == 't' &&s[i + 5] == 'o' && s[i + 6] == 'n')
          i += 7;
        else if(s[i + 1] == 'n' &&s[i + 2] == 'p' &&s[i + 3] == 'u' &&s[i + 4] == 't')
          i += 5;
        else if(s[i + 1] == 'n')
          i += 2;
        else b = false;
      }
      else
        b = false;
    }
    if(b)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
