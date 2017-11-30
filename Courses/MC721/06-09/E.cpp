
#include <iostream>
#include <vector>

#define MAX_N 26
#define MAX_L 26

using namespace std;

void format(string &str){
  if(str[0] < 'A' || str[0] > 'Z')
    str[0] = str[0] - 'a' + 'A';

  for(int i = 1; i < str.length(); i++){
    if(str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] - 'A' + 'a';
  }
}

int main(){
  ios::sync_with_stdio(false);

  string **strs = new string*[MAX_N];
  for(int i = 0; i < MAX_N; i++)
    strs[i] = new string[MAX_L];

  int N;
  cin >> N;
  for(int t = 1; t <= N; t++){
    int n;
    cin >> n;

    for(int i = 0; i < MAX_N; i++)
      for(int j = 0; j < MAX_L; j++)
        strs[i][j] = "";

    int k;
    string str;
    for(int i = 0; i < n; i++){
      cin >> k;
      for(int j = 0; j < k; j++){
        cin >> str;
        format(str);
        strs[i][str[0] - 'A'] = str;
      }
    }

    string *strings = new string[n];
    int count = 0;

    int p, q;
    while(count < n){
      for(int j = 0; j < n; j++){
        p = -1;
        for(int i = 0; i < n; i++){
          if(strs[i][j] != ""){
            if(p == -1){
              p = i;
              q = j;
            }
            else{
              p = -1;
              break;
            }
          }
        }

        if(p != -1){
          strings[q] = strs[p][q];
          for(int q = 0; q < n; q++)
            strs[p][q] = "";
          count++;
          break;
        }
      }
    }

    cout << "Case #" << t << ":\n";
    for(int i = 0; i < n; i++)
      cout << strings[i] << endl;

  }

  return 0;
}
