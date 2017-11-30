
#include <iostream>

#define N 30

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;

  int *lar = new int[N];
  int *che = new int[N];

  while(cin >> n){
    for(int i = 0; i < n; i++)
      cin >> lar[i];

    int total = 0;
    for(int i = 0; i < n; i++){
      cin >> che[i];

      int pos = 0;
      for(int j = 0; j < n; j++){
        if(lar[j] == che[i]){
          lar[j] = 0;
          break;
        }
        if(lar[j] != 0)
          pos++;
      }
      total += pos;
    }

    cout << total << endl;

  }

  return 0;
}
