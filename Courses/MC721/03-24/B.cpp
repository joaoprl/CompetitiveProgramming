
#include <iostream>
#include <vector>

#define N 10
#define M 10

using namespace std;

bool findPath(char **map, int beginN, int beginM, char c, int m, int n, vector<string> &steps){
  if(beginN < 0 || beginN >= n)
    return false;
  if(beginM < 0 || beginM >= m)
    return false;
  if(map[beginM][beginN] != c)
    return false;

  char next;
    
  switch(c){
    case '@':
      next = 'I';
      break;
    case 'I':
      next = 'E';
      break;
    case 'E':
      next = 'H';
      break;
    case 'H':
      next = 'O';
      break;
    case 'O':
      next = 'V';
      break;
    case 'V':
      next = 'A';
      break;
    case 'A':
      next = '#';
      break;
    case '#':
      return true;
  }

  steps.push_back("left");
  if(findPath(map, beginN - 1, beginM, next, m, n, steps))
    return true;

  steps.pop_back();
  steps.push_back("right");
  if(findPath(map, beginN + 1, beginM, next, m, n, steps))
    return true;

  steps.pop_back();
  steps.push_back("forth");
  if(findPath(map, beginN, beginM - 1, next, m, n, steps))
    return true;

  steps.pop_back();
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;

  char **map = new char*[M];
  for(int i = 0; i < M; i++)
    map[i] = new char[N];

  while(t--){
    int m, n;
    cin >> m >> n;
    char c;
    int beginM, beginN;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cin >> map[i][j];
        if(map[i][j] == '@'){
          beginM = i;
          beginN = j;
        }
      }
    }

    vector<string> steps;
    if(findPath(map, beginN, beginM, '@', m, n, steps)){
      for(int i = 0; i < steps.size() - 1; i++)
        cout << steps[i] << " ";
      cout << steps.back() << endl;
    }
    else{
      cerr << "Error" << endl;
      return 1;
    }


  }

  return 0;
}
