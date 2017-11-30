// G. Hotel Rewards

#include <iostream>
#include <algorithm>

using namespace std;

bool op(int a, int b){
  return a > b;
}

int main(){
  int n, k, *p;
  cin >> n >> k;
  p = new int[n];

  for(int i = 0; i < n; i++)
    cin >> p[i];

  int acc = 0;
  int sum = 0;
  vector<int> v;
  for(int i = 0; i < n; i++){
    if(acc >= k){
      v.push_back(p[i]);
      push_heap(v.begin(), v.end(), op);
      acc -= k;
    }
    else if(v.size() >  0 && v[0] < p[i]){
      sum += v[0];
      pop_heap(v.begin(), v.end(), op);
      v.pop_back();
      v.push_back(p[i]);
      push_heap(v.begin(), v.end(), op);
      acc++;
    }
    else{
      sum += p[i];
      acc++;
    }
  }

  cout << sum << endl;

  return 0;
}
