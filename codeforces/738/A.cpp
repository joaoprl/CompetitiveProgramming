// A. Interview with Oleg

#include <iostream>

using namespace std;

int main(){
  int n;
  string str;
  cin >> n >> str;
  string pattern = "ogo", out = "", buf;
  int i = 0;
  bool flag = true;
  for(int j = 0; j < n; j++){
    if(str[j] == pattern[i]){
      i++;
      buf = buf + str[j];
    }
    else{
      if(i != 0){
        i = 0;
        j--;
        out = out + buf;
        buf = "";
      }
      else{
        out = out + buf + str[j];
        buf = "";
        i = 0;
      }
      flag = true;
    }

    if(i == 3){
      buf = "";
      i = 1;
      if(flag){
        out = out + buf + "***";
        flag = false;
      }
    }
  }
  out = out + buf;
  cout << out << endl;

  return 0;
}
