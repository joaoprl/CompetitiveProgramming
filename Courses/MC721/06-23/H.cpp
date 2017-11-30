
#include <iostream>
#include <iomanip>
#include <vector>

#define N 101
#define BAR 1
#define CAR 2

using namespace std;

void dfs(vector<int> *edges, int a, int b, int c, int *cl, int &r, int dist){
  if(cl[a] != -1)
    return;

  bool pos = cl[b] == -1 && cl[c] == -1;

  cl[a] = dist;

  for(int i = 0; i < edges[a].size(); i++)
    dfs(edges, edges[a][i], b, c, cl, r, dist + 1);

  if(pos && cl[b] != -1 && cl[c] != -1 && r == -1)
    r = a;
}

int main(){
  ios::sync_with_stdio(false);
  int n, a, b, c, u, v;
  double ch;

  vector<int> *edges = new vector<int>[N];
  int *cl = new int[N];

  while(cin >> n >> a >> b >> c){
    for(int i = 0; i <= n; i++){
      edges[i].clear();
      cl[i] = -1;
    }

    for(int i = 0; i < n - 1; i++){
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    int r = -1;
    dfs(edges, a, b, c, cl, r, 0);

    if(r == b)
      ch = 1;
    else if(r == c)
      ch = 0;
    else
      ch = (double)(cl[c] - cl[r]) / (cl[b] - cl[r] + cl[c] - cl[r]);

    cout << fixed << setprecision(6) << ch << endl;

  }

  return 0;
}
