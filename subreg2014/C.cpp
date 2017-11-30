// C. Confederation 
// C. Confederação

#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

class Plane{
public:
  int a, b, c, d;
  Plane(int a, int b, int c, int d) : a(a), b(b), c(c), d(d){}
};

class Point{
public:
  int x, y, z;
  string str;
  Point(int x, int y, int z) : x(x), y(y), z(z), str(""){ }

  void setC(char c){
    str.push_back(c);
  }
};

int main(){
  ios::sync_with_stdio(false);
  int m, n, a, b, c, d, x, y, z;

  vector<Plane> vPL;
  vector<Point> vPO;
  while(cin >> m >> n){
    vPL.clear();
    vPO.clear();
    for(int i = 0; i < m; i++){
      cin >> a >> b >> c >> d;

      vPL.push_back(Plane(a, b, c, d));
    }

    for(int i = 0; i < n; i++){
      cin >> x >> y >> z;

      vPO.push_back(Point(x, y, z));
    }

    for(int i = 0; i < vPL.size(); i++){
      Plane &pl = vPL[i];
      for(int j = 0; j < vPO.size(); j++){
        Point &po = vPO[j];
        if((pl.a * po.x + pl.b * po.y + pl.c * po.z - pl.d) > 0)
          po.setC('A');
        else
          po.setC('B');
      }
    }

    map<string, int> m;
    for(int i = 0; i < vPO.size(); i++)
      m[vPO[i].str] = m[vPO[i].str] + 1;

    int ma = 0;
    for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
      ma = max(ma, it->second);

    cout << ma << endl;

  }

  return 0;
}
