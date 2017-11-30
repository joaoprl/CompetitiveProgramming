
#include <iostream>
#include <vector>
#include <set>

#define CHR 30

using namespace std;

void kmpPreprocess(vector<int> p, vector<int> &b){
  int i = 0, j = -1;
  b.push_back(-1);
  while(i < p.size()){
    while(j >= 0 && p[i] != p[j]) j = b[j];
    i++; j++;
    b.push_back(j);
  }
}

bool isInvalidSet(vector<char> &map, vector<int> s, string t, vector<int> p, int i, int j){
  if(map[p[j]] != 0 && map[p[j]] == t[i])
    return false;

  map.assign(CHR, 0);
  set<char> charSet;
  for(int k = 0; k < CHR; k++){
    if(s[k] != -1){
      char c = t[s[k] + i - j];
      cout << c << ", " << k << " " << s[k] << " " << i << " " << j << endl;

      if(charSet.find(c) != charSet.end()){
        map.assign(CHR, 0);
        cout << "repeated" << endl;
        return true;
      }

      map[k] = c;
      charSet.insert(c);
    }
  }
  cout << endl;

  if(map[p[j]] != 0 && map[p[j]] == t[i])
    return false;

  map.assign(CHR, 0);
  return true;
}

vector<int> kmpSearch(const string &t, const vector<int> &p, const vector<int> &b, vector<int> set, vector<char> map){
  map.assign(CHR, 0);

  vector<int> v;
  int i = 0, j = 0;
  while(i < t.size()){
    while(j >= 0 && isInvalidSet(map, set, t, p, i, j)) j = b[j];
    i++; j++;
    if(j == p.size()){
      v.push_back(i - j);
      j = b[j];
    }
  }

  return v;
}

void setInitialize(const vector<int> &p, vector<int> &set){
  for(int i = 0; i < p.size(); i++){
    if(set[p[i]] == -1)
      set[p[i]] = i;
  }
}

int main(){
  ios::sync_with_stdio(false);
  string t;
  int n;
  cin >> t >> n;

  vector<int> p(n, 0), b, out;
  for(int i = 0; i < n ; i++)
    cin >> p[i];

  vector<char> map(CHR, 0);
  vector<int> set(CHR, -1);

  setInitialize(p, set);
  kmpPreprocess(p, b);
  out = kmpSearch(t, p, b, set, map);

  cout << out.size() << endl;
  for(int i = 0; i < out.size(); i++)
    cout << out[i] << " ";
  cout << endl;

  return 0;
}
