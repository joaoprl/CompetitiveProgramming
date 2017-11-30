
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  long long d[3];
  string st;

  while(cin >> st){
    long long count = 0;
    d[0] = d[1] = d[2] = 0;
    for(int i = 0; i < st.length(); i++){
      if(st[i] >= '0' && st[i] <= '9'){
        int v = st[i] - '0';
        v %= 3;

        if(v == 1){
          swap(d[1], d[2]);
          swap(d[0], d[1]);
        }
        if(v == 2){
          swap(d[0], d[1]);
          swap(d[1], d[2]);
        }
        d[v]++;
        count += d[0];
      }else{
        d[0] = d[1] = d[2] = 0;
      }
    }
    cout << count << endl;
  }

  return 0;
}
