// D. Dire wolf

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

#define INF INT_MAX
#define N 200

using namespace std;

int get(vector<int> &b, int i){
  if(i >= 0 && i < b.size())
    return b[i];
  return 0;
}

int rSolve(vector<int> &a, vector<int> &b, int **m, int l, int r){
  if(l > r)
    return 0;
  
  if(m[l][r] != INF)
    return m[l][r];

  for(int i = l; i <= r; i++)
    m[l][r] = min(m[l][r],
		  get(b, l - 1) + get(b, r + 1) + rSolve(a, b, m, l, i - 1) + rSolve(a, b, m, i + 1, r) + a[i]);
  
  return m[l][r];	     
}

int solve(vector<int> &a, vector<int> &b, int** m){  
  for(int i = 0; i < a.size() ; i++){
    for(int j = 0; j < a.size() ; j++)
      m[i][j] = INF;
  }

  return rSolve(a, b, m, 0, a.size() - 1);
}

int main(){  
  int t, n, v;
  cin >> t;

  vector<int> a, b;
  int** m = new int*[N];
  for(int i = 0; i < N; i++)
    m[i] = new int[N];

  for(int x = 1; x <= t; x++){
    cin >> n;

    for(int i = 0; i < n; i++){
      cin >> v;
      a.push_back(v);
    }
    for(int i = 0; i < n; i++){
      cin >> v;
      b.push_back(v);
    }
    
    printf("Case #%d: %d\n", x, solve(a, b, m));

    a.clear();
    b.clear();
  }

  for(int i = 0; i < N; i++)
    delete[] m[i];
  delete[] m;
  
  return 0;
}
