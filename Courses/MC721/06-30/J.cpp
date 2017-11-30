

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int *a = new int[100010];
  int *b = new int[100010];

  int n, m;
  while(cin >> n >> m){
    for(int i = 0; i < n; i++)
      cin >> a[i];

    for(int j = 0; j < m; j++)
      cin >> b[j];

    int k = 0;
    for(int i = 0; i < n && k < m; i++){
      if(a[i] == b[k])
        k++;
    }

    if(k == m)
      cout << "sim\n";
    else
      cout << "nao\n";

  }
  return 0;
}
