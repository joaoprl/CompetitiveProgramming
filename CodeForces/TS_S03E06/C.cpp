
// C. Old Chess Sets

#include <iostream>
#include <vector>
#define W 0
#define B 1

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  int king[2], queen[2], bishop[2], knight[2], rook[2], pawn[2];
  king[0] = queen[0] = bishop[0] = knight[0] = rook[0] = pawn[0];
  king[1] = queen[1] = bishop[1] = knight[1] = rook[1] = pawn[1];

  string str;
  vector<string> out;

  for(int i = 0; i < a; i++){
    cin >> str;
    if(str == "black"){
      cin >> str;
      if(str == "king")
        king[B]++;
      if(str == "queen")
        queen[B]++;
      if(str == "bishop")
        bishop[B]++;
      if(str == "knight")
        knight[B]++;
      if(str == "rook")
        rook[B]++;
      if(str == "pawn")
        pawn[B]++;
    }
    else{
      cin >> str;
      if(str == "king")
        king[W]++;
      if(str == "queen")
        queen[W]++;
      if(str == "bishop")
        bishop[W]++;
      if(str == "knight")
        knight[W]++;
      if(str == "rook")
        rook[W]++;
      if(str == "pawn")
        pawn[W]++;
    }
  }

  for(int i = 0; i < b; i++){
    cin >> str;
    if(str == "black"){
      cin >> str;
      if(str == "king" && king[B] < 1){
        king[B]++;
        out.push_back("black king");
      }
      if(str == "queen" && queen[B] < 1){
        queen[B]++;
        out.push_back("black queen");
      }
      if(str == "bishop" && bishop[B] < 2){
        bishop[B]++;
        out.push_back("black bishop" );
      }
      if(str == "knight" && knight[B] < 2){
        knight[B]++;
        out.push_back("black knight");
      }
      if(str == "rook" && rook[B] < 2){
        rook[B]++;
        out.push_back("black rook");
      }
      if(str == "pawn" && pawn[B] < 8){
        pawn[B]++;
        out.push_back("black pawn");
      }
    }
    else{
      cin >> str;
      if(str == "king" && king[W] < 1){
        king[W]++;
        out.push_back("white king");
      }
      if(str == "queen" && queen[W] < 1){
        queen[W]++;
        out.push_back("white queen");
      }
      if(str == "bishop" && bishop[W] < 2){
        bishop[W]++;
        out.push_back("white bishop");
      }
      if(str == "knight" && knight[W] < 2){
        knight[W]++;
        out.push_back("white knight");
      }
      if(str == "rook" && rook[W] < 2){
        rook[W]++;
        out.push_back("white rook");
      }
      if(str == "pawn" && pawn[W] < 8){
        pawn[W]++;
        out.push_back("white pawn");
      }
    }
  }

  int acc = king[B] + queen[B] + bishop[B] + knight[B] + rook[B] + pawn[B];
  acc += king[W] + queen[W] + bishop[W] + knight[W] + rook[W] + pawn[W];

  if(acc != 32)
    cout << "impossible" << endl;
  else{
    for(int i = 0; i < out.size(); i++)
      cout << out[i] << endl;
  }

  return 0;
}
