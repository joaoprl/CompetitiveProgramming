// B. Eefun Guessing Words

#include <cstdio>

#define AB_SIZE ('Z' - 'A' + 1)

using namespace std;

int main(){
  bool **m = new bool*[AB_SIZE];

  for(int i = 0; i < AB_SIZE; i++){
    m[i] = new bool[AB_SIZE];
    for(int j = 0; j < AB_SIZE; j++)
      m[i][j] = false;
  }

  bool *h = new bool[AB_SIZE];
  for(int i = 0; i < AB_SIZE; i++)
    h[i] = false;

  char c;
  while(scanf("%c", &c) && c != '\n'){
    for(int i = 0; i < AB_SIZE; i++){
      if(h[i])
        m[i][c - 'A'] = true;
    }
    h[c - 'A'] = true;
  }

  int n;
  char x, y;
  scanf("%d", &n);
  scanf("%c", &x);
  while(n--){
    scanf("%c %c", &x, &y);
    if(m[x - 'A'][y - 'A'])
      printf("YA\n");
    else
      printf("TIDAK\n");
    scanf("%c", &x);
  }

  return 0;
}
