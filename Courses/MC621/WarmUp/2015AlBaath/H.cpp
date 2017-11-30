// H. Phobia

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    int n, m;
    
    cin >> n >> m;

    char **maze = new char*[n];

    for(int x = 0; x < n; x++){
      maze[x] = new char[m];
      for(int y = 0; y < m; y++){
	cin >> maze[x][y];
      }
    }
    
    for(int x = 0; x < n; x++){
      for(int y = 0; y < m; y++){
	cout << maze[x][y] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
