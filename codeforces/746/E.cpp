// E. Numbers Exchange

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int *arr = new int[n];
  int odd = 0, even = 0, evenUsed = 0, oddUsed = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i] % 2 == 0){
      even++;
      if(arr[i] <= m)
        evenUsed++;
    }
    else{
      odd++;
      if(arr[i] <= m)
        oddUsed++;
    }
  }

  if((even - odd) / 2 > m / 2 - oddUsed){
    cout << "-1\n";
    return 0;
  }
  if((odd - even) / 2 > m / 2 - evenUsed){
    cout << "-1\n";
    return 0;
  }

  sort(arr, arr + n);

  int equalsEven = 0, equalsOdd = 0;
  for(int i = 0; i < n - 1; i++){
    if(arr[i] == arr[i + 1]){
      if(arr[i] % 2 == 0)
        equalsEven++;
      else
        equalsOdd++;
    }
  }

  if(equalsEven > m / 2 - evenUsed){
    cout << "-1\n";
    return 0;
  }
  if(equalsOdd > m / 2 - oddUsed){
    cout << "-1\n";
    return 0;
  }


  return 0;
}
