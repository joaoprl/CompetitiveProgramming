
#include <iostream>
#include <deque>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  string str;
  while(cin >> str){
    deque<string> out;
    string st;
    bool front = false;
    for(int i = 0; i < str.size(); i++){
      if(str[i] == '[' || str[i] == ']'){
        if(front && st != "")
          out.push_front(st);
        else if(st != "")
          out.push_back(st);
        st.clear();

        if(str[i] == '[')
          front = true;
        else
          front = false;
      }
      else
        st += str[i];
    }
    if(front && st != "")
      out.push_front(st);
    else if(st != "")
      out.push_back(st);

    for(deque<string>::iterator it = out.begin(); it != out.end(); it++)
      cout << *it;
    cout << endl;
  }

  return 0;
}
