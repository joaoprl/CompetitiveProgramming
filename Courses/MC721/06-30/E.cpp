
#include <iostream>
#include <climits>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  while(cin >> n && n != 0){

    int p1, p2;
    p1 = p2 = 0;

    int num;
    for(int i = 0; i < n; i++){
      cin >> num;

      p1 += num % 2;
    }

    for(int i = 0; i < n; i++){
      cin >> num;

      p2 += num % 2;
    }

    int ma = INT_MAX;
    ma = abs(p1 - n + p2);
    cout << ma << endl;
  }

  return 0;
}
