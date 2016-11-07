// E. Restaurant

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pairComp(pair<int, int> i, pair<int, int> j){
  return i.second < j.second;
}

int main(){
  int n;
  cin >> n;

  vector< pair<int, int> > orders;

  int begin, end;
  for(int i = 0; i < n; i++){
    cin >> begin >> end;
    orders.push_back(make_pair(begin, end));
  }

  sort(orders.begin(), orders.end(), pairComp);

  int last = 0, count = 1;
  for(int i = 1; i < n; i++){
    if(orders[last].second < orders[i].first){
      count++;
      last = i;
    }
  }

  cout << count << "\n";

  return 0;

}
