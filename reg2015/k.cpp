
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void insert(map<int, int> &shops, pair<int, int> sh){
  int s = sh.first;
  int c = sh.second;

  shops[c] = max(s, shops[c]);
  map<int, int>::iterator it = shops.lower_bound(c), nx;
  it++;

  while(it != shops.end() && it->second <= s){
    nx = it;
    nx++;
    shops.erase(it);
    it = nx;
  }
}

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<int> e(n + 1, 0);
  for(int i = 1; i <= n; i++)
    cin >> e[i];

  vector< pair<int, pair<int, int> > > sh;

  int l, s, c;
  for(int i = 0; i < m; i++){
    cin >> l >> s >> c;
    sh.push_back({l, {s, c}});
  }
  sort(sh.begin(), sh.end());
  map<int, int> shops;

  int energy = 0;
  int k = 0;
  int totalCost = 0;
  for(int i = 1; i <= n; i++){
    while(k < sh.size() && sh[k].first <= i){
      insert(shops, sh[k].second);
      k++;
    }

    if(energy < e[i]){
      int lo = 1;
      int hi = shops.rbegin()->first;

      cout << "level: " << i << endl;
      for(map<int, int>::iterator it = shops.begin(); it != shops.end(); it++)
        cout << it->first << " " << it->second << endl;

      while(lo != hi){
        int mid = (lo + hi) / 2;

        map<int, int>::iterator it = shops.lower_bound(mid);
        cout << it->first << " " << it->second << " " << lo << " " << hi << endl;
        if(it->second >= e[i])
          hi = mid;
        else
          lo = mid + 1;
      }
      cout << lo << endl;
      cout << endl;
      totalCost += lo;
      energy += max(lo, energy);
    }
    energy -= e[i];
  }

  cout << totalCost << endl;

  return 0;
}
