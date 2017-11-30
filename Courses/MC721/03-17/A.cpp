// A. As Dicas de Ali Babá

#include <iostream>
#include <algorithm>

#define N 100010

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int k, n;
  pair<int, int> *arr = new pair<int, int>[N];
  while(cin >> k >> n){
    for(int i = 0; i < N; i++)
      arr[i] = make_pair(0,0);

    int num;
    for(int i = 1; i <= k; i++){
      cin >> num;
      if(arr[num].first == 0)
        arr[num] = make_pair(i, num);
    }

    sort(arr, arr + n + 1);

    for(int i = 1; i < n; i++)
      cout << arr[i].second << " ";
    cout << arr[n].second << endl;
  }

  return 0;
}
