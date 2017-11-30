
#include <iostream>

using namespace std;

char change(char c){
  if(c >= 'a' && c <= 'z')
    return c - 'a' + 'A';
  else
    return c - 'A' + 'a';
}

int main(){
  ios::sync_with_stdio(false);
  string str;

  while(getline(cin, str) && str != "*"){
    char c = 0;
    bool newWord = true;
    bool taut = true;
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ' ')
        newWord = true;
      else{
        if(newWord){
          if(c == 0)
            c = str[i];
          else if(c != str[i] && change(c) != str[i])
            taut = false;
        }
        newWord = false;
      }
    }
    if(taut)
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }

  return 0;
}
