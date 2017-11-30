
#include <iostream>
#include <algorithm>

#define N 2000010

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  int *p = new int[N];
  while(cin >> n && n > 0){
    for(int i = 0; i < n; i++)
      cin >> p[i];

    sort(p, p + n);

    int m = 0;
    for(int i = 0; i < n / 2; i++){
      m = max(m, p[i] + p[n - i - 1]);
    }

    cout << m << endl;
  }

  return 0;
}
