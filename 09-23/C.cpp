// C. War of the Corporations

#include <iostream>

using namespace std;

int main(){
  string str, subStr;
  cin >> str >> subStr;

  int i = 0, j = -1, k = 0;
  int *b = new int[subStr.size() + 1];
  b[0] = -1;

  while(i < subStr.size()){
    while(j >= 0 && subStr[i] != subStr[j])
      j = b[j];
    i++; j++;
    b[i] = j;
  }

  i = j = k = 0;
  while(i < str.size()){
    while(j >= 0 && str[i] != subStr[j])
      j = b[j];
    i++; j++;

    if(j == subStr.size()){
      k++;
      j = 0;
    }
  }
  delete[] b;
  cout << k << "\n";
}
