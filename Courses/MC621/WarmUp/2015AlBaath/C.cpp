// C. Rotate It !!

#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    int n, *arr, sum[2], max, pos;
    
    cin >> n;    
    arr = (int*)malloc(sizeof(int) * n);
    sum[0] = sum[1] = 0;
    
    for(int j = 0; j < n; j++){
      cin >> arr[j];
      
      sum[j % 2] += arr[j];      
    }
    
    if(n % 2 != 0){
      max = sum[0];
      pos = 0;

      for(int j = 0; j < n; j++){
	sum[pos] -= arr[j];
      
	pos = (pos + 1) % 2;
	sum[pos] += arr[j];
	max = (max > sum[pos])? max : sum[pos];
      }
    }

    else
      max = (sum[0] > sum[1])? sum[0] : sum[1];

    cout << max << "\n";

    free(arr);
    
  }
  return 0;
}
