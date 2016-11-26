// A. Assigning Teams

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int n;
  vector<int> v;
  for(int i = 0; i < 4; i++){
    cin >> n;
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  cout << abs(v[0] + v[3] - v[1] - v[2]) << endl;
  return 0;
}
