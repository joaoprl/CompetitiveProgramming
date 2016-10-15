// A. Room Change

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void computePrimes(int n, vector<long long> &v){
  long long *arr = new long long[n];

  v.push_back(2);
  for(int i = 3; i < n; i += 2){
    if(arr[i] == 0){
      for(int j = i; j < n; j += 2 * i)
        arr[j] = 1;
      v.push_back(i);
    }
  }

  delete[] arr;
}

int main(){
  long long q, root;
  cin >> q;
  root = (long long)pow(root, 0.5) + 1;

  vector<long long> v;
  computePrimes(root, v);

  for(int i = 0; i < v.size(); i++){
    if(q % v[i] == 0){
      if(v[i] * v[i] != q)
        cout << "MARIAN\n";
      else
        cout << "ANNE\n";
      break;
    }
  }


  return 0;
}
