
#include <iostream>

#define N 5001

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, num, acc;
  int *arr = new int[N];
  while(cin >> n && n != 0){
    for(int i = 0; i < n; i++)
      cin >> arr[i];

    int k = 0;
    while(k < n && arr[n - 1 - k] == 0)
      k++;

    acc = k;
    num = 0;
    if(k == n)
      num = (k + 1) / 2;
    for(int i = 0; i < n - k; i++){
      if(arr[i] == 0)
        acc++;
      else{
        num += acc / 2;
        acc = 0;
      }
    }
    cout << num << endl;
  }

  return 0;
}
