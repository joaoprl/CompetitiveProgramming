
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  int *arr = new int[n + 1];
  for(int i = 0; i <= n; i++)
    arr[i] = i;

  int t, x, y;
  for(int i = 0; i < q; i++){
    cin >> t >> x >> y;

    if(t == 1){
      while(arr[x] != x)
        x = arr[x];

      while(arr[y] != y)
        y = arr[y];

      arr[x] = y;

    }
    else if(t == 2){
      int y1 = y;
      while(arr[y] != y)
        y = arr[y];

      for(int i = x; i <= y1; i++){
        x = i;
        while(arr[x] != x)
          x = arr[x];
        arr[x] = y;
      }

    }
    else if(t == 3){
      while(arr[x] != x)
        x = arr[x];

      while(arr[y] != y)
        y = arr[y];

      if(x != y)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }

  return 0;
}
