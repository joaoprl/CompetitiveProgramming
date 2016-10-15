// I. Tic-tac-toe

#include <iostream>

using namespace std;

int main(){
  char g[3][3];

  bool firstWon, secondWon;
  int crosses, circles;

  crosses = circles = 0;
  firstWon = secondWon = false;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> g[i][j];

      if(g[i][j] == '0')
        circles++;
      if(g[i][j] == 'X')
        crosses++;
    }
  }

  for(int l = 0; l < 3; l++){
    if(g[l][0] == g[l][1] && g[l][1] == g[l][2]){
      if(g[l][0] == '0')
        secondWon = true;
      if(g[l][0] == 'X')
        firstWon = true;
    }
    if(g[0][l] == g[1][l] && g[1][l] == g[2][l]){
      if(g[0][l] == '0')
        secondWon = true;
      if(g[0][l] == 'X')
        firstWon = true;
    }
  }

  if(g[0][0] == g[1][1] && g[1][1] == g[2][2]){
    if(g[0][0] == '0')
      secondWon = true;
    if(g[0][0] == 'X')
      firstWon = true;
  }
  if(g[0][2] == g[1][1] && g[1][1] == g[2][0]){
    if(g[0][2] == '0')
      secondWon = true;
    if(g[0][2] == 'X')
      firstWon = true;
  }

  if((firstWon && secondWon) || (firstWon && circles + 1 != crosses) ||
  (secondWon && circles != crosses) || circles > crosses || crosses > circles + 1)
    cout << "illegal\n";
  else if(firstWon)
    cout << "the first player won\n";
  else if(secondWon)
    cout << "the second player won\n";
  else if(circles + 1 == crosses && circles + crosses == 9)
    cout << "draw\n";
  else if(circles == crosses)
    cout << "first\n";
  else cout << "second\n";

  return 0;
}
