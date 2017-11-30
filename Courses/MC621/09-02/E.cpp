// E. Onotole needs your help

#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int *array = new int[n];
  for(int i = 0; i < n; i++)
    scanf("%d", &array[i]);

  sort(array, array + n);

  for(int i = 0; i < n; i += 2){
    if(array[i] != array[i + 1]){
      printf("%d\n", array[i]);
      break;
    }
  }

  return 0;
}
