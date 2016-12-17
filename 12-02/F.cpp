// F. Numeral System

#include <iostream>
#include <string>

using namespace std;

int from(string str){
  int m, c, x, i;
  m = c = x = i = 0;

  for(int p = 0; p < str.length(); p++){
    if(str[p] >= '2' && str[p] <= '9'){
      if(str[p + 1] == 'm')
        m = str[p] - '0';
      if(str[p + 1] == 'c')
        c = str[p] - '0';
      if(str[p + 1] == 'x')
        x = str[p] - '0';
      if(str[p + 1] == 'i')
        i = str[p] - '0';

      p++;
    }
    else{
      if(str[p] == 'm')
        m = 1;
      if(str[p] == 'c')
        c = 1;
      if(str[p] == 'x')
        x = 1;
      if(str[p] == 'i')
        i = 1;
    }
  }

  return 1000 * m + 100 * c + 10 * x + i;
}

string to(int v){
  int m, c, x, i;
  m = c = x = i = 0;

  i = v % 10;
  v /= 10;

  x = v % 10;
  v /= 10;

  c = v % 10;
  v /= 10;

  m = v % 10;
  v /= 10;

  string s = "";

  if(m > 0){
    if(m > 1)
      s = s + to_string(m);
    s = s + "m";
  }
  if(c > 0){
    if(c > 1)
      s = s + to_string(c);
    s = s + "c";
  }
  if(x > 0){
    if(x > 1)
      s = s + to_string(x);
    s = s + "x";
  }
  if(i > 0){
    if(i > 1)
      s = s + to_string(i);
    s = s + "i";
  }


  return s;
}

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  while(n--){
    string str1, str2;
    cin >> str1 >> str2;

    cout << to(from(str1) + from(str2)) << "\n";
  }

  return 0;
}
