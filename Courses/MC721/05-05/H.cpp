
#include <iostream>

#define TOTAL 10010
#define INF 1000000

using namespace std;

int c(int a, int b, int c, int d){
  return 1000 * a + 100 * b + 10 * c + d;
}

int *d;

int compute(bool *forbid, int a1, int a2, int a3, int a4, int t1, int t2, int t3, int t4, int n){
  if(forbid[c(a1, a2, a3, a4)])
    return INF;
  if(c(a1, a2, a3, a4) == c(t1, t2, t3, t4))
    return 0;

  int m = INF;

  forbid[c(a1, a2, a3, a4)] = true;
  if(n == 1){
    for(int i = 1; i <= 4; i++){
      m = min(m, compute(forbid, (a1 + 11) % 10, a2, a3, a4, t1, t2, t3, t4, i));
      m = min(m, compute(forbid, (a1 + 9) % 10, a2, a3, a4, t1, t2, t3, t4, i));
    }
  }
  else if(n == 2){
    for(int i = 1; i <= 4; i++){
      m = min(m, compute(forbid, a1, (a2 + 11) % 10, a3, a4, t1, t2, t3, t4, i));
      m = min(m, compute(forbid, a1, (a2 + 9) % 10, a3, a4, t1, t2, t3, t4, i));
    }

  }
  else if(n == 3){
    for(int i = 1; i <= 4; i++){
      m = min(m, compute(forbid, a1, a2, (a3 + 11) % 10, a4, t1, t2, t3, t4, i));
      m = min(m, compute(forbid, a1, a2, (a3 + 9) % 10, a4, t1, t2, t3, t4, i));
    }

  }
  else if(n == 4){
    for(int i = 1; i <= 4; i++){
      m = min(m, compute(forbid, a1, a2, a3, (a4 + 11) % 10, t1, t2, t3, t4, i));
      m = min(m, compute(forbid, a1, a2, a3, (a4 + 9) % 10, t1, t2, t3, t4, i));
    }
  }
  forbid[c(a1, a2, a3, a4)] = false;

  if(m == INF)
    return INF;
  return m + 1;
}

int main(){
  ios::sync_with_stdio(false);

  int n;
  int a1, a2, a3, a4;
  int t1, t2, t3, t4;

  bool *forbid = new bool[TOTAL];
  d = new int[TOTAL;]

  cin >> n;
  while(n--){
    cin >> a1 >> a2 >> a3 >> a4;
    cin >> t1 >> t2 >> t3 >> t4;

    for(int i = 0; i < TOTAL; i++)
      forbid[i] = false;

    for(int i = 0; i < TOTAL; i++)
      d[i] = -1;


    int f, f1, f2, f3, f4;
    cin >> f;
    for(int i = 0; i < f; i++){
      cin >> f1 >> f2 >> f3 >> f4;
      forbid[c(f1, f2, f3, f4)] = true;
    }
    cout << "here" << endl;
    int m = INF;
    m = min(m, compute(forbid, a1, a2, a3, a4, t1, t2, t3, t4, 1));
    m = min(m, compute(forbid, a1, a2, a3, a4, t1, t2, t3, t4, 2));
    m = min(m, compute(forbid, a1, a2, a3, a4, t1, t2, t3, t4, 3));
    m = min(m, compute(forbid, a1, a2, a3, a4, t1, t2, t3, t4, 4));
    if(m == INF)
      cout << -1 << endl;
    else
      cout << m << endl;

  }
  return 0;
}
