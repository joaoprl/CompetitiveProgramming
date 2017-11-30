
#include <iostream>

#define N 10001

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  int *h = new int[N];
  while(cin >> n && n > 0){
    for(int i = 0; i < n; i++)
      cin >> h[i];

    int count = 0;
    for(int i = 0; i < n; i++){
      if((h[i] > h[(i - 1 + n) % n] && h[i] > h[(i + 1) % n])
       || (h[i] < h[(i - 1 + n) % n] && h[i] < h[(i + 1) % n]))
        count++;
    }

    cout << count << endl;
  }

  return 0;
}
