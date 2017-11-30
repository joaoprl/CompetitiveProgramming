
#include <iostream>
#include <algorithm>

#define M 1010

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  pair<int, int> *a = new pair<int, int>[M];
  pair<int, int> *b = new pair<int, int>[M];
  while(n--){
    int m,  num;
    cin >> m;
    for(int i = 0; i < m; i++){
      cin >> num;
      a[i] = b[i] = make_pair(num, i);
    }
    sort(a, a + m, greater<pair<int, int> >());

    int count = 0;
    for(int i = 0; i < m; i++){
      if(a[i].second == b[i].second)
        count++;
    }

    cout << count << endl;
  }

  return 0;
}
