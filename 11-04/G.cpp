// G. The Maximize Sum

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t, n;
  cin >> t;

  vector<int> negatives, positives;
  int num;

  while(t--){
    cin >> n;
    negatives.clear();
    positives.clear();

    for(int i = 0; i < n; i++){
      cin >> num;
      if(num > 0)
        positives.push_back(num);
      else
        negatives.push_back(num);
    }

    sort(positives.begin(), positives.end(), greater<int>());
    sort(negatives.begin(), negatives.end());

    long long total = 0;
    for(unsigned int i = 0; i < negatives.size(); i += 2){
      if(i == negatives.size() - 1)
        total += negatives[i];
      else
        total += negatives[i] * negatives[i + 1];
    }
    for(unsigned int i = 0; i < positives.size(); i += 2){
      if(i == positives.size() - 1)
        total += positives[i];
      else{
        if(positives[i] + positives[i + 1] > positives[i] * positives[i + 1])
          total += positives[i] + positives[i + 1];
        else
          total += positives[i] * positives[i + 1];
      }
    }

    cout << total << "\n";

  }
  return 0;
}
