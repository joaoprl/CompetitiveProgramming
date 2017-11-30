
#include <iostream>
#include <vector>
#define MAX 2000010

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> x(n, 0), y(n, 0);
  vector<bool> nums(MAX, false);
  for(int i = 0; i < n; i++){
    cin >> x[i];
    nums[x[i]] = true;
  }
  for(int i = 0; i < n; i++){
    cin >> y[i];
    nums[y[i]] = true;
  }

  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int val = x[i] xor y[j];
      if(val < MAX && val >= 0 && nums[x[i] xor y[j]])
        count++;
    }
  }
  if(count % 2 == 0)
    cout << "Karen" << endl;
  else
    cout << "Koyomi" << endl;

  return 0;
}
