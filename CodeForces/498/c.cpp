
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

#include <vector>
#include <cstring>

using namespace std;

vector<int> primes(int n){
  vector<int> pr;
  const int limit = 10000000;
  if(n <= limit){
    vector<bool> p(n + 1, false);

    pr.push_back(2);
    for(int i = 3; i <= n; i += 2){
      if(!p[i]){
        for(int k = i * 2; k <= n; k += i)
          p[k] = true;
        pr.push_back(i);
      }
    }
  }else{
    vector<int> pr = primes(limit);
    cout << "done1" << endl;
    for(int i = pr.back() + 2; i <= n; i += 2){
      bool f = true;
      for(int j = 0; f && j < pr.size() && pr[j] < 50000 && pr[j] * pr[j] < i; j++)
        if(i % pr[j] == 0)
          f = false;

      if(f)
        pr.push_back(i);
    }
  }

  return pr;
}


int main(){
  ios::sync_with_stdio(false);
  vector<int> pr = primes(1000000000);
  return 0;
  int m;
  cin >> n >> m;

  vector<int> nums(n + 1, 0);
  for(int i = 1; i <= n; i++)
    cin >> nums[i];

  s = 0;
  t = n + 1;

  vector< pair<int, int> > pairs;

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    pairs.push_back({a, b});
  }


  return 0;
}
