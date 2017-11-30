// B. Tails all the way

#include <iostream>

#define SIZE 20
#define INF 1000

using namespace std;

void flip(bool *arr, int n){
  arr[n - 1] = !arr[n - 1];
  arr[n] = !arr[n];
  arr[n + 1] = !arr[n + 1];
}

int minimize(bool *arr, int n){
  if(n > SIZE){
    for(int i = 1; i <= SIZE; i++)
      if(arr[i] != 0)
        return INF;
    return 0;
  }

  int k = INF;
  k = minimize(arr, n + 1);

  flip(arr, n);
  k = min(k, minimize(arr, n + 1) + 1);
  flip(arr, n);

  return k;
}

int main(){
  bool *arr = new bool[SIZE + 2];
  for(int i = 1; i <= SIZE; i++)
    cin >> arr[i];
  cout << minimize(arr, 1) << "\n";
  return 0;
}
