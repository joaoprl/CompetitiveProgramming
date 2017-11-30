
#include <iostream>
#define MAX 310

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int m[MAX][MAX];

  int l, n;
  while(cin >> l >> n){
    pair<int, int> one;
    for(int i = 0; i < l; i++){
      for(int j = 0; j < n; j++){
        cin >> m[i][j];
        if(m[i][j] == 1)
          one = {i, j};
      }
    }

    bool pos = true;
    for(int i = 0; i < l; i++){
      int c = (m[i][0] - 1) / n;
      for(int j = 0; j < n; j++){
        if(c != (m[i][j] - 1) / n){
          pos = false;
        }
      }
    }

    for(int j = 0; j < n; j++){
      int c = (m[0][j] - 1) % n;
      for(int i = 0; i < l; i++){
        if(c != (m[i][j] - 1) % n){
          pos = false;
        }
      }
    }

    if(pos){
      int count = 0;
      int val = 0;

      if(one.second != 0){
        count = 1;
        for(int i = 0; i < l; i++)
          swap(m[i][one.second], m[i][0]);
      }

      for(int i = 1; i <= l; i++){
        for(int j = i; j < l; j++){
          if((i - 1) * n + 1 == m[j][0]){
            if(i == 1)
              val = j;
            swap(m[i - 1][0], m[j][0]);
            count++;
          }
        }
      }

      for(int j = 1; j < n; j++)
        swap(m[0][j], m[val][j]);

      for(int j = 1; j <= n; j++){
        for(int i = j; i < n; i++){
          if(j == m[0][i]){
            swap(m[0][i], m[0][j - 1]);
            count++;
          }
        }
      }

      cout << count << endl;
    }
    else  cout << "*" << endl;

  }

  return 0;
}
