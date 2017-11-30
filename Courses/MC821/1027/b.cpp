
#include <iostream>
#include <vector>
#include <cstring>
#define N 110

using namespace std;

const int MAXN = 20000;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
};

int n1, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

// Add 1-directional edge
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n1 * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	while(bfs()){
		memset (ptr, 0, n1 * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

void clear(){
  for(int i = 0; i < MAXN; i++){
    g[i].clear();
    e.clear();
    s = t = 0;
  }
}


int main(){
  ios::sync_with_stdio(false);
  int n;
  char map[N][N];
  pair<int, int> lc[N][N];
  while(cin >> n){
    char ch;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> map[i][j];
      }
    }
    int v = 2;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(j == 0 && map[i][j] != 'X')
          lc[i][j].first = v++;
        else if(map[i][j] == '.' && map[i][j - 1] == 'X')
          lc[i][j].first = v++;
        else
          lc[i][j].first = lc[i][j - 1].first;
      }
    }
    int line = v;
    v++;

    for(int j = 0; j < n; j++){
      for(int i = 0; i < n; i++){
        if(i == 0 && map[i][j] != 'X')
          lc[i][j].second = v++;
        else if(map[i][j] == '.' && map[i - 1][j] == 'X')
          lc[i][j].second = v++;
        else
          lc[i][j].second = lc[i - 1][j].second;
      }
    }
    int col = v;
    v++;

    clear();

    s = 0;
    t = 1;
    n1 = v;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(map[i][j] == '.')
          add_edge(lc[i][j].first, lc[i][j].second, 1);

    for(int i = 2; i <= line; i++)
      add_edge(s, i, 1);
    for(int i = line + 1; i <= col; i++)
      add_edge(i, t, 1);

    cout << dinic() << endl;
  }

  return 0;
}
