// E. Sleep in Class

#include <iostream>

#define UNCOMPUTED -10
#define COMPUTING -9
#define LOOP -1

using namespace std;

int getNext(string str, int i, int t){
  if((t == 0 && str[i] == 'U') || (t == 1 && str[i] == 'D'))
    return i + 1;
  return i - 1;
}

int compute(string str, int **table, int i, int n){
  if(i < 0 || i >= n)
    return 0;
  if(table[i][t] != UNCOMPUTED)
    return table[i][t];

  table[i][t] = COMPUTING;

  table[i][2] = 1 - table[i][2];
  int result = compute(str, table, getNext(str, i, t), n);
  table[i][2] = 0;
  
  if(result == LOOP || result == COMPUTING)
    return (table[i][t] = LOOP);

  return (table[i][t] = result + 1);
}

int main(){
  int n;
  string str;
  cin >> n >> str;

  int **table = new int*[n];
  for(int i = 0; i < n; i++){
    table[i] = new int[3];
    table[i][0] = table[i][1] = UNCOMPUTED;
    table[i][2] = 0;
  }

  for(int i = 0; i < n - 1; i++)
    cout << compute(str, table, i, n) << " ";
  cout << compute(str, table, n - 1, n) << "\n";

  return 0;
}
