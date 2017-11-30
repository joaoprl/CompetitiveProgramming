// E. Army Buddies

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int b, s;
  while(cin >> s >> b && b > 0 && s > 0){
    vector< pair<int, int> >sol;
    for(int i = 0; i <= s + 1; i++)
      sol.push_back(make_pair(i - 1, i + 1));

    int l, r;
    for(int i = 0; i < b; i++){
      cin >> l >> r;
      sol[sol[r].second].first = sol[l].first;
      sol[sol[l].first].second = sol[r].second;

      if(sol[sol[r].second].first <= 0)
        cout << '*';
      else
        cout << sol[sol[r].second].first;
      cout << " ";

      if(sol[sol[l].first].second > s)
        cout << '*';
      else
        cout << sol[sol[l].first].second;
      cout << endl;
    }
    cout << "-\n";
  }
  return 0;
}
