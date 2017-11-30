
#include <iostream>

#define INF 1000000000

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int a, d;
  while(cin >> a >> d && (a != 0 || d != 0)){
    int b1 = INF, b;
    for(int i = 0; i < a; i++){
      cin >> b;

      if(b < b1)
        swap(b, b1);
    }

    int c, c1 = INF, c2 = INF;
    for(int i = 0; i < d; i++){
      cin >> c;
      if(c < c1)
        swap(c, c1);
      if(c < c2)
        swap(c, c2);
    }

    if(b1 < c2)
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }

  return 0;
}
