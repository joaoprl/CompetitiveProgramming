// F. Cows and Cars

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  double cows, cars, open;
  while(cin >> cows >> cars >> open){
    double doors = cars + cows;
    double prob = cars / doors;
    prob += open * prob / (doors - open - 1);

    cout << fixed << setprecision(5) << prob << endl;
  }

  return 0;
}
