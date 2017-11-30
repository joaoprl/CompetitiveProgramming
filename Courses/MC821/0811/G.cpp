
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Elp{
public:
  int w, s, i;
  Elp(int w, int s, int i){
    this->w = w;
    this->s = s;
    this->i = i;
  }
};

bool comp(Elp a, Elp b){
  return a.w < b.w;
}

int main(){
  ios::sync_with_stdio(false);

  vector<Elp> v;

  int w, s;
  int k = 0;
  while(cin >> w >> s){
    v.push_back(Elp(w, s, k));
    k++;
  }

  sort(v.begin(), v.end(), comp);

  pair<int, int> *prev = new pair<int, int>[v.size()];
  for(int i = 0; i < v.size(); i++)
    prev[i] = make_pair(i, 1);

  int p = 0;
  for(int i = 0; i < v.size(); i++){
    for(k = 0; k < i; k++){
      if(v[k].w < v[i].w && v[k].s > v[i].s && prev[k].second + 1 > prev[i].second){
        prev[i].first = k;
        prev[i].second = prev[k].second + 1;
      }
    }

    if(prev[i].second > prev[p].second)
      p = i;
  }

  cout << prev[p].second << endl;

  vector<int> ints;
  ints.push_back(v[p].i + 1);
  while(prev[p].first != p){
    p = prev[p].first;
    ints.push_back(v[p].i + 1);
  }

  for(int i = ints.size() - 1; i >= 0; i--)
    cout << ints[i] << endl;



  return 0;
}
