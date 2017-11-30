// A. Gopher II

#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>

#define MAX_SIZE 100+100+5
#define EPS 1e-8

using namespace std;

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
// http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
bool bfs(int** rGraph, int s, int t, int parent[], int V)
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns tne maximum flow from s to t in the given graph
// http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
int fordFulkerson(int** graph, int s, int t, int V)
{
    int u, v;
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int **rGraph = new int*[V]; // Residual graph where rGraph[i][j] indicates
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)
    for(int i = 0; i < V; i++)
      rGraph[i] = new int[V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent, V))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    for(int i = 0; i < V; i++)
      delete[] rGraph[i];
    delete[] rGraph;

    // Return the overall flow
    return max_flow;
}

class Pos{
  public:
    double x, y;
    Pos(double, double);
    double getDistance(Pos);
};

Pos::Pos(double x1, double y1){
  x = x1;
  y = y1;
}

double Pos::getDistance(Pos p){
  return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

int main(){
  int **graph = new int*[MAX_SIZE];
  for(int i = 0; i < MAX_SIZE; i++)
    graph[i] = new int[MAX_SIZE];

  vector<Pos> gophers;
  vector<Pos> holes;
  double x, y;
  int n, m, s, v;

  while(cin.peek() != EOF && cin >> n >> m >> s >> v){

    gophers.clear();
    holes.clear();

    for(int i = 0; i < n + m + 2; i++){
      for(int j = 0; j < n + m + 2; j++){
        graph[i][j] = 0;
      }
    }

    int source = n + m, target = n + m + 1;
    for(int i = 0; i < n; i++){ // gophers
      cin >> x >> y;

      gophers.push_back(Pos(x, y));
      graph[source][i] = 1; // source to gophers
      graph[i][source] = 1;
    }
    for(int j = 0; j < m; j++){ // holes
      cin >> x >> y;

      holes.push_back(Pos(x, y));
      graph[n + j][target] = 1; // holes to target
      graph[target][n + j] = 1;
    }

    double maxDist = v * s;
    for(int i = 0; i < n; i++){ // build graph (gophers to holes)
      for(int j = 0; j < m; j++){
        if(maxDist - gophers[i].getDistance(holes[j]) >= EPS){
          graph[i][n + j] = 1;
          graph[n + j][i] = 0;
        }
        else{
          graph[i][n + j] = 0;
          graph[n + j][i] = 0;
        }
      }
    }

    int saved = fordFulkerson(graph, source, target, n + m + 2);

    cout << n - saved << "\n";
  }

  for(int i = 0; i < MAX_SIZE; i++)
    delete[] graph[i];
  delete[] graph;

  return 0;
}
