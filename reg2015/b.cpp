#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 2000;
const int INF = 1000000000;

struct edge{
	int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge(int a, int b, int cap){
	edge e1 = {a, b, cap, 0};
	edge e2 = {b, a, 0, 0};
	g[a].push_back((int)e.size());
	e.push_back(e1);
	g[b].push_back((int)e.size());
	e.push_back(e2);
}

bool bfs(){
	int qh = 0, qt = 0;
	q[qt++] = s;
	memset(d, -1, n * sizeof d[0]);
	d[s] = 0;

	while(qh < qt && d[t] == -1){
		int v = q[qh++];
		for(size_t i = 0; i < g[v].size(); i++){
			int id = g[v][i],
				to = e[id].b;
			if(d[to] == -1 && e[id].flow < e[id].cap){
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs(int v, int flow){
	if(!flow) return 0;
	if(v == t) return flow;
	for(; ptr[v] < (int)g[v].size(); ptr[v]++){
		int id = g[v][ptr[v]],
			to = e[id].b;
		if(d[to] != d[v] + 1) continue;
		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
		if(pushed){
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic(){
	int flow = 0;
	while(bfs()){
		memset(ptr, 0, n * sizeof ptr[0]);
		while(int pushed = dfs(s, INF))
			flow += pushed;
	}
	return flow;
}

void clear(){
	for(int i = 0; i < MAXN; i++)
		g[i].clear();
	e.clear();
	s = t = 0;
}

int main(){
	ios::sync_with_stdio(false);
	int n1, q, a, b;
	while(cin >> n1 >> q){
		vector< vector<bool> > par;

		for(int i = 0; i < n1; i++){
			par.push_back(vector<bool>(n1 + 1, false));
			cin >> b;
			par.back()[0] = b < n1;

			while(b--){
				cin >> a;
				par.back()[a] = true;
			}
		}

		vector<int> qr;
		while(q--){
			clear();
			qr.clear();

			s = 0;
			t = 1;
			n = n1 + n1 + 1 + 2;

			for(int i = 0; i < n1; i++){
				add_edge(s, i + 2, 1);
				for(int j = 0; j <= n1; j++){
					if(par[i][j])
						add_edge(i + 2, j + n1 + 2, 1);
				}
			}
			cin >> b;
			if(b < n1)
				qr.push_back(0);
			for(int i = 0; i < b; i++){
				cin >> a;
				add_edge(a + n1 + 2, t, 1);
				qr.push_back(a);
			}

			int flow = dinic();

			bool poss = true;
			for(int i = 0; i < n1; i++){
				bool parposs = false;
				for(int j = 0; j < qr.size(); j++){
					if(par[i][qr[j]]){
						parposs = true;
						break;
					}
				}
				if(!parposs)
					poss = false;
			}

			if(poss && flow == b)
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
	}


	return 0;
}
