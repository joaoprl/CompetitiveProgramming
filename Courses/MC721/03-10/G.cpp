// G. Bolsa de Valores
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  while(cin >> n && n > 0){
    char t;
    double v;
    double total = 0;
    vector<double> compra, venda;
    make_heap(compra.begin(), compra.end());
    make_heap(venda.begin(), venda.end(), greater<double>());
    while(n--){
      cin >> t >> v;
      if(t == 'C'){
        if(!venda.empty() && venda.front() <= v){
          total += v - venda.front();
          pop_heap(venda.begin(), venda.end(), greater<double>());
          venda.pop_back();
        }
        else{
          compra.push_back(v);
          push_heap(compra.begin(), compra.end());
        }
      }
      if(t == 'V'){
        if(!compra.empty() && compra.front() >= v){
          total += compra.front() - v;
          pop_heap(compra.begin(), compra.end());
          compra.pop_back();
        }
        else{
          venda.push_back(v);
          push_heap(venda.begin(), venda.end(), greater<double>());
        }
      }
    }
    cout << fixed << setprecision(2) << total << endl;
  }

  return 0;
}
