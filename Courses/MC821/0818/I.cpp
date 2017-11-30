
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    int count = 0;
    int acc = 0;
    for(int j = 0; j < str.length(); j++){
      if(str[j] == 'O'){
        count++;
        acc += count;
      }
      else
        count = 0;
    }
    cout << acc << endl;
  }

  return 0;
}
