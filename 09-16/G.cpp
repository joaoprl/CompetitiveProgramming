// G. To and Fro

#include <iostream>
#include <string>

#define N 200

using namespace std;

int main(){
  string input;
  char *output = new char[N];
  int n;
  cin >> n;
  while(n != 0){
    cin >> input;

    int c = 0;
    for(int i = 0; i < n; i++){
      for(int k = 0; k < input.size() / n; k += 2){
        output[c++] = input[k * n + i];
        if(k * n + 2 * n - 1 - i < input.size())
          output[c++] = input[k * n + 2 * n - 1 - i];
      }
    }
    output[c] = '\0';
    cout << output << "\n";
    cin >> n;
  }
  return 0;
}
