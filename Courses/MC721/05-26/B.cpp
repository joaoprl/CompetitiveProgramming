
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, f;
  cin >> n >> f;

  int *k = new int[n];
  int *l = new int[n];
  pair<int, int> *d = new pair<int, int>[n];
  for(int i = 0; i < n; i++){
    cin >> k[i] >> l[i];

    d[i] = make_pair(min(2 * k[i], l[i]) - min(k[i], l[i]), i);
  }

  sort(d, d + n, greater<pair<int, int> >());

  long long count = 0;
  for(int i = 0; i < f; i++){
    count += min(2 * k[d[i].second], l[d[i].second]);
    l[d[i].second] = 0;
    k[d[i].second] = 0;
  }

  for(int i = 0; i < n; i++){
    count += min(k[i], l[i]);
  }

  cout << count << endl;

  return 0;
}
