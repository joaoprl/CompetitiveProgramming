
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
}

void checkBFS(vector<pair<int, int> > *edges, int x, int m, int *dist, int &g, int *p){
  vector<pair<int, int> > q;
  make_heap(q.begin(), q.end(), greater<pair<int, int> >());

  pair<int, int> v;

  for(int i = 0; i < edges[x].size(); i++){
    q.push_back(edges[x][i]);
    push_heap(q.begin(), q.end(), greater<pair<int, int> >());
  }

  while(q.size() != 0){
    pop_heap(q.begin(), q.end(), greater<pair<int, int> >());
    v = q.back();
    q.pop_back();

    for(int i = 0; i < edges[x].size(); i++){
      if(edges[x][i].second != p[x]){
        p[edges[x][i].second] = x;
        edges[x][i].first = dist[x] + edges[x][i].first;
        q.push_back(edges[x][i]);
        push_heap(q.begin(), q.end(), greater<pair<int, int> >());
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);

  int s, t;
  while(cin >> s >> t){
    int a, b, c;
    vector<pair<int, int> > * edges = new vector<pair<int, int> >[s + 1];
    for(int i = 0; i < t; i++){
      cin >> a >> b >> c;

      edges[a].push_back(make_pair(c, b));
      edges[b].push_back(make_pair(c, a));
    }

    int q, m, x, v;
    cin >> q;

    int *dist = new int[s + 1];
    int *p = new int[s + 1];

    for(int i = 0; i < q; i++){
      cin >> x >> m;

      for(int i = 0; i <= s; i++){
        dist[i] = -1;
        p[i] = -1;
      }
      v = INT_MAX;
      checkBFS(edges, x, m, dist, v, p);

      if(v == INT_MAX)
        cout << -1 << endl;
      else
        cout << v << endl;
    }
  }

  return 0;
}
