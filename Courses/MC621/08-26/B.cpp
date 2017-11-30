// B. Age Sort

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 2000005

int main(){
  int n;
  cin >> n;

  int* array = new int[N];
  while(n){

    for(int i = 0; i < n; i++)
      scanf("%d", &array[i]);
    sort(array, array + n);
    for(int i = 0; i < n - 1; i++)
      printf("%d ", array[i]);
    printf("%d\n", array[n - 1]);

    cin >> n;
    
  }

  return 0;
}
