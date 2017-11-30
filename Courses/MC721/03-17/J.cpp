// J. Triangulos

#include <iostream>
#include <map>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;


  while(cin >> n){
    map<int, int> circle;

    int *arr = new int[n];
    int total = 0;

    circle[0] = 1;
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      total += arr[i];

      circle[total] = 1;
    }

    if(total % 3 != 0){
      cout << 0 << endl;
      continue;
    }

    int pos = 0;
    int count = 0;
    int acc = 0;
    for(int i = 0; i < n; i++){
      pos = acc;
      pos += total / 3;
      pos %= total;

      if(circle[pos] == 1){
        pos += total / 3;
        pos %= total;
        if(circle[pos] == 1)
          count++;
      }
      acc += arr[i];
    }
    cout << count / 3 << endl;
  }

  return 0;
}
