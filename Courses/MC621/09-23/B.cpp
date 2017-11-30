// B. Scrolling Sign

#include <iostream>

using namespace std;

int main(){
  int n, k, w, l;
  string word1, word2;
  cin >> n;
  while(n--){
    cin >> k >> w;
    cin >> word1;
    w--;
    l = k;
    while(w--){
      cin >> word2;

      for(int i = 0; i <= k; i++){
        int j = 0;
        while(word1[i + j] == word2[j] && i + j < k)
          j++;
        if(i + j == k){
          l += k - j;
          break;
        }
      }

      word1 = word2;
    }
    cout << l << "\n";

  }
  return 0;
}
