
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  string a, b;
  while(cin >> a >> b && (a != "*" || b != "*")){
    int count = 0;
    for(int i = 0; i < a.length(); i++){
      int j = i;
      while(a[j] != b[j]){
        j++;
      }
      if(a[i] != b[i]){
        count++;
        i = j;
      }
    }
    cout << count << endl;
  }

  return 0;
}
