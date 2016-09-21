// H. Indiana Jones and the lost Soccer Cup

#include <iostream>
#include <vector>

using namespace std;

#define UMARK 0
#define TMARK 1
#define PMARK 2

#define N (int)(1e4+1)

bool visit(int n, vector<int> &l, int *mark, vector<int> *edges, bool t){
  if(mark[n] == TMARK)
    return false;

  bool r = true;
  if(t && edges[n].size() == 0){
    l.push_back(n);
    return true;
  }
  else if(mark[n] == UMARK){
    mark[n] = TMARK;
    for(int m = 0; m < edges[n].size() && r; m++)
      r = r && visit(edges[n][m], l, mark, edges, false);
    mark[n] = PMARK;
    l.push_back(n);

  }
  return r;
}

int main(){

  int c, n, h, a, b;

  vector<int> *edges = new vector<int>[N];
  vector<int> l;
  int *mark = new int[N];

  cin >> c;
  while(c-- && c > 0){
    cin >> n >> h;
    for(int i = 1; i <= n; i++){
      edges[i].clear();
      mark[i] = UMARK;
    }
    for(int i = 1; i <= h; i++){
      cin >> a >> b;
      edges[a].push_back(b);
    }

    l.clear();
    bool valid = true;
    for(int i = 1; i <= n; i++){
      if(mark[i] == UMARK)
        valid = valid && visit(i, l, mark, edges, true);
    }

    bool missing = false;
    for(int i = n - 1; i >= 1; i--){
      missing = true;
      for(int j = 0; j < edges[l[i]].size(); j++){
        if(edges[l[i]][j] == l[i - 1])
          missing = false;
      }
      if(missing)
        break;
    }

    if(!valid){
      cout << "recheck hints\n";
    }
    else if(missing){
      cout << "missing hints\n";
    }
    else {
      for(int i = n - 1; i > 0; i--)
        cout << l[i] << " ";
      cout << l[0] << "\n";

    }
  }
  return 0;
}
