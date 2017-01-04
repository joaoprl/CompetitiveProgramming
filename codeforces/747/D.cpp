// D. Winter Is Coming

#include <iostream>
#include <vector>

#define WINTER 0
#define SUMMER 1
#define N 200010

using namespace std;


int main(){
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  int *temp = new int[n];
  int fr = 0;
  for(int i = 0; i < n; i++){
    cin >> temp[i];
    if(temp[i] < 0)
      fr++;
  }
  if(fr > k){
    cout << "-1\n";
    return 0;
  }
  k -= fr;

  int acc = 0;
  vector<int> nf;
  for(int i = 0; i < n; i++){
    if(temp[i] < 0){
      if(acc > 0)
        nf.push_back(acc);
      acc = 0;
    }
    else
      acc++;
  }

  if(acc > 0)
    nf.push_back(acc);
  int **tab = new int*[nf.size()];
  for(int i = 0; i < nf.size(); i++)
    tab[i] = new int[k];

  for(int j = 0; j < k; j++)
    tab[0][j] = 0;

  for(int i = 0; i < k; i++){
    for(int j = 0; j < nf.size(); j++){
      if(nf)
    }
  }


  return 0;
}
