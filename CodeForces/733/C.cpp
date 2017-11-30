// C. Epidemic in Monstropolis

#include <iostream>
#include <string>

using namespace std;

bool valid(int *begin, int a, int b, int k, int value, string &output){
  if(a == b){
    return true;
  }

  bool isValid = false;
  int m = begin[a];
  for(int i = a + 1; i <= b; i++){
    m = max(m, begin[i]);
    if(begin[i] != begin[a])
      isValid = true;
  }
  if(!isValid)
    return false;

  int pos = a;
  char c = 'R';
  for(int i = a; i < b; i++){
    if(begin[i] != m && begin[i + 1] == m){
      pos = i + 1;
      c = 'L';
      break;
    }
    if(begin[i] == m && begin[i + 1] != m){
      pos = i;
      c = 'R';
      break;
    }
  }
  int pos2 = pos - a + k;
  output = output + to_string(pos2) + " " + c + "\n";
  if(c == 'L'){
    pos2--;
    a++;
  }
  if(c == 'R'){
    b--;
  }

  for(int i = pos; i < b; i++){
    output = output + to_string(pos2) + " " + 'R' + "\n";
  }

  for(int i = pos; i > a; i--){
    output = output + to_string(pos2) + " " + 'L' + "\n";
    pos2--;
  }

  return true;
}

int main(){
  string output;
  int n, k;
  cin >> n;
  int *begin = new int[n + 1];
  for(int i = 1; i <= n; i++)
    cin >> begin[i];

  cin >> k;
  int *end = new int[k + 1];
  for(int i = 1; i <= k; i++)
    cin >> end[i];

  if((k == 0 && n > 0) || (k > n)){
    cout << "NO\n";
    return 0;
  }

  int a, b, sum;
  a = 1;
  for(int i = 1; i <= k; i++){
    sum = 0;
    b = a;
    while(sum + begin[b] < end[i] && b <= n){
      sum += begin[b];
      b++;
    }
    if(b > n || sum + begin[b] != end[i]){
      cout << "NO\n";
      return 0;
    }

    if(!valid(begin, a, b, i, end[i], output)){
      cout << "NO\n";
      return 0;
    }
    a = b + 1;
  }
  if(b != n){
    cout << "NO\n";
    return 0;
  }
  
  cout << "YES\n";
  cout << output;

  return 0;
}
