// C. Building Designing

#include <iostream>
#include <vector>
#include <algorithm>

#define INF ((int)1e9)

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int p;
  cin >> p;
  while(p--){

    int numFlors, f;
    vector<int> blue, red;

    cin >> numFlors;
    for(int i = 0; i < numFlors; i++){
      cin >> f;
      if(f > 0)
        blue.push_back(f);
      else
        red.push_back(-f);
    }
    sort(blue.begin(), blue.end(), greater<int>());
    sort(red.begin(), red.end(), greater<int>());

    bool flag;
    int last;
    int bP = 0, rP = 0;
    if(blue[0] > red[0]){
      flag = true;
      last = blue[0];
      bP = 1;
    }
    else{
      flag = false;
      last = red[0];
      rP = 1;
    }

    int count = 1;
    while(rP < red.size() && bP < blue.size()){
      if(flag){
        rP = upper_bound(red.begin() + rP, red.end(), last, greater<int>()) - red.begin();
        if(rP < red.size()){
          last = red[rP];
          rP++;
          count++;
          flag = !flag;
        }
      }
      else{
        bP = upper_bound(blue.begin() + bP, blue.end(), last, greater<int>()) - blue.begin();
        if(bP < blue.size()){
          last = blue[bP];
          bP++;
          count++;
          flag = !flag;
        }
      }
    }
    if(flag){
      rP = upper_bound(red.begin() + rP, red.end(), last, greater<int>()) - red.begin();
      if(rP < red.size()){
        last = red[rP];
        rP++;
        count++;
        flag = !flag;
      }
    }
    else{
      bP = upper_bound(blue.begin() + bP, blue.end(), last, greater<int>()) - blue.begin();
      if(bP < blue.size()){
        last = blue[bP];
        bP++;
        count++;
        flag = !flag;
      }
    }

    cout << count << endl;
    

  return 0;
}
