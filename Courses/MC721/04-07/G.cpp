
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  vector< pair<double, double> > cities;
  int n;

  int t = 1;
  while(cin >> n){
    double x, y, xm, ym, r;
    xm = ym = 0;
    cities.clear();
    for(int i = 0; i < n; i++){
      cin >> x >> y;
      cities.push_back(make_pair(x, y));
      xm += x;
      ym += y;
    }

    xm /= n;
    ym /= n;
    r = 0;
    for(int i = 0; i < cities.size(); i++){
      x = cities[i].first;
      y = cities[i].second;
      r = max(r, pow((xm - x) * (xm - x) + (ym - y) * (ym - y), 0.5));
    }

    cout << "Instancia " << t << endl;
    cout << xm << " " << ym << " " << r << endl;
    t++;
  }

  return 0;
}
