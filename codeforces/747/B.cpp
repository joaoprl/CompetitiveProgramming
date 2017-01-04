// B. Mammoth's Genome Decoding

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  string gen;
  cin >> n >> gen;
  int a, c, g, t;
  a = c = g = t = 0;
  for(int i = 0; i < n; i++){
    if(gen[i] == 'A')
      a++;
    if(gen[i] == 'C')
      c++;
    if(gen[i] == 'G')
      g++;
    if(gen[i] == 'T')
      t++;
  }

  if(n % 4 != 0 || (a > n / 4 || c > n / 4 || g > n / 4 || t > n / 4)){
    cout << "===\n";
    return 0;
  }

  for(int i = 0; i < n; i++){
    if(gen[i] == '?'){
      if(a < n / 4){
        gen[i] = 'A';
        a++;
      }
      else if(c < n / 4){
        gen[i] = 'C';
        c++;
      }
      else if(g < n / 4){
        gen[i] = 'G';
        g++;
      }
      else if(t < n / 4){
        gen[i] = 'T';
        t++;
      }
    }
  }

  cout << gen << endl;

  return 0;
}
