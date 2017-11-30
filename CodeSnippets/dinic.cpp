// dinic


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// O(n² * m)
const int MAXN = 2000;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
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
	memset (d, -1, n * sizeof d[0]);
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
		memset (ptr, 0, n * sizeof ptr[0]);
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
  int m;
  while(cin >> n && n != -1){
    cin >> m;
    clear();

    vector<int> p(n + 1, 0);
    for(int i = 1; i <= n; i++)
      cin >> p[i];

    s = 0;
    t = n + 1;

    int a, b;
    int k = t + 1, pont = 0;
    for(int i = 0; i < m; i++){
      cin >> a >> b;
      if(a == n)
        p[n] += 2;
      else if(b == n)
        p[n] += 2;
      else{
        pont += 2;
        add_edge(s, k, 2);
        add_edge(k, a, 2);
        add_edge(k, b, 2);
        k++;
      }
    }

    bool poss = true;
    for(int i = 1; i < n; i++){
      if(p[n] - p[i] - 1 < 0)
        poss = false;
      else
        add_edge(i, t, p[n] - p[i] - 1);
    }

    n = k + 1;

    if(poss && dinic() == pont)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
