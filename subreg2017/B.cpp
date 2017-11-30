
#include <iostream>
#include <vector>
#include <deque>

#define X 1000010

using namespace std;

typedef long long ll;

ll apply(vector<ll> ts, ll a, ll n){
  bool in = false;
  ll r = a >> 1;
  for(ll i = 0; i < ts.size(); i++)
    in = in xor ((a >> ts[i]) & 1);

  if(in)
    r = r | (1 << n - 1);
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  ll n, t, a0, x, y;
  cin >> n >> t >> a0 >> x >> y;

  vector<ll> ts;
  ts.assign(t, 0);
  for(ll i = 0; i < t; i++)
    cin >> ts[i];

  deque<ll> di;
  ll acc = 0;

  ll xs[X];
  for(ll i = 0; i < X; i++)
    xs[i] = -1;

  ll a = a0;
  for(ll i = 0; i < y; i++){
    acc += a;
    di.push_back(acc);
    a = apply(ts, a, n);
  }
  ll pos = y;
  while(true){
    if(acc % x == 0){
      cout << 0 << " " << pos - 1 << endl;
      break;
    }
    else if(xs[acc % x] != -1){
      cout << xs[acc % x] << " " << pos - 1 << endl;
      break;
    }
    ll out = di.front();
    di.pop_front();
    pos++;
    if(xs[out % x] == -1 || xs[out % x] == 0)
      xs[out % x] = pos - y;
    acc += a;
    di.push_back(acc);
    a = apply(ts, a, n);
  }

  return 0;
}
