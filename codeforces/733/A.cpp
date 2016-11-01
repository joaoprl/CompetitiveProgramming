// A. Grasshopper And the String

#include <iostream>

using namespace std;

bool isVowel(char c){
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main(){
  char c;
  int hop = 0, count = 1;

  while(cin >> c){
    if(isVowel(c)){
      hop = max(hop, count);
      count = 1;
    }
    else {
      count++;
      hop = max(hop, count);
    }
  }

  cout << hop << "\n";

  return 0;
}
