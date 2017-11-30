
#include <iostream>
#include <map>
#include <vector>

#define N 2010

using namespace std;

int n;
vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;

bool contains(const map<string, int> &m, const string &st){
  return m.find(st) != m.end();
}

string neg(const string &st){
  if(st[0] == '!')
    return string(st.begin() + 1, st.end());
  return "!" + st;
}

void dfs1(int v){
	used[v] = true;
	for(size_t i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to])
			dfs1(to);
	}
	order.push_back(v);
}

void dfs2(int v, int cl){
	comp[v] = cl;
	for(size_t i = 0; i < gt[v].size(); i++) {
		int to = gt[v][i];
		if(comp[to] == -1)
			dfs2(to, cl);
	}
}

int main(){
  ios::sync_with_stdio(false);

  int n, c = 1;
  map<string, int> m;
  while(cin >> n){
    string st1, st2;
    int k = 0;
    m.clear();
    g.clear();
    gt.clear();
    for(int i = 0; i < n; i++){
      cin >> st1 >> st2;

      int u, nu, v, nv;
      if(!contains(m, st1)){
        u = m[st1] = k++;
        nu = m[neg(st1)] = k++;
      }
      else{
        u = m[st1];
        nu = m[neg(st1)];
      }
      if(!contains(m, st2)){
        v = m[st2] = k++;
        nv = m[neg(st2)] = k++;
      }
      else{
        v = m[st2];
        nv = m[neg(st2)];
      }

      while(k > g.size()){
        g.push_back(vector<int>());
        gt.push_back(vector<int>());
      }

      g[nu].push_back(v);
      g[nv].push_back(u);

      gt[v].push_back(nu);
      gt[u].push_back(nv);
    }
    n = k;
    order.clear();
    used.assign(n, false);

    for(int i = 0; i < n; i++)
      if(!used[i])
        dfs1(i);

    comp.assign(n, -1);
    for(int i = 0, j = 0; i < n; i++){
      int v = order[n - i - 1];
      if(comp[v] == -1){
        dfs2(v, j++);
      }
    }

    cout << "Instancia " << c++ << endl;
    bool poss = true;
    for(int i = 0; i < n; i++)
      if(comp[i] == comp[i ^ 1])
        poss = false;

    if(poss)
      cout << "sim" << endl << endl;
    else
      cout << "nao" << endl << endl;
  }

  return 0;
}
