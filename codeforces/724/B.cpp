// B. Batch Sort

#include <iostream>

using namespace std;

bool batchSort(int **table, int n, int m){
  bool *swappableRow = new bool[m];
  int *swapCount = new int[n];
  bool **bTable = new bool*[n];
  for(int i = 0; i < n; i++){
    swapCount[i] = 0;
    bTable[i] = new bool[m];
    for(int j = 0; j < m; j++)
      bTable[i][j] = false;
  }
  for(int i = 0; i < m; i++)
    swappableRow[i] = true;

  for(int line = 0; line < n; line++){
    for(int row = 0; row < m; row++){
      if(table[line][row] != row + 1){
        bTable[line][row] = true;
        swapCount[line]++;
      }
    }
    if(swapCount[line] > 4)
      return false;
    if(swapCount[line] == 4){
      for(int row = 0; row < m; row++){
        if(table[line][row] != row + 1 && table[line][table[line][row] - 1] != row + 1)
          return false;
      }
    }
    if(swapCount[line] >= 2){
      for(int row = 0; row < m; row++){
        if(table[line][row] == row + 1)
          swappableRow[row] = false;
      }
    }
  }

  int sr[2];
  sr[0] = sr[1] = -1;
  for(int line = 0; line < n; line++){
    int swapRow = 0;
    for(int row = 0; row < m; row++){
      if(table[line][row] != row + 1 && !swappableRow[row]){
        swapRow += 2;

        int i;
        for(i = 0; i < m; i++)
          if(table[line][i] == row + 1)
            break;

        int aux = table[line][i];
        table[line][i] = table[line][row];
        table[line][row] = aux;
      }
    }

    if(swapCount[line] >= 3 && swapRow == 2){
      for(int row = 0; row < m; row++){
        if(table[line][row] != row + 1){
          if(!swappableRow[row] || !swappableRow[table[line][row] - 1]){
            return false;
          }

          if(sr[0] == -1){
            sr[0] = row;
            sr[1] = table[line][row] - 1;
          }
          else if((row != sr[0] && row != sr[1]) ||
            (table[line][row] - 1 != sr[0] && table[line][row] - 1 != sr[1]))
            return false;
        }
      }
    }

    if(swapRow > 2)
      return false;
  }
  return true;
}

int main(){
  int n, m;
  cin >> n >> m;
  int **table = new int*[n];
  for(int i = 0; i < n; i++){
    table[i] = new int[m];
    for(int j = 0; j < m; j++)
      cin >> table[i][j];
  }

  if(batchSort(table, n, m))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
