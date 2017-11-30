
#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1300031
#define int long long

using namespace std;

int compute(int I, int F, int N){
  int A = (I % N == 0 ? I : I - I % N + N);
  int B = (F % N == 0 ? F : F - F % N);

  return ((A + B) * (B - A + N) / (2 * N)) % MOD;
}

int32_t main(){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for(int c = 0; c < t; c++){
    int I, F, N;
    cin >> I >> F >> N;
    vector<int> nums(N, 0);
    for(int i = 0; i < N; i++)
      cin >> nums[i];

    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] != 0){
        for(int j = i + 1; j < nums.size(); j++){
          if(nums[j] % nums[i] == 0){
            nums[j] = 0;
          }
        }
      }
    }

    vector<int> facts;
    for(int i = 0; i < nums.size(); i++)
      if(nums[i] != 0)
        facts.push_back(nums[i]);

    int out = 0;
    for(int mask = 1; mask < (1 << facts.size()); mask++){
      int k = 1;
      int count = 0;
      for(int i = 0; i < facts.size(); i++){
        if((mask & (1 << i)) != 0){
          k *= facts[i];
          count++;
        }
      }
      if(count % 2 == 0)
        out = (MOD + out - compute(I, F, k)) % MOD;
      else
        out = (out + compute(I, F, k)) % MOD;
    }
    cout << out << endl;
  }

  return 0;
}
