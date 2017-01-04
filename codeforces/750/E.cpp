// E. New Year and Old Subsequence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;

  vector<int> twos, ones, zeroes, sevens;

  int *sixes = new int[n + 1];
  sixes[0] = 0;

  for(int i = 1; i <= n; i++){
    sixes[i] = sixes[i - 1];

    if(s[i] == '2')
      twos.push_back(i);
    else if(s[i] == '0')
      zeroes.push_back(i);
    else if(s[i] == '1')
      ones.push_back(i);
    else if(s[i] == '6')
      sixes[i]++;
    else if(s[i] == '7')
      sevens.push_back(i);
  }

  int a, b;
  while(q--){
    cin >> a >> b;

    vector<int>::iterator p, firstOne;

    p = lower_bound(twos.begin(), twos.end(), a);
    if(p == twos.end() || *p > b){
      cout << "-1\n";
      continue;
    }

    p = lower_bound(zeroes.begin(), zeroes.end(), *p + 1);
    if(p == zeroes.end() || *p > b){
      cout << "-1\n";
      continue;
    }

    p = lower_bound(ones.begin(), ones.end(), *p + 1);
    if(p == ones.end() || *p > b){
      cout << "-1\n";
      continue;
    }

    firstOne = p;

    p = lower_bound(sevens.begin(), sevens.end(), *p + 1);
    if(p == sevens.end() || *p > b){
      cout << "-1\n";
      continue;
    }
    cout << sixes[b] - sixes[*firstOne] << "\n";
  }



  return 0;
}
