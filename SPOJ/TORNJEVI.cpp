
#include <iostream>
#include <vector>

#define R 110

using namespace std;
typedef pair<int, int> pii;

int n;
vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;

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
  int r, s;
  cin >> r >> s;

  char grid[r + 2][s + 2];
	for(int i = 0; i <= r + 1; i++)
		for(int j = 0; j <= s + 1; j++)
			grid[i][j] = '.';

	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= s; j++)
			cin >> grid[i][j];

	pair<int, int> mark[r + 2][s + 2];
	vector<int> towerCounter;
	towerCounter.push_back(0);
	int c = 0;
	for(int i = 0; i <= r + 1; i++){
		for(int j = 0; j <= s + 1; j++){
			mark[i][j].first = c;
			if(grid[i][j] == 'T' || grid[i][j] == '#'){
				c++;
				towerCounter.push_back(0);
				if(grid[i][j] == 'T'){
					towerCounter[c]++;
					towerCounter[c - 1]++;
				}
			}
		}
		c++;
		towerCounter.push_back(0);
	}

	for(int j = 0; j <= s + 1; j++){
		for(int i = 0; i <= r + 1; i++){
			mark[i][j].second = c;
			if(grid[i][j] == 'T' || grid[i][j] == '#'){
				c++;
				towerCounter.push_back(0);
				if(grid[i][j] == 'T'){
					towerCounter[c]++;
					towerCounter[c - 1]++;
				}
			}
		}
		c++;
		towerCounter.push_back(0);
	}

	for(int i = 0; i <= r + 1; i++){
		for(int j = 0; j <= s + 1; j++){
			mark[i][j].first *= 2;
			mark[i][j].second *= 2;
		}
	}

	g.assign(2 * (c + 1), vector<int>());
	gt.assign(2 * (c + 1), vector<int>());

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= s; j++){
			if(grid[i][j] == 'T'){
				g[mark[i][j].first].push_back(mark[i][j + 1].first ^ 1);
				gt[mark[i][j + 1].first ^ 1].push_back(mark[i][j].first);
				g[mark[i][j + 1].first].push_back(mark[i][j].first ^ 1);
				gt[mark[i][j].first ^ 1].push_back(mark[i][j + 1].first);

				g[mark[i][j].second].push_back(mark[i + 1][j].second ^ 1);
				gt[mark[i + 1][j].second ^ 1].push_back(mark[i][j].second);
				g[mark[i + 1][j].second].push_back(mark[i][j].second ^ 1);
				gt[mark[i][j].second ^ 1].push_back(mark[i + 1][j].second);
			}
			else if(grid[i][j] == 'n'){
				g[mark[i][j].first ^ 1].push_back(mark[i][j].second);
				gt[mark[i][j].second].push_back(mark[i][j].first ^ 1);

				g[mark[i][j].second ^ 1].push_back(mark[i][j].first);
				gt[mark[i][j].first].push_back(mark[i][j].second ^ 1);
			}
		}
	}

	for(int i = 0; i < towerCounter.size(); i++){
		if(towerCounter[i] != 1){
				int v = 2 * i;
				g[v].push_back(v ^ 1);
				gt[v ^ 1].push_back(v);
		}
	}

	n = 2 * c;
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

	for(int i = 0; i < n; i += 2){
		comp[i] = (comp[i] > comp[i ^ 1]);
		comp[i ^ 1] = !comp[i];
	}

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= s; j++){
			if(grid[i][j] == 'T'){
				if(comp[mark[i][j].first] && comp[mark[i][j].second ^ 1])
					cout << 1;
				if(comp[mark[i][j].first ^ 1] && comp[mark[i][j].second ^ 1])
					cout << 2;
				if(comp[mark[i][j].first ^ 1] && comp[mark[i][j].second])
					cout << 3;
				if(comp[mark[i][j].first] && comp[mark[i][j].second])
					cout << 4;
			}
			else
				cout << grid[i][j];
		}
		cout << endl;
	}

  return 0;
}
