
#include <iostream>
#include <sstream>
#include <vector>

#define N 110

using namespace std;

string out(int n){
  ostringstream convert;
  string str = "";
  if(n < 10)
    str += "  ";
  else if(n < 100)
    str += " ";
  convert << n;
  str += convert.str();

  return str;
}

int main(){
  int n;
  int **m = new int*[N];
  for(int i = 0; i < N; i++){
    m[i] = new int[N];
    for(int j = 0; j < N; j++)
      m[i][j] = 0;
  }

  vector<int> primes;
  int *primesV = new int[N];
  for(int i = 0; i < N; i++)
    primesV[i] = 1;

  for(int i = 2; i < N; i++){
    if(primesV[i] == 1){
      primes.push_back(i);
      for(int j = i; j < N; j += i)
        primesV[j] = 0;
    }
  }

  m[2][2] = 1;
  for(int i = 3; i < N; i++){
    for(int j = 0; j < N; j++){
      m[i][j] = m[i - 1][j];
    }

    for(int j = 0; j < primes.size(); j++){
      int num = i;
      while(num % primes[j] == 0){
        m[i][primes[j]]++;
        num /= primes[j];
      }
    }
  }

  while(cin >> n && n > 0){
    cout << out(n) << "! =";
    for(int i = 0; i < primes.size() && primes[i] <= n; i++){
      if(i % 15 == 0 && i > 0)
        cout << endl << "      ";
      cout << out(m[n][primes[i]]);
    }
    cout << endl;
  }
}
