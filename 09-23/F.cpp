// F. Alternating Sequences

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  long long n, m;
  cin >> n;

  long long *arr = new long long[n];
  long long *dst = new long long[n];

  m = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    dst[i] = 1;
    for(int j = i - 1; j >= 0; j--){
      if(arr[j] * arr[i] < 0 && abs(arr[j]) < abs(arr[i])){
        dst[i] = max(dst[i], dst[j] + 1);
      }
    }
    m = max(dst[i], m);
  }
  
  cout << m << "\n";

  return 0;

}
