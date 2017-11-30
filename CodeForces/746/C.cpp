// C. Tram

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int s, x1, x2, t1, t2, p, d;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

  if(x2 == x1){
    cout << "0\n";
    return 0;
  }

  int d2 = ((x2 - x1 < 0)? -1 : 1);

  int t;

  if(d2 == 1){
    if(d == 1 && p <= x1){
      t = (x2 - p) * t1;
    }else if(d == 1){
      t = (s - p + s + x2) * t1;
    }
    else{ // d == -1
      t = (p + x2) * t1;
    }
    t = min(t, (x2 - x1) * t2);
  }
  else{ // d2 == -1
    if(d == -1 && p >= x1){
      t = (p - x2) * t1;
    }
    else if(d == -1){
      t = (p + s + s - x2) * t1;
    }
    else{ // d == 1
      t = (s - p + s - x2) * t1;
    }

    t = min(t, (x1 - x2) * t2);
  }

  cout << t << endl;
  return 0;
}
