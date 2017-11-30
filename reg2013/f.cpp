#include<bits/stdc++.h>

using namespace std;

#define pb push_back

typedef vector<int> vi;

int main(){
  int n, g;

  while(cin >> n >> g){
    vi v;
    int points = 0;
    for(int i = 0; i < n; i++){
      int s, r;
      scanf("%d %d", &s, &r);
      if(r == s)
        points++;
      if(s > r)
        points += 3;
      if(r >= s)
        v.pb(r - s);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size() && g > 0; i++){
      if(v[i] == 0){
        g--;
        points += 2;
      }

      else{
        if(g > v[i]){
          g -= v[i] + 1;
          points += 3;
        }

        else if(g == v[i]){
          g = 0;
          points += 1;
        }
      }
    }

    printf("%d\n", points);
  }

  return 0;
}
