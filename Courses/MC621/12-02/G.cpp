// G. Non-Decreasing Digits

#include <iostream>

using namespace std;

long long compute(int n, int s, long long **table){
  if(table[n][s] != -1)
    return table[n][s];
  if(n == 1)
    return (table[n][s] = 10 - s);

  long long v = 0;

  for(int i = s; i < 10; i++)
    v += compute(n - 1, i, table);

  table[n][s] = v;
  return v;
}

int main(){
  ios::sync_with_stdio(false);
  int p, t, n;
  cin >> p;

  long long **table = new long long*[70];
  for(int i = 0; i < 70; i++){
    table[i] = new long long[10];
    for(int j = 0; j < 10; j++)
      table[i][j] = -1;
  }

  while(p--){
    cin >> t >> n;

    cout << t << " " << compute(n, 0, table) << "\n";
  }

  return 0;
}
