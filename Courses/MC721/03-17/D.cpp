// D. Babelfish

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  map<string, string> dic;
  string str1, str2;
  while(getline(cin, str1) && !str1.empty()){
    istringstream iss(str1);
    iss >> str1 >> str2;
    dic[str2] = str1;
  }

  while(cin >> str1 && !str1.empty()){
    str2 = dic[str1];
    if(str2 == "")
      cout << "eh" << endl;
    else
      cout << str2 << endl;
  }

  return 0;
}
