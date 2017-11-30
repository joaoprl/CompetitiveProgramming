
#include <iostream>
#include <vector>

#define endl '\n'

#define N 1000010
#define UND 0
#define TMP 1
#define PER 2

using namespace std;

int counter;
bool hc;

void sort(vector<int> *edges, int v, int *cl, vector<int> &order, bool &pos){
  if(cl[v] == TMP){
    pos = false;
    return;
  }
  if(cl[v] == UND){
    cl[v] = TMP;

    for(int i = 0; i < edges[v].size(); i++)
      sort(edges, edges[v][i], cl, order, pos);

    order.push_back(v);
    cl[v] = PER;
  }

}

int main(){
  ios::sync_with_stdio(false);

  int n, m;

  vector<int> *edges = new vector<int>[N];
  vector<int> order;
  int *cl = new int[N];
  bool pos;

  while(cin >> n >> m && (n != 0 || m != 0)){
    order.clear();
    pos = true;
    for(int i = 0; i <= n; i++){
      edges[i].clear();
      cl[i] = UND;
    }
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;

      edges[u].push_back(v);
    }

    hc = false;
    counter = 0;

    for(int i = 1; i <= n; i++)
      sort(edges, i, cl, order, pos);

    if(pos)
      for(int i = order.size() - 1; i >= 0; i--)
        cout << order[i] << endl;    
    else
      cout << "IMPOSSIBLE" << endl;


  }


  return 0;
}
