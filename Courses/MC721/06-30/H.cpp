
#include <cstdio>

typedef long long ll;

ll max(ll a, ll b){
  if(a > b)
    return a;
  return b;
}

using namespace std;

ll compute(ll *ar, ll n, ll m, ll p, ll acc, ll **map){
  if(p >= m && acc % n == 0){
    return (map[acc % n][p] = 0);
  }
  else if(p >= m)
    return (map[acc % n][p] = -2);

  if(map[acc % n][p] != -1)
    return map[acc % n][p];

  int a = compute(ar, n, m, p + 1, acc + ar[p], map);
  int b = compute(ar, n, m, p + 1, acc, map);

  if(a == -2)
    return (map[acc % n][p] = b);
  if(b == -2)
    return (map[acc % n][p] = a + 1);

  return (map[acc % n][p] = max(a + 1, b));
}

int main(){
  ll n, m;

  ll **map = new ll*[1010];
  for(ll i = 0; i < 1010; i++)
    map[i] = new ll[1010];

  ll *ar = new ll[1010];
  while(scanf("%lld%lld", &n, &m) != EOF){
    for(ll i = 0; i < m; i++)
      scanf("%lld", &ar[i]);

    for(ll i = 0; i <= n; i++)
      for(ll j = 0; j <= m; j++)
        map[i][j] = -1;

    printf("%lld\n", compute(ar, n, m, 0, 0, map));

  }


  return 0;
}
