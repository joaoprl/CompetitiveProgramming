// C. Running Median

#include <iostream>
#include <algorithm>
#include <vector>

#define N 100001

using namespace std;

bool iComp(int a, int b){
  return a > b;
}

int main(){
  ios::sync_with_stdio(false);
  vector<int> minor, maxi;

  int num;
  while(cin >> num){
    if(num == 0){
      minor.clear();
      maxi.clear();
      continue;
    }
    else if(num == -1){
      pop_heap(minor.begin(), minor.end());
      cout << minor.back() << "\n";
      minor.pop_back();

      if(maxi.size() > minor.size()){
        pop_heap(maxi.begin(), maxi.end(), iComp);
        minor.push_back(maxi.back());
        push_heap(minor.begin(), minor.end());
        maxi.pop_back();
      }
    }
    else{
      if(minor.size() == 0 || num <= minor.front()){
        minor.push_back(num);
        push_heap(minor.begin(), minor.end());

        if(minor.size() > maxi.size() + 1){
          pop_heap(minor.begin(), minor.end());
          maxi.push_back(minor.back());
          push_heap(maxi.begin(), maxi.end(), iComp);
          minor.pop_back();
        }
      }
      else{
        maxi.push_back(num);
        push_heap(maxi.begin(), maxi.end(), iComp);

        if(maxi.size() > minor.size()){
          pop_heap(maxi.begin(), maxi.end(), iComp);
          minor.push_back(maxi.back());
          push_heap(minor.begin(), minor.end());
          maxi.pop_back();
        }
      }
    }
  }

  return 0;
}
