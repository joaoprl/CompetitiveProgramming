// H. Equidistant String

#include <iostream>

using namespace std;

int main(){
  string s, t;
  cin >> s >> t;

  string p (s.size(), 0);

  bool b = true;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == t[i]) p[i] = s[i];
    else if(b){
      p[i] = s[i];
      b = !b;
    }
    else{
      p[i] = t[i];
      b = !b;
    }
  }

  if(b)
    cout << p << "\n";
  else
    cout << "impossible\n";
    
  
  return 0;
}
