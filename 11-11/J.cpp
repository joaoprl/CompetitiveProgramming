// J. Cops and Robbers

#include <iostream>

using namespace std;

int win(int **maze, int i, int j){
  if(i == 4 && j == 4)
    return true;
  if(i < 0 || j < 0 || i >= 5 || j >= 5)
    return false;
  if(maze[i][j] == 1)
    return false;

  maze[i][j] = 1;
  return win(maze, i - 1, j) || win(maze, i + 1, j)
    || win(maze, i, j - 1) || win(maze, i, j + 1);
}

int main(){
  int t;
  cin >> t;
  int **maze = new int*[5];
  for(int i = 0; i < 5; i++)
    maze[i] = new int[5];
  while(t--){
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++)
        cin >> maze[i][j];
    }

    if(win(maze, 0, 0))
      cout << "COPS\n";
    else
      cout << "ROBBERS\n";

  }
  return 0;
}
