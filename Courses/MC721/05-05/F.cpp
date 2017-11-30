
#include <iostream>

using namespace std;

int **m

void compute(string str, int n, int cur, int k, int p, string &fin){
  if(p == n && k == abs(cur)){
    fin = str;
    return;
  }
  if(abs(cur) == k)
    return;

  if(str[p] == 'L')
    compute(str, n, cur - 1, k, p + 1, fin);
  if(fin != "")
    return;
  if(str[p] == 'W')
    compute(str, n, cur + 1, k, p + 1, fin);
  if(fin != "")
    return;
  if(str[p] == 'D')
    compute(str, n, cur, k, p + 1, fin);
  if(fin != "")
    return;
  if(str[p] == '?'){
    str[p] = 'L';
    compute(str, n, cur - 1, k, p + 1, fin);
    if(fin != "")
      return;
    str[p] = 'W';
    compute(str, n, cur + 1, k, p + 1, fin);
    if(fin != "")
      return;
    str[p] = 'D';
    compute(str, n, cur, k, p + 1, fin);
  }
}

int main(){
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  string str;
  cin >> str;
  string fin = "";
  m = new int*[k];
  for(int i = 0; i < k; i++){
    m[i] = new int[4];
    for(int j = 0; j < 4; j++)
      m[i][j] = -1;
  }
  compute(str, n, 0, k, 0, fin);
  if(fin == "")
    cout << "NO" << endl;
  else
    cout << fin << endl;

  return 0;
}
