// C. War

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int s, t;
  cin >> s;
  vector<int> q, n;
  for(int i = 0; i < s; i++){
    cin >> t;
    q.push_back(t);
  }
  for(int i = 0; i < s; i++){
    cin >> t;
    n.push_back(t);
  }
  sort(q.begin(), q.end());
  sort(n.begin(), n.end());

  int k = n.size() - 1;
  for(int i = q.size() - 1; i >= 0; i--){
    if(q[i] < n[k])
      k--;
  }
  cout << s - k - 1 << "\n";

  return 0;
}
