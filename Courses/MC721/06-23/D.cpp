
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

class Dancer{
public:
  ll x, y, r;
  double area;
  Dancer(ll x, ll y, ll r){
    this->x = x;
    this->y = y;
    this->r = r;
    this->area = acos(-1) * r * r;
  }
};

ll dist2(Dancer a, Dancer b){
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(Dancer a, Dancer b){
  return a.area > b.area;
}

int main(){
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;

  vector<Dancer> dancers;

  ll x, y, r;
  for(ll i = 0; i < n; i++){
    cin >> x >> y >> r;

    dancers.push_back(Dancer(x, y, r));
  }

  sort(dancers.begin(), dancers.end(), comp);

  bool **areas = new bool*[n];

  for(ll i = 0; i < n; i++){
    areas[i] = new bool[n];
    for(ll j = 0; j < n; j++)
      areas[i][j] = dist2(dancers[i], dancers[j]) <= max(dancers[i].r * dancers[i].r, dancers[j].r * dancers[j].r);
  }

  vector<int> a, b;

  int dA, dB;
  double ar = 0;
  for(int i = 0; i < n; i++){
    dA = 0;
    dB = 0;
    for(int j = 0; j < a.size(); j++)
      dA += areas[i][a[j]];
    for(int j = 0; j < b.size(); j++)
      dB += areas[i][b[j]];


    if(dA % 2 == 0){
      a.push_back(i);
      ar += dancers[i].area;
    }
    else{
      b.push_back(i);
      if(dB % 2 == 0)
        ar += dancers[i].area;
      else
        ar -= dancers[i].area;
    }

  }

  cout << fixed << setprecision(8) << ar << endl;


  return 0;
}
