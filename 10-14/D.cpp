// D. Matrix Transpose

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cell{
  public:
    int x, y, value;

  Cell(int i, int j) : x(i), y(j){}

  bool operator < (const Cell& cell) const{
    return (y < cell.y) || (y == cell.y && x < cell.x);
  }
};

int main(){
  int m, n, k, col, value, pos;
  vector<Cell> matrix;

  while(cin >> m >> n){
    matrix.clear();
    pos = 0;
    for(int i = 0; i < m; i++){
      cin >> k;

      for(int j = 0; j < k; j++){
        cin >> col;
        matrix.push_back(Cell(i + 1, col));
      }
      for(int j = 0; j < k; j++){
        cin >> value;
        matrix[pos + j].value = value;
      }
      pos += k;
    }

    sort(matrix.begin(), matrix.end());

    cout << n << " " << m << "\n";

    col = 0;
    for(int i = 0; i < matrix.size(); i++){
      if(col + 1 == matrix[i].y){
        col = matrix[i].y;
        int j;
        for(j = i; matrix[j].y == col; j++);
        cout << j - i;
        for(j = i; matrix[j].y == col; j++){
          cout << " " << matrix[j].x;
        }
        cout << "\n";
        int k = i;
        if(k < j)
          cout << matrix[k].value;
        for(k = i + 1; k < j; k++)
          cout << " " << matrix[k].value;
        cout << "\n";
        i = j - 1;
      }
      else {
        cout << "0\n\n";
        col++;
        i--;
      }
    }
    while(col < n){
      cout << "0\n\n";
      col++;
    }
  }

  return 0;
}
