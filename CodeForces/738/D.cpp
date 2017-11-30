// D. Sea Battle

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string str;
  cin >> str;

  vector<int> pos;

  int l = 0;
  int shoots = 0;
  int start = -1;
  for(int i = 0; i < n; i++){
    if(str[i] == '0' && i - start == b){
      pos.push_back(i + 1);
      start = i;
    }
    else if(str[i] == '1')
      start = i;
  }

  cout << pos.size() - a + 1 << "\n";
  int i;
  for(i = 0; i < pos.size() - a; i++){
    cout << pos[i] << " ";
  }
  cout << pos[i] << "\n";

  return 0;
}
