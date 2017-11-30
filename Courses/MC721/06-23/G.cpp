
#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, k = -1, l = -1;
  cin >> n;
  int *a = new int[n];
  int *b = new int[n];
  int *p = new int[n];
  unordered_set<int> s;

  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < n; i++)
    cin >> b[i];
  for(int i = 0; i < n; i++){
    if(a[i] == b[i]){
      p[i] = a[i];
      s.insert(p[i]);
    }
    else{
      p[i] = 0;
      if(k == -1)
        k = i;
      else
        l = i;
    }
  }

  if(l == -1){
    int num = 0;
    for(int i = 1; i <= n; i++){
      if(s.find(i) == s.end()){
        num = i;
        break;
      }
    }

    p[k] = num;
  }
  else if(s.find(a[k]) != s.end()){
    p[k] = b[k];
    p[l] = a[l];
  }
  else if(s.find(b[k]) != s.end()){
    p[k] = a[k];
    p[l] = b[l];
  }
  else if(s.find(a[l]) != s.end()){
    p[l] = b[l];
    p[k] = a[k];
  }
  else if(s.find(b[l]) != s.end()){
    p[l] = a[l];
    p[k] = b[k];
  }else{
    p[l] = a[l];
    p[k] = b[k];
  }

  cout << p[0];
  for(int i = 1; i < n; i++){
    cout << " " << p[i];
  }
  cout << endl;

  return 0;
}
