// A. Edit distance

#include <iostream>

#define min3(x, y, z) min(x, min(y, z))
#define N 2005

using namespace std;

int main(){
  int n, i, j, k;
  cin >> n;
  string str1, str2;

  int **table;
  table = new int*[N];
  for(int i = 0; i < N; i++)
    table[i] = new int[N];

  while(n--){
    cin >> str1 >> str2;

    for(int i = 0; i <= str1.size(); i++) table[i][0] = i;
    for(int j = 0; j <= str2.size(); j++) table[0][j] = j;

    for(int i = 1; i <= str1.size(); i++){
      for(int j = 1; j <= str2.size(); j++){
        table[i][j] = min(table[i - 1][j] + 1, table[i][j - 1] + 1);

        if(str1[i - 1] == str2[j - 1])
          table[i][j] = min(table[i][j], table[i - 1][j - 1]);
        else
          table[i][j] = min(table[i][j], table[i - 1][j - 1] + 1);
      }
    }

    cout << table[str1.size()][str2.size()] << endl;
  }
  return 0;
}
