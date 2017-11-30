
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, num;
  int c = 1;
  while(cin >> n && n != 0){
    vector<int> v;
    for(int i = 0; i < n; i++){
      cin >> num;
      v.push_back(num);
    }
    sort(v.begin(), v.end());

    int count = 0;
    int a = 0;
    int b = v.size() - 1;
    while(a < b){
      if(v[a] + v[b] >= 20){
        count++;
        a++;
        b--;
      }else
        a++;
    }

    cout << "Case " << c++ << ": " << count << endl;
  }

  return 0;
}
