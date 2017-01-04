// D. Green and Black Tea

#include <iostream>

using namespace std;

bool compute(string &str, int greenAcc, int blackAcc, int k, int a, int b){
  bool flag;

  int pos = 0;
  char *s = new char[a + b + 1];
  s[a + b] = 0;
  while(true){
    if(a == 0 || b == 0){
      if(a + b > k){
        flag = false;
        break;
      }

      char c = ((a == 0)? 'B' : 'G');
      for(int i = 0; i < a + b; i++)
        s[pos + i] = c;
      flag = true;
      break;
    }

    if(greenAcc == k){
      s[pos] = 'B';
      pos++;
      greenAcc = 0;
      blackAcc = 1;
      b--;
      continue;
    }

    else if(blackAcc == k){
      s[pos] = 'G';
      pos++;
      blackAcc = 0;
      greenAcc = 1;
      a--;
      continue;
    }

    if(a >= b){
      s[pos] = 'G';
      pos++;
      greenAcc++;
      a--;
      continue;
    }
    else{
      s[pos] = 'B';
      pos++;
      blackAcc++;
      b--;
      continue;
    }
  }

  str = string(s);
  return flag;
}

int main(){
  ios::sync_with_stdio(false);
  int n, k, a, b;

  cin >> n >> k >> a >> b;

  string str;
  if(compute(str, 0, 0, k, a, b))
    cout << str << endl;
  else
    cout << "NO\n";

  return 0;
}
