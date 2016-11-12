// C. As Dicas de Ali Babá

#include <iostream>

#define N 100001

using namespace std;

int main(){
  int k, n, num;
  int *arr = new int[N];
  while(cin >> k >> n){
    for(int i = 0; i <= n; i++)
      arr[i] = 0;

    int count = 0;
    for(int i = 0; i < k; i++){
      cin >> num;
      if(arr[num] == 0){
        arr[num] = 1;
        cout << num;
        if(count < n - 1){
          cout << " ";
        }
        count++;
      }
    }
    cout << "\n";
  }
  delete[] arr;
  return 0;
}
