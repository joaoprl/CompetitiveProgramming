// C. Arpa's loud Owf and Mehrdad's evil plan

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<int> *edges, int v, int d, int n, vector<int> &cicles, int *color, int*dist){
  if(color[v] == 2){
    cicles.push_back(-1);
    return;
  }
  if(color[v] == 1){
    cicles.push_back(d - dist[v]);
    color[v] = 2;
    return;
  }

  dist[v] = d;
  color[v] = 1;
  for(int i = 0; i < edges[v].size(); i++)
    dfs(edges, edges[v][i], d + 1, n, cicles, color, dist);


  if(color[v] != 2 && dist[v] == 0)
    cicles.push_back(-1);

  color[v] = 2;
}

int gcd(int a, int b){
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b){
  return abs(a * b) / gcd(a, b);
}

void explore(vector<int> *edges, int n){
  vector<int> cicles;

  int *color = new int[n + 1];
  int *dist = new int[n + 1];
  for(int i = 1; i <= n; i++){
    color[i] = 0;
    dist[i] = 0;
  }

  for(int i = 1; i <= n; i++){
    if(color[i] == 0)
      dfs(edges, i, 0, n, cicles, color, dist);
  }

  int m = 1;
  for(int i = 0; i < cicles.size(); i++){
    if(cicles[i] == -1){
      m = -1;
      break;
    }

    if(cicles[i] % 2 == 0)
      cicles[i] = cicles[i] / 2;
      
    m = lcm(cicles[i], m);
  }

  cout << m << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<int> *edges = new vector<int>[n + 1];
  int e;
  for(int i = 1; i <= n; i++){
    cin >> e;
    edges[i].push_back(e);
  }

  explore(edges, n);


  return 0;
}
