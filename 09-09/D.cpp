// D. Senha da Tia

#include <iostream>

using namespace std;

int main(){
  int n, m, a, k;
  cin >> n >> m >> a >> k;
  string s;
  cin >> s;

  for(int i = 0; i < s.size(); i++){
    if(s[i] >= 'a' && s[i] <= 'z')
      m--;
    else if(s[i] >= 'A' && s[i] <= 'Z')
      a--;
    else if(s[i] >= '0' && s[i] <= '9')
      k--;
  }
  if(s.size() >= n && m <= 0 && a <= 0 && k <= 0)
    cout << "Ok =/\n";
  else
    cout << "Ufa :)\n";

  return 0;
}
