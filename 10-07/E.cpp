// E. Seating Arragement

#include <cstdio>
#include <vector>

#define UND 0
#define DIS 1

using namespace std;

void DFS(vector<int> *edges, int v, int *color, int k, int *numbers){
  numbers[v] = k;
  color[v] = DIS;

  for(int i = 0; i < edges[v].size(); i++){
    if(color[edges[v][i]] != DIS)
      DFS(edges, edges[v][i], color, k, numbers);
  }
}

int main(){
  int n, m, a, b, c, d, q;
  scanf("%d %d", &n, &m);
  vector<int> *edges = new vector<int>[n];
  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  scanf("%d", &q);
  int *color = new int[n];
  int *numbers = new int[n];
  for(int j = 0; j < n; j++)
    color[j] = UND;

  for(int i = 0; i < n; i++)
    if(color[i] != DIS)
      DFS(edges, i, color, i, numbers);

  for(int i = 0; i < q; i++){
    scanf("%d %d", &c, &d);
    if(numbers[c] == numbers[d])
      printf("YES\n");
    else
      printf("NO\n");
  }
}
