// J. Toll

#include <iostream>
#include <vector>
#include <algorithm>

#define AB_SIZE ('z' - 'A' + 1)
#define INF 10000000

using namespace std;

int *dist;
bool comp(int a, int b){
  return dist[a] > dist[b];
}

int numPieces(int x2){
  int x1;
  for(x1 = x2; x1 - (x1 + 19)/20 < x2; x1++);
  return x1;
}

void dijkstra(vector<int> *edges, int n, int start, int p){
  vector<int> q;

  for(int i = 0; i < n; i++){
    if(i == start)
      dist[start] = p;
    else
      dist[i] = INF;

    q.push_back(i);
    push_heap(q.begin(), q.end(), comp);
  }

  while(q.size() != 0){
    pop_heap(q.begin(), q.end(), comp);
    int u = q.back();
    q.pop_back();

    for(int i = 0; i < edges[u].size(); i++){
      int v = edges[u][i];
      int alt;

      if(u <= 'Z' - 'A')
        alt = numPieces(dist[u]);
      else
        alt = dist[u] + 1;

      if(alt < dist[v]){
        dist[v] = alt;
        make_heap(q.begin(), q.end(), comp);
      }
    }
  }
}

int main(){
  int n;

  vector<int> *edges = new vector<int>[AB_SIZE];
  dist = new int[AB_SIZE];

  int t = 1;
  while(true){
    cin >> n;
    if(n == -1)
      return 0;

    for(int i = 0; i < AB_SIZE; i++)
      edges[i].clear();

    while(n--){
      char c1, c2;
      cin >> c1 >> c2;
      edges[c1 - 'A'].push_back(c2 - 'A');
      edges[c2 - 'A'].push_back(c1 - 'A');
    }

    int p;
    char start, end;
    cin >> p >> start >> end;

    dijkstra(edges, AB_SIZE, (int)(end - 'A'), p);

    cout << "Case " << t << ": " << dist[start - 'A'] << "\n";
    t++;
  }

  return 0;
}
