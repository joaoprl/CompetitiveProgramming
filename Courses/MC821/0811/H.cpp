
#include <iostream>
#include <climits>
#include <vector>

#define N 110
#define M 110

using namespace std;

class Prop{
public:
  int x, y, c;
  Prop(int x, int y, int c){
    this->x = x;
    this->y = y;
    this->c = c;
  }
};

void sandal(int **map, char **grid, int i, int j, int n, int m, int &sally, int &hole){

  vector<Prop> prop;
  int k = 0;
  prop.push_back(Prop(i, j, 1));

  int c;
  sally = INT_MAX;
  hole = INT_MAX;

  while(k < prop.size()){
    i = prop[k].x;
    j = prop[k].y;
    c = prop[k].c;

    if(i < 0 || i >= n || j < 0 || j >= m || map[i][j] != -1){
      k++;
      continue;
    }

    map[i][j] = 0;

    if(grid[i][j] == '.' || grid[i][j] == 'X'){
      prop.push_back(Prop(i - 1, j, c + 1));
      prop.push_back(Prop(i + 1, j, c + 1));
      prop.push_back(Prop(i, j + 1, c + 1));
      prop.push_back(Prop(i, j - 1, c + 1));
    }

    if(grid[i][j] == 'S')
      sally = min(sally, c);

    if(grid[i][j] == '*')
      hole = min(hole, c);
    k++;
  }
}

int main(){
  ios::sync_with_stdio(false);

  char **grid = new char*[N];
  for(int i = 0; i < N; i++)
    grid[i] = new char[M];

  int **map = new int*[N];
  for(int i = 0; i < N; i++)
    map[i] = new int[M];

  int t;
  cin >> t;
  for(int c = 0; c < t; c++){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> grid[i][j];
        map[i][j] = -1;
      }
    }

    int sally, hole;
    sally = INT_MAX;
    hole = INT_MAX;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 'X')
          sandal(map, grid, i, j, n, m, sally, hole);
      }
    }

    if(sally == INT_MAX || sally >= hole)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }

  return 0;
}
