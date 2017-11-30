
// S. Surf

#include <iostream>
#include <algorithm>
#include <vector>

#define M_MAX 1000010
#define max3(x, y, z) max(x, max(y, z))

using namespace std;

typedef long long ll;

class Wave{
public:
  ll m, f, w;
  Wave(int m, int f, int w) : m(m), f(f), w(w){ }

  bool operator<(const Wave &w){
    return this->m < w.m;
  }
};

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<Wave> waves;

  ll m, f, w;
  for(int i = 0; i < n; i++){
    cin >> m >> f >> w;
    waves.push_back(Wave(m, f, w));
  }
  sort(waves.begin(), waves.end());

  vector<ll> ms(M_MAX, 0);
  for(int i = M_MAX - 2; i >= 0; i--){
    vector<Wave>::iterator it = lower_bound(waves.begin(), waves.end(), Wave(i, 0, 0));
    if(it->m != i)
      ms[i] = max(ms[i], ms[i + 1]);

    while(it->m == i && it != waves.end()){
      if(it->m + it->w >= M_MAX)
        ms[i] = max3(ms[i], ms[i + 1], it->f);
      else
        ms[i] = max3(ms[i], ms[i + 1], ms[it->m + it->w] + it->f);

      it++;
    }
  }

  cout << ms[0] << endl;

  return 0;
}
