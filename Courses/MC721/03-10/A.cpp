// A. Acido Ribonucleico Alienigena

#include <iostream>

using namespace std;

bool conn(string &fita, int pos1, int pos2){
  if((fita[pos1] == 'B' && fita[pos2] == 'S') ||
    (fita[pos2] == 'B' && fita[pos1] == 'S') ||
    (fita[pos1] == 'F' && fita[pos2] == 'C') ||
    (fita[pos2] == 'F' && fita[pos1] == 'C'))
      return true;
  return false;
}

int main(){
  ios::sync_with_stdio(false);

  string fita;
  while(cin >> fita){
    int lig = 0;
    bool c = true;
    while(c){
      c = false;
      for(int i = 1; i < fita.length(); i++){
        while(i < fita.length() && conn(fita, i, i - 1)){
          c = true;
          fita.erase(fita.begin() + i - 1, fita.begin() + i + 1);
          lig++;
        }
      }
    }

    cout << lig << endl;
  }
  return 0;
}
