
#include <iostream>
#include <unordered_map>

#define N 10010

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  int num;
  int *arr = new int[N];
  while(cin >> n && n != 0){
    unordered_map<int, int> circle;

    int total = 0;
    circle[0] = 1;
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      total += arr[i];

      circle[total] = 1;
    }

    bool failed;
    for(int k = n; k >= 3; k--){
      failed = true;
      if(total % k == 0){
        int pos = 0;
        int count = 0;
        for(int i = 0; i < n && failed; i++){
          if(i > total / k)
            break;

          pos = i;
          pos += total / k;
          pos %= total;

          for(int j = 1; j < k; j++){
            if(circle[pos] == 1){
              pos += total / k;
              pos %= total;
            }
            else
              break;
          }
          if(circle[pos] == 1)
            failed = false;
        }
      }
      if(!failed){
        num = n - k;
        break;
      }
    }
    if(!failed)
      cout << num << endl;
    else
      cout << "-1\n";
  }

  return 0;
}
