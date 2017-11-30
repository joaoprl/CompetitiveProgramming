// B. The number of the board

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int k;
  string n;
  cin >> k >> n;

  int count = 0, d = 0;
  for(int i = 0; i < n.length(); i++)
    count += n[i] - '0';

  sort(n.begin(), n.end());

  for(int i = 0; i < n.length(); i++){
    if(count < k){
      count += '9' - n[i];
      d++;
    }
  }

  cout << d << endl;


  return 0;
}
