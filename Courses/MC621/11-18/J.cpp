// J. Amusing number

#include <iostream>

using namespace std;

int main(){
  long long n, k;
  cin >> n;
  while(n--){
    cin >> k;
    k++;
    bool flag = false;
    for(int i = 60; i >= 0; i--){
      if(!flag && (k & (1LL << i)) > 0)
        flag = true;

      else if(flag && (k & (1LL << i)) > 0)
        cout << 6;
      else if(flag && (k & (1LL << i)) == 0)
        cout << 5;
    }
    cout << endl;
  }
  return 0;
}
