
#include <iostream>

#define N 1010

typedef long long ll;

using namespace std;

void compute(pair<ll, ll> *p, int n, int k, int i){

}

int main(){
  ios::sync_with_stdio(false);
  ll n, k;
  pair<ll, ll> *p = new pair<ll, ll>[N];

  while(cin >> n >> k){
    for(int i = 0; i < n; i++)
      cin >> p[i].first >> p[i].second;

    acc += p[sL].second * (p[sR].first - p[sL].first);
      p[sR].second += p[sL].second;
      p[sL].second = 0;
      curr--;
    }

    cout << acc << endl;
  }

  return 0;
}
