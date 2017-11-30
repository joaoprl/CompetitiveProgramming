
#include <iostream>

#define N 100010

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  string str;
  int pos[N];
  while(cin >> str){

    pos[0] = (str.front() == str.back());
    for(int i = 1; i < str.size(); i++){
      pos[i] = (str[i] == str.back());
      if(str[i] == str[str.size() - pos[i - 1] - 1])
        pos[i] = pos[i - 1] + 1;
    }

    int p = pos[str.size() - 1];

    cout << str;
    for(int i = str.size() - p - 1; i >= 0; i--)
      cout << str[i];
    cout << endl;
  }

  return 0;
}
