// F. Teletransport
// F. Teletransporte

#include <iostream>
#include <vector>

#define N 110
#define MOD 10000

using namespace std;

vector< vector<int> > prod(vector< vector<int> > a, vector< vector<int> > b){
  vector< vector<int> > r;

  for(int i = 0; i < a.size(); i++){
    r.push_back(vector<int>());
    r[i].assign(b[0].size(), 0);
  }

  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < b[0].size(); j++){
      r[i][j] = 0;
      for(int k = 0; k < b.size(); k++){
        r[i][j] += (a[i][k] * b[k][j]) % MOD;
        r[i][j] %= MOD;
      }
    }
  }

  return r;
}

void print(vector< vector<int> > v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[0].size(); j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

vector< vector<int> > exp(vector< vector<int> > m, int l){
  if(l == 0){

    for(int i = 0; i < m.size(); i++){
      for(int j = 0; j < m[0].size(); j++)
        m[i][j] = 0;
      m[i][i] = 1;
    }
    return m;
  }
  if(l == 1)
    return m;
  if(l == 2)
    return prod(m, m);

  vector< vector<int> > r;
  r = exp(m, l / 2);
  r = prod(r, r);

  if(l % 2 == 1)
    r = prod(r, m);

  // cout << l << endl;
  // print(r);
  // cout << endl;
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  int n, l, s, t, x;

  vector< vector<int> > m, r;

  while(cin >> n >> l){
    cin >> s >> t;
    m.clear();
    r.clear();

    for(int i = 0; i < n; i++){
      m.push_back(vector<int>());
      m[i].assign(n, 0);
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < 4; j++){
        cin >> x;
        m[i][x - 1]++;
      }
    }
    r = exp(m, l);

    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     cout << m[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    //
    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     cout << r[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    cout << r[s - 1][t - 1] << endl;

  }

  return 0;
}
