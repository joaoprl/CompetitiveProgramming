// D. Alyona and a tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool comp(tuple<int, long long, int> a, tuple<int, long long, int> b){
  return get<1>(a) <= get<1>(b);
}

int computeControl(int v, vector<int> *edges, int *w, vector< tuple<int, long long, int> > &dist, int *a, int *p, int *counter){
  // update distance of this node
  long long d = w[v];
  if(dist.size() > 0)
    d += get<1>(dist.back());
  dist.push_back(make_tuple(v, d, 0));

  // get number of controled by subtree that go this or a parent of this node
  int controled = 0;
  for(unsigned int i = 0; i < edges[v].size(); i++){
    if(edges[v][i] != p[v])
      controled += computeControl(edges[v][i], edges, w, dist, a, p, counter);
  }

  // update number of controled by this node
  counter[v] = controled;
  // control that ends on this node should not go to a parent
  controled -= get<2>(dist.back());

  // mark ending point of control for this node
  if(v != 1){
    int pos = upper_bound(dist.begin(), dist.end(), make_tuple(v, d - a[v], 0), comp) - dist.begin();
    if(get<0>(dist[pos]) != v){
      get<2>(dist[pos])++;
      controled++;
    }
  }

  // clear this node from distance vector
  dist.pop_back();

  // send number of controled of this subtree that expands to a parent of the subtree
  return controled;
}

int main(){
  int n;
  cin >> n;

  int *a = new int[n + 1];
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  int *p = new int[n + 1], *w = new int[n + 1];
  p[1] = w[1] = 0;

  vector<int> *edges = new vector<int>[n + 1];

  for(int i = 1; i <= n - 1; i++){
    cin >> p[i + 1] >> w[i + 1];

    edges[i + 1].push_back(p[i + 1]);
    edges[p[i + 1]].push_back(i + 1);
  }

  vector< tuple<int, long long, int> > dist;
  int *counter = new int[n + 1];
  for(int i = 1; i <= n; i++)
    counter[i] = 0;

  computeControl(1, edges, w, dist, a, p, counter);

  for(int i = 1; i <= n; i++)
    cout << counter[i] << " ";
  cout << endl;

  return 0;
}
