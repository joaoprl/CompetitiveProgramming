// E. Knapsack

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

double solve(vector< pair<int, double> > &m, int x, double *arr){
  if(x <= 0)
    return 0;
  else if(arr[x] >= 0)
    return arr[x];
  else{
    double v = INT_MAX;
    for(int i = 0; i < m.size(); i++){
      v = min(v, m[i].second + solve(m, x - m[i].first, arr));
    }
    return (arr[x] = v);
  }
  return 0;
}

int main(){
  int x, M, wi;
  double pi;
  vector< pair<int, double> > m;
  cin >> x >> M;

  double *arr = new double[x + 1];

  for(int i = 0; i <= x; i++)
    arr[i] = -1;
  arr[0] = 0;

  for(int i = 0; i < M; i++){
    pair<int, double> p;

    cin >> wi >> pi;
    p.first = wi;
    p.second = pi;

    m.push_back(p);
  }
  printf("%.2lf\n", solve(m, x, arr));

  return 0;
}
