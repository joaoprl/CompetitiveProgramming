// D. New Year and Fireworks

#include <iostream>

#define SIZE 300

using namespace std;

class Cell{
public:
  bool grid[3][3][200];
  bool painted;
  Cell();
  bool check(int dX, int dY, int time);
  void set(int dX, int dY, int time);
};

Cell::Cell(void){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 200; k++)
        grid[i][j][k] = false;
  }
  painted = false;
}

bool Cell::check(int dX, int dY, int time){
  return this->grid[dX + 1][dY + 1][time];
}

void Cell::set(int dX, int dY, int time){
  this->grid[dX + 1][dY + 1][time] = true;
}

int compute(Cell **grid, int n, int *t, int r, int i, int x, int y, int dX, int dY, int time){
  if(r == n)
    return 0;

  if(grid[x][y].check(dX, dY, time))
    return 0;
  grid[x][y].set(dX, dY, time);

  int paint = (grid[x][y].painted? 0 : 1);
    grid[x][y].painted = true;

  if(i == t[r] - 1){
    int dX1, dX2, dY1, dY2;

    if(dX == 0 || dY == 0){
      dY1 = dY + dX;
      dY2 = dY - dX;

      dX1 = dX + dY;
      dX2 = dX - dY;
    }
    else{
      dX1 = dX;
      dY1 = 0;

      dX2 = 0;
      dY2 = dY;
    }

    return paint + compute(grid, n, t, r + 1, 0, x + dX1, y + dY1, dX1, dY1, time + 1) +
      compute(grid, n, t, r + 1, 0, x + dX2, y + dY2, dX2, dY2, time + 1);
  }

  return paint + compute(grid, n, t, r, i + 1, x + dX, y + dY, dX, dY, time + 1);
}

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int *t = new int[n];
  for(int i = 0 ; i < n; i++)
    cin >> t[i];

  Cell **grid = new Cell*[SIZE];
  for(int i = 0; i < SIZE; i++){
    grid[i] = new Cell[SIZE];
  }

  cout << compute(grid, n, t, 0, 0, SIZE / 2, SIZE / 2, 0, 1, 0) << endl;

  return 0;
}
