// C. New Year and Rating

#include <iostream>
#include <climits>

#define INF INT_MAX

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int c, d;
  int max, min;
  max = INF;
  min = -INF;
  bool poss = true;

  while(n--){
    cin >> c >> d;

    if(d == 1){
      if(min < 1900)
        min = 1900 + c;
      else
        min += c;

      if(max != INF)
        max += c;
    }
    else{
      if(max > 1899)
        max = 1899 + c;
      else
        max += c;

      if(min != -INF)
        min += c;
    }

    if(max < min)
      poss = false;
  }

  if(poss){
    if(max == INF)
      cout << "Infinity\n";
    else
      cout << max << "\n";
  }
  else
    cout << "Impossible\n";

  return 0;
}
