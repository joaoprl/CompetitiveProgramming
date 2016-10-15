// J. Vasya and String

#include <iostream>

using namespace std;

int solve(string str, int k, int n, char c, int K, int *A){
  if(A[n] != -1)
    return A[n];

  if(n >= str.size())
    return 0;

  cout << str[n] << " " << k << " " << c << endl;

  if(k < 0)
    return 0;

  if(str[n] == c){
    return A[n] = 1 + solve(str, k, n + 1, c, K);
  }
  else{
    int m = 0;
    if(k > 0)
      m = 1 + solve(str, k - 1, n + 1, c, K);
    m = max(m, solve(str, K, n + 1, c, K));
    return m;
  }
}

int main(){
  int n, k;
  string str;
  cin >> n >> k >> str;
  int *A = new int[n];
  int *B = new int[n];
  for(int i = 0; i < n; i++)
    A[i] = B[i] = -1;

  cout << max(solve(str, k, 0, 'a', k, A), solve(str, k, 0, 'b', k, A)) << endl;
  return 0;
}
