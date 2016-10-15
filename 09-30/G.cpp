// G. Bytelandian gold coins

#include <iostream>

#define N 100000

using namespace std;

long long maximize(long long n, long long *table){
  if(n >= N){
    if((int)n/2 + (int)n/3 + (int)n/4 >= n)
      return maximize(n/2, table) + maximize(n/3, table)+maximize(n/4, table);
    else
      return n;
  }
  else{
    if(table[n] != -1)
      return table[n];
    else{
      if((int)n/2 + (int)n/3 + (int)n/4 >= n)
        return (table[n] = maximize(n/2, table) + maximize(n/3, table)+maximize(n/4, table));
      else
        return (table[n] = n);
    }
  }
}

int main(){
  int n;
  long long *table = new long long[N];


  for(int i = 0; i < N; i++)
    table[i] = -1;
  table[0] = 0;

  while(cin >> n){
    cout << maximize(n, table) << "\n";
  }

  return 0;
}
