// E. Repeating Characters

#include <iostream>

using namespace std;

int main(){
  int t, n, k;
  cin >> t;
  string str;
  while(k != t){
    cin >> k >> n >> str;
    cout << k << " ";
    for(int i = 0; i < str.size(); i++){
      for(int j = 0; j < n; j++)
        cout << str[i];
    }
    cout << "\n";
  }

  return 0;
}
