
#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n && n != 0){
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }

    double b;
    cin >> b;
    double r, v, e, f;
    cin >> r >> v >> e >> f;

    vector<double> t;
    t.push_back(0);
    for(int d = 0; d <= a[n - 1]; d++){
      double dt;
      if(d >= r)
        dt = 1 / (v - e * (d - r));
      else
        dt = 1 / (v - f * (r - d));

      t.push_back(t.back() + dt);
    }

    vector<double> ta(n, INF);
    ta[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
      for(int j = i + 1; j < n; j++){
        ta[i] = min(ta[i], ta[j] + t[a[j] - a[i]] + b);
      }
    }

    double out = t[a[n - 1]];
    for(int i = 0; i < n - 1; i++){
      out = min(out, ta[i] + t[a[i]]);
    }
    cout << out << endl;
  }
}
