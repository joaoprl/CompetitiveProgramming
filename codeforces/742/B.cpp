// B.Arpa’s obvious problem and Mehrdad’s terrible solution

#include <iostream>

#define N 100010

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  long long n, x;
  cin >> n >> x;

  long long *arr = new long long[N];
  for(int i = 0; i < N; i++)
    arr[i] = 0;

  long long num;
  for(int i = 0; i < n; i++){
    cin >> num;
    arr[num]++;
  }

  long long v;
  long long q = 0;
  for(int i = 0; i < N; i++){
    if(arr[i] > 0){
      v = x xor i;
      if(v < N && v > i)
        q += ((long long)arr[i]) * arr[v];
      else if(v == i)
        q += arr[i] * (arr[i] - 1) / 2;
    }
  }

  cout << q << endl;

  return 0;
}
