#include<bits/stdc++.h>

using namespace std;

int mx;
int cor[4][7];
int rot[4][7];
int n;

int pow(int k){
  int res = 1;

  for(int i = 0; i < k; i++)
    res *= 24;

  return res;
}

void nextrot(){

}

int main(){
  while(cin >> n && n != 0){
    int cnt = 0;
    map<string, int> mapa;

    for(int i = 0; i < 4; i++)
      for(int j = 1; j < 7; j++)
        rot[i][j] = j;

    for(int i = 0; i < n; i++){
      string s;
      for(int j = 1; j < 7; j++){
        cin >> s;
        if(mapa.find(s) != mapa.end())
          cor[i][j] = mapa[s];
        else{
          mapa[s] = cnt++;
          cor[i][j] = mapa[s];
        }
      }
    }

    mx = 24;

    for(int i = 0; i < pow(n-1); i++){
      nextrot();
    }
  }

  return 0;
}
