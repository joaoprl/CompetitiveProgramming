
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class cup{
public:
  int a, p, v;
  cup(int a, int p, int v){
    this-> a = a;
    this-> p = p;
    this -> v = v;
  }
};

bool g1(cup a, cup b){
  return a.a < b.a;
}

bool g2(cup a, cup b){
  return a.p < b.p;
}

int main(){
  ios::sync_with_stdio(false);

  int n, w;
  cin >> n >> w;
  vector<cup> cups;
  int a, sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a;
    cups.push_back(cup(a, i, (a + 1) / 2));
    sum += (a + 1) / 2;
  }

  sort(cups.begin(), cups.end(), g1);

  if(sum > w){
    cout << -1 << endl;
  }else{
    w -= sum;
    for(int i = n - 1; i >= 0 && w > 0; i--){
      int d = min(w, cups[i].a - cups[i].v);
      cups[i].v += d;
      w -= d;
    }

    sort(cups.begin(), cups.end(), g2);
    cout << cups[0].v;
    for(int i = 1; i < n; i++){
      cout << " " << cups[i].v;
    }
    cout << endl;
  }




  return 0;
}
