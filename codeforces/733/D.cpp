// D. Kostya the Sculptor

#include <iostream>
#include <map>
#include <algorithm>

#define min3(x, y, z) min(x, min(y, z))

using namespace std;

void sort3(int &x, int &y, int &z){
  int aux;
  if(y > x){
    aux = x;
    x = y;
    y = aux;
  }
  if(z > y){
    aux = y;
    y = z;
    z = aux;
  }
  if(y > x){
    aux = x;
    x = y;
    y = aux;
  }
}

int main(){
  int n, a, b, c;
  cin >> n;

  int r[2];
  r[0] = r[1] = 0;

  map< pair<int, int>, pair<int, int> > m;
  pair<int, int> zero_pair = make_pair(0, 0), key, value;

  int max_v = 0;
  for(int i = 1; i <= n; i++){
    cin >> a >> b >> c;
    sort3(a, b, c);

    if(c > max_v){
      max_v = c;
      r[1] = 0;
      r[0] = i;
    }

    key.first = a;
    key.second = b;
    value.first = c;
    value.second = i;
    if(m[key] == zero_pair)
      m[key] = value;
    else{
      if(max_v < min3(a, b, m[key].first + c)){
        max_v = min3(a, b, m[key].first + c);
        r[0] = m[key].second;
        r[1] = i;
      }
      if(m[key].first < c){
        m[key].first = c;
        m[key].second = i;
      }

    }
  }

  if(r[1] == 0)
    cout << "1\n" << r[0] << "\n";
  else
    cout << "2\n" << r[0] << " " << r[1] << "\n";

  return 0;
}
