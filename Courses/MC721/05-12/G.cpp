
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

double tPres(char c){
  if(c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p'
     || c == 't' || c == 'w' || c == '#' || c == ' ')
     return 0.2;
  return 0.2 + tPres(c - 1);
}

int pos(char c){
  if(c == 'a' || c == 'b' || c == 'c')
    return 2;
  if(c == 'd' || c == 'e' || c == 'f')
    return 3;
  if(c == 'g' || c == 'h' || c == 'i')
    return 4;
  if(c == 'j' || c == 'k' || c == 'l')
    return 5;
  if(c == 'm' || c == 'n' || c == 'o')
    return 6;
  if(c == 'p' || c == 'q' || c == 'r' || c == 's')
    return 7;
  if(c == 't' || c == 'u' || c == 'v')
    return 8;
  if(c == 'w' || c == 'x' || c == 'y' || c == 'z')
    return 9;
  if(c == ' ')
    return 11;
  return 12;
}

double t(int a, int b){
  int x1, y1, x2, y2;
  x1 = (a - 1) % 3;
  y1 = (a - 1) / 3;
  x2 = (b - 1) % 3;
  y2 = (b - 1) / 3;

  double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  d = pow(d, 0.5);

  return d / 30;
}

double compute(string str, int p, int l, int r, double ***map){
  if(p >= str.size())
    return 0;
  if(map[p][l][r] != -1)
    return map[p][l][r];
  return (map[p][l][r] = min(compute(str, p + 1, pos(str[p]), r, map) + t(l, pos(str[p])),
    compute(str, p + 1, l, pos(str[p]), map) + t(r, pos(str[p]))) + tPres(str[p]));
}

void validate(string &st){
  for(int i = 0; i + 1 < st.length(); i++){
    if(pos(st[i]) == pos(st[i + 1]) && st[i] != '#' && st[i] != ' ')
      st.insert(i + 1, "#");
  }
}

int main(){
  ios::sync_with_stdio(false);
  string st;
  while(getline(cin, st)){
    validate(st);
    double ***map = new double**[200];
    for(int i = 0; i < 200; i++){
      map[i] = new double*[15];
      for(int j = 0; j < 15; j++){
        map[i][j] = new double[15];
        for(int k = 0; k < 15; k++)
          map[i][j][k] = -1;
      }
    }
    cout << fixed << setprecision(2) << compute(st, 0, 4, 6, map) << endl;
  }

  return 0;
}
