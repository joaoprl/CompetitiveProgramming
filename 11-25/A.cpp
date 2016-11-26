// A. Common Permutation

#include <iostream>

#define AB_SIZE ('z' - 'a' + 1)

using namespace std;

int main(){
  string a, b;
  char *ab1 = new char[AB_SIZE], *ab2 = new char[AB_SIZE];

  while(cin >> a >> b){
    for(int i = 0; i < AB_SIZE; i++)
      ab1[i] = ab2[i] = 0;

    for(int i = 0; i < a.length(); i++)
      ab1[a[i] - 'a']++;

    for(int i = 0; i < b.length(); i++)
      ab2[b[i] - 'a']++;

    for(int i = 0; i < AB_SIZE; i++){
      int n = min(ab1[i], ab2[i]);
      while(n--){
        cout << (char)(i + 'a');
      }
    }

    cout << endl;
  }
  
  return 0;
}
