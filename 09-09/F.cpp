// F. Cut Ribbon

#include <iostream>
#include <climits>

#define max3(a, b, c) max(max(a, b), c)
#define N 4001

using namespace std;

int cutRibbon(int n, int a, int b, int c, int *arr){
  if(n == 0)
    return 0;
  else if(n < 0)
    return INT_MIN;
  else if(arr[n] != -1)
    return arr[n];
  return (arr[n] = 1 + max3(cutRibbon(n - a, a, b, c, arr),
              cutRibbon(n - b, a, b, c, arr),
              cutRibbon(n - c, a, b, c, arr)));
}

int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int *arr = new int[N];
  for(int i = 0; i < N; i++)
    arr[i] = -1;
  cout << cutRibbon(n, a, b, c, arr) << "\n";

  return 0;
}
