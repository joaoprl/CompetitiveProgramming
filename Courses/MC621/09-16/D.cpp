// D. Check the Check

#include <iostream>
#include <cstdio>

using namespace std;

bool isBlack(char c){
  if(c >= 'a' && c <= 'z')
    return true;
  return false;
}
bool isWhite(char c){
  if(c >= 'A' && c <= 'Z')
    return true;
  return false;
}

int main(){
  char board[8][8], c;
  pair<int, int> king, King;

  bool end;
  int game = 1;

  while(!end){
    end = true;
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        cin >> c;
        board[i][j] = c;
        if(c == 'k'){
          king.first = i;
          king.second = j;
        }
        else if(c == 'K'){
          King.first = i;
          King.second = j;
        }
        if(c != '.')
          end = false;
      }
    }

    if(end)
      break;

    bool check, Check;
    check = Check = false;

    int x, y;
    x = king.first; y = king.second;

    // check pawn
    if(x < 7 && y < 7 && board[x + 1][y + 1] == 'P')
      check = true;
    if(x < 7 && y > 0 && board[x + 1][y - 1] == 'P')
      check = true;

    // check Rook (and partial queen)
    for(int j = y + 1; j < 8; j++){
      int i = x;
      c = board[i][j];
      if(isBlack(c))
        j = 8;
      else if(isWhite(c) && (c == 'Q' || c == 'R' )){
        check = true;
        j = 8;
      }
      else if(isWhite(c)){
        j = 8;
      }
    }
    for(int j = y - 1; j >= 0; j--){
      int i = x;
      c = board[i][j];
      if(isBlack(c))
        j = 0;
      else if(isWhite(c) && (c == 'Q' || c == 'R')){
        check = true;
        j = 0;
      }
      else if(isWhite(c)){
        j = 0;
      }
    }
    for(int i = x + 1; i < 8; i++){
      int j = y;
      c = board[i][j];
      if(isBlack(c))
        i = 8;
      else if(isWhite(c) && (c == 'Q' || c == 'R')){
        check = true;
        i = 8;
      }
      else if(isWhite(c)){
        i = 8;
      }
    }
    for(int i = x - 1; i >= 0; i--){
      int j = y;
      c = board[i][j];
      if(isBlack(c))
        i = 0;
      else if(isWhite(c) && (c == 'Q' || c == 'R')){
        check = true;
        i = 0;
      }
      else if(isWhite(c)){
        i = 0;
      }
    }

    // check bishop (and partial queen)
    for(int i = -1; x + i >= 0 && y + i >= 0; i--){
      c = board[x + i][y + i];
      if(isBlack(c))
        i = -100;
      else if(isWhite(c) && (c == 'Q' || c == 'B')){
        check = true;
        i = -100;
      }
      else if(isWhite(c)){
        i = -100;
      }
    }
    for(int i = -1; x + i >= 0 && y - i < 8; i--){
      c = board[x + i][y - i];
      if(isBlack(c))
        i = -100;
      else if(isWhite(c) && (c == 'Q' || c == 'B')){
        check = true;
        i = -100;
      }
      else if(isWhite(c)){
        i = -100;
      }
    }
    for(int i = -1; x - i < 8 && y + i >= 0; i--){
      c = board[x - i][y + i];
      if(isBlack(c))
        i = -100;
      else if(isWhite(c) && (c == 'Q' || c == 'B')){
        check = true;
        i = -100;
      }
      else if(isWhite(c)){
        i = -100;
      }
    }
    for(int i = -1; x - i < 8 && y - i < 8; i--){
      c = board[x - i][y - i];
      if(isBlack(c))
        i = -100;
      else if(isWhite(c) && (c == 'Q' || c == 'B')){
        check = true;
        i = -100;
      }
      else if(isWhite(c)){
        i = -100;
      }
    }

    // check knight
    if(x - 2 >= 0 && y - 1 >= 0 && board[x - 2][y - 1] == 'N')
      check = true;
    if(x - 2 >= 0 && y + 1 < 8 && board[x - 2][y + 1] == 'N')
      check = true;
    if(x + 2 < 8 && y - 1 >= 0 && board[x + 2][y - 1] == 'N')
      check = true;
    if(x + 2 < 8 && y + 1 < 8 && board[x + 2][y + 1] == 'N')
      check = true;
    if(x - 1 >= 0 && y - 2 >= 0 && board[x - 1][y - 2] == 'N')
      check = true;
    if(x - 1 >= 0 && y + 2 < 8 && board[x - 1][y + 2] == 'N')
      check = true;
    if(x + 1 < 8 && y - 2 >= 0 && board[x + 1][y - 2] == 'N')
      check = true;
    if(x + 1 < 8 && y + 2 < 8 && board[x + 1][y + 2] == 'N')
      check = true;



    x = King.first; y = King.second;
    // check pawn
    if(x > 0 && y < 7 && board[x - 1][y + 1] == 'p')
      Check = true;
    if(x > 0 && y > 0 && board[x - 1][y - 1] == 'p')
      Check = true;

    // check Rook (and partial queen)
    for(int j = y + 1; j < 8; j++){
      int i = x;
      c = board[i][j];
      if(isWhite(c))
        j = 8;
      else if(isBlack(c) && (c == 'q' || c == 'r')){
        Check = true;
        j = 8;
      }
      else if(isBlack(c)){
        j = 8;
      }
    }
    for(int j = y - 1; j >= 0; j--){
      int i = x;
      c = board[i][j];
      if(isWhite(c))
        j = -100;
      else if(isBlack(c) && (c == 'q' || c == 'r')){
        Check = true;
        j = -100;
      }
      else if(isBlack(c)){
        j = -100;
      }
    }
    for(int i = x + 1; i < 8; i++){
      int j = y;
      c = board[i][j];
      if(isWhite(c))
        i = 8;
      else if(isBlack(c) && (c == 'q' || c == 'r')){
        Check = true;
        i = 8;
      }
      else if(isBlack(c)){
        i = 8;
      }
    }
    for(int i = x - 1; i >= 0; i--){
      int j = y;
      c = board[i][j];
      if(isWhite(c))
        i = -100;
      else if(isBlack(c) && (c == 'q' || c == 'r')){
        Check = true;
        i = -100;
      }
      else if(isBlack(c)){
        i = -100;
      }
    }

    // check bishop (and partial queen)
    for(int i = -1; x + i >= 0 && y + i >= 0; i--){
      c = board[x + i][y + i];

      if(isWhite(c))
        i = -100;
      else if(isBlack(c) && (c == 'q' || c == 'b')){
        Check = true;
        i = -100;
      }
      else if(isBlack(c)){
        i = -100;
      }
    }

    for(int i = -1; x + i >= 0 && y - i < 8; i--){
      c = board[x + i][y - i];
      if(isWhite(c))
        i = -100;
      else if(isBlack(c) && (c == 'q' || c == 'b')){
        Check = true;
        i = -100;
      }
      else if(isBlack(c)){
        i = -100;
      }
    }
    for(int i = -1; x - i < 8 && y + i >= 0; i--){
      c = board[x - i][y + i];
      if(isWhite(c))
        i = -100;
      else if(isBlack(c) && (c == 'q' || c == 'b')){
        Check = true;
        i = -100;
      }
      else if(isBlack(c)){
        i = -100;
      }
    }
    for(int i = -1; x - i < 8 && y - i < 8; i--){
      c = board[x - i][y - i];
      if(isWhite(c))
        i = -100;
      else if(isBlack(c) && (c == 'q' || c == 'b')){
        Check = true;
        i = -100;
      }
      else if(isBlack(c)){
        i = -100;
      }
    }

    // check knight
    if(x - 2 >= 0 && y - 1 >= 0 && board[x - 2][y - 1] == 'n')
      Check = true;
    if(x - 2 >= 0 && y + 1 < 8 && board[x - 2][y + 1] == 'n')
      Check = true;
    if(x + 2 < 8 && y - 1 >= 0 && board[x + 2][y - 1] == 'n')
      Check = true;
    if(x + 2 < 8 && y + 1 < 8 && board[x + 2][y + 1] == 'n')
      Check = true;
    if(x - 1 >= 0 && y - 2 >= 0 && board[x - 1][y - 2] == 'n')
      Check = true;
    if(x - 1 >= 0 && y + 2 < 8 && board[x - 1][y + 2] == 'n')
      Check = true;
    if(x + 1 < 8 && y - 2 >= 0 && board[x + 1][y - 2] == 'n')
      Check = true;
    if(x + 1 < 8 && y + 2 < 8 && board[x + 1][y + 2] == 'n')
      Check = true;


    if(check)
      printf("Game #%d: black king is in check.\n", game);
    else if(Check)
      printf("Game #%d: white king is in check.\n", game);
    else
      printf("Game #%d: no king is in check.\n", game);
    game++;
  }

  return 0;
}
