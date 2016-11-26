// D. Anton and Chess

#include <iostream>

using namespace std;

class Piece{
  public:
    char c = '\0';
    int x = 0, y = 0;
};

void tabUpdate(Piece smallTab[3][3], Piece p){
  if(p.x == 0){
    if(p.y < 0){
      if(p.y > smallTab[1][2].y || smallTab[1][2].c == '\0')
        smallTab[1][2] = p;
    }
    if(p.y > 0){
      if(p.y < smallTab[1][0].y || smallTab[1][0].c == '\0')
        smallTab[1][0] = p;
    }
  }
  if(p.x > 0){
    if(p.y < 0){
      if(p.x < smallTab[2][2].x || smallTab[2][2].c == '\0')
        smallTab[2][2] = p;
    }
    if(p.y == 0){
      if(p.x < smallTab[2][1].x || smallTab[2][1].c == '\0')
        smallTab[2][1] = p;
    }
    if(p.y > 0){
      if(p.x < smallTab[2][0].x || smallTab[2][0].c == '\0')
        smallTab[2][0] = p;
    }
  }
  if(p.x < 0){
    if(p.y < 0){
      if(p.x > smallTab[0][2].x || smallTab[0][2].c == '\0')
        smallTab[0][2] = p;
    }
    if(p.y == 0){
      if(p.x > smallTab[0][1].x || smallTab[0][1].c == '\0')
        smallTab[0][1] = p;
    }
    if(p.y > 0){
      if(p.x > smallTab[0][0].x || smallTab[0][0].c == '\0')
        smallTab[0][0] = p;
    }
  }
}

int main(){
  int n, k_x, k_y;
  cin >> n >> k_x >> k_y;
  Piece smallTab[3][3];
  Piece p;
  while(n--){
    cin >> p.c >> p.x >> p.y;
    p.x -= k_x;
    p.y -= k_y;
    if(p.x == 0 || p.y == 0 || p.x == p.y || p.x == -p.y){
      tabUpdate(smallTab, p);
    }
  }

  bool check = false;
  if(smallTab[0][0].c == 'Q' || smallTab[0][0].c == 'B' ||
    smallTab[0][2].c == 'Q' || smallTab[0][2].c == 'B' ||
    smallTab[2][0].c == 'Q' || smallTab[2][0].c == 'B' ||
    smallTab[2][2].c == 'Q' || smallTab[2][2].c == 'B')
    check = true;

  if(smallTab[0][1].c == 'Q' || smallTab[0][1].c == 'R' ||
    smallTab[1][0].c == 'Q' || smallTab[1][0].c == 'R' ||
    smallTab[1][2].c == 'Q' || smallTab[1][2].c == 'R' ||
    smallTab[2][1].c == 'Q' || smallTab[2][1].c == 'R')
    check = true;

  if(check)
    cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
