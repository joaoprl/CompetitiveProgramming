// E. Cuarenta e Dois

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define N 40

using namespace std;

int main(){
  int t, n, k;
  cin >> t;

  int *arr = new int[N];
  bool *flag = new bool[N];
  while(t--){
    cin >> n >> k;

    for(int j = 0; j < n; j++){
      cin >> arr[j];
      flag[j] = true;
    }

    for(int i = 29; i >= 0; i--){
      int count = 0;
      for(int j = 0; j < n; j++)
        if(flag[j] && (arr[j] & (1 << i)) != 0)
          count++;

      if(count >= k){
        for(int j = 0; j < n; j++)
          if(flag[j] && (arr[j] & (1 << i)) == 0)
            flag[j] = false;
      }
    }
    int value = -1;
    for(int j = 0; j < n; j++){
      if(flag[j] && value == -1)
        value = arr[j];
      else if(flag[j])
        value = value & arr[j];
    }
    cout << value << endl;

  }
  return 0;
}
