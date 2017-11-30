
#include <iostream>
#include <vector>

#define N 2010

#define UND 0
#define VIS 1

using namespace std;

void comp(vector<int> *edges, int v, int *cl, int r){
  if(cl[v] == -1){
    cl[v] = r;

    for(int i = 0; i < edges[v].size(); i++)
      comp(edges, edges[v][i], cl, r);
  }
}


void sort(vector<int> *edges, int v, int *cl, vector<int> &order){
  if(cl[v] == VIS)
    return;

  cl[v] = VIS;

  for(int i = 0; i < edges[v].size(); i++)
    sort(edges, edges[v][i], cl, order);

  order.push_back(v);
}

int main(){
  ios::sync_with_stdio(false);

  int n, m;
  int v, w, p;

  vector<int> *edges = new vector<int>[N];
  vector<int> *iedges = new vector<int>[N];
  int *cl = new int[N];
  vector<int> order;
  bool conn;

  while(cin >> n >> m && (n != 0 || m != 0)){
    order.clear();
    for(int i = 0; i <= n; i++){
      edges[i].clear();
      iedges[i].clear();
      cl[i] = UND;
    }

    for(int i = 0; i < m; i++){
      cin >> v >> w >> p;
      if(p == 2){
        edges[v].push_back(w);
        edges[w].push_back(v);
        iedges[v].push_back(w);
        iedges[w].push_back(v);
      }else{
        edges[v].push_back(w);
        iedges[w].push_back(v);
      }
    }

    for(int i = 1; i <= n; i++)
      sort(edges, i, cl, order);

    for(int i = 1; i <= n; i++)

      cl[i] = -1;

    for(int i = order.size() - 1; i >= 0; i--)
      comp(iedges, order[i], cl, order[i]);


    conn = true;
    for(int i = 1; i <= n; i++){
      if(cl[i] != cl[1])
        conn = false;
    }

    if(conn)
      cout << "1\n";
    else
      cout << "0\n";

  }

  return 0;
}
