
#include <iostream>
#include <vector>
#include <algorithm>

#define M 110

using namespace std;

int sum(int* a, int* b, int *c){
  int car = 0;
  for(int i = M - 1; i >= 0; i--){
    c[i] = a[i] + b[i] + car;
    car = c[i] / 10;
    c[i] %= 10;
  }
  return car;
}

bool comp(int *a, int *b){
  for(int i = 0; i < M; i++){
    if(a[i] != b[i])
      return a[i] < b[i];
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);

  vector<int*> fib;

  fib.push_back(new int[M]);
  fib.push_back(new int[M]);
  fib.push_back(new int[M]);

  fib[0][M - 1] = 1;
  fib[1][M - 1] = 2;

  fib.push_back(new int[M]);
  int k = 2;
  while(sum(fib[k - 2], fib[k - 1], fib[k]) == 0){
    fib.push_back(new int[M]);
    k++;
  }

  string a, b;
  int *pA = new int[M];
  int *pB = new int[M];
  while(cin >> a >> b && (a != "0" || b != "0")){
    for(int i = 0; i < M; i++)
      pA[i] = pB[i] = 0;

    for(int i = 0; i < a.length(); i++)
      pA[M - i - 1] = a[a.length() - i - 1] - '0';

    for(int i = 0; i < b.length(); i++)
      pB[M - i - 1] = b[b.length() - i - 1] - '0';

    int posA = lower_bound(fib.begin(), fib.end(), pA, comp) - fib.begin();
    int posB = upper_bound(fib.begin(), fib.end(), pB, comp) - fib.begin();

    cout << posB - posA << endl;

  }



  return 0;
}
