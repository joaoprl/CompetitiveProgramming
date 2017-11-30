// H. Jumping Mario

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for(int c = 1; c <= t; c++){
    int n;
    cin >> n;

    int curr, next;
    cin >> curr;
    int high = 0, low = 0;
    for(int i = 1; i < n; i++){
      cin >> next;
      if(next > curr)
        high++;
      if(next < curr)
        low++;
      curr = next;
    }

    cout << "Case " << c << ": " << high << " " << low << endl;
  }
  return 0;
}
