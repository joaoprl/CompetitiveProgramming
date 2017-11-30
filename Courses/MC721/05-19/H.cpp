
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int k, w;

  while(cin >> k >> w && (k != 0 || w != 0)){
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    map< pair<int, int>, int> readen;

    int a, b;
    bool possible = true;
    for(int i = 0; i < w; i++){
      cin >> a >> b;
      if(readen[make_pair(a, b)] == 1)
        continue;
      readen[make_pair(a, b)] = 1;
      readen[make_pair(b, a)] = 1;


      if(m2[a] == 0)
        m2[a] = 1;
      else if(m2[a] == 1)
        m2[a] = 2;
      else{
         possible = false;
       }

       if(m2[b] == 0)
         m2[b] = 1;
       else if(m2[a] == 1)
         m2[b] = 2;
       else{
          possible = false;
        }

      int c = b;
      while(m1[c] != 0)
        c = m1[c];

      int d = a;
      while(m1[d] != 0)
        d = m1[d];

      if(c != d)
        m1[c] = d;
      else if(m1.size() != k){
        possible = false;
      }
    }

    if(possible)
      cout << "Y" << endl;
    else
      cout << "N" << endl;

  }

  return 0;
}
