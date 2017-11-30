// D. A Needle in the Haystack

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void kmpPreprocess (char *p, int *b, int m){
  int i = 0, j = -1; b[0] = -1;
  while(i < m){
    while(j >= 0 && p[i] != p[j])
      j = b[j];
    i++; j++;
    b[i] = j;
  }
}

int main(){
  int n;
  char c;
  char *p;
  int *b;

  while(cin >> n){
    p = (char *)malloc(sizeof(char) * (n + 10));
    b = (int *)malloc(sizeof(int) * (n + 10));
    scanf("%s", p);

    kmpPreprocess(p, b, n);

    int i = 0, j = 0;
    bool flag = true;
    scanf("%c", &c);
    scanf("%c", &c);
    while(c != '\n' && c != EOF){
      while(j >= 0 && c != p[j])
        j = b[j] ;
      scanf("%c", &c);
      i++; j++;
      if(j == n){
        flag = false;
        printf("%d\n", i - j) ;
        j = b[j];
      }
    }
    if(flag)
      printf("\n");
    free(b);
    free(p);
  }
  return 0;
}
