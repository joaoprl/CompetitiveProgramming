
#include <iostream>

#define N 10001

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  int *arr = new int[N];
  while(cin >> n && n != 0){
    for(int i = 0; i < N; i++)
      arr[i] = 0;

    int c, v;
    while(n--){
      cin >> c >> v;
      arr[c] += v;
    }

    int total = 0;
    for(int i = 0; i < N; i++)
      total += arr[i] / 2;

    cout << total / 2 << endl;
  }

  return 0;
}
