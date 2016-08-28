// I. The Department of Redundancy Department

#include <iostream>
#include <map>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int x = 0;

  map<int, int> m;
  vector<int> v;
  

  while(cin.peek() != EOF && (cin >> x)){
    if(m[x] == 0)
      v.push_back(x);
    m[x]++;
  }

  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " " << m[v[i]] << "\n";
  
  return 0;
}
