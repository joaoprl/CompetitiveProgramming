// A. Beehives

#include<bits/stdc++.h>
#include <cstdio>
#include <vector>

#define INF 1000000000
#define MAX 505

using namespace std;

int dis[MAX];
int vis[MAX];
int dad[MAX];

int bfs(int pos, vector<int>* adj){
	queue<int> fila;	
	fila.push(pos);
	
	dis[pos] = 0;
	
	int r = INF;
	
	//printf("bfs em %d\n", pos);
	
	while(!fila.empty()){
		int a = fila.front();
		fila.pop();
		//printf("	visita %d\n", a);
		for(int i = 0; i < adj[a].size(); i++){
			int nx = adj[a][i];
			if(dis[nx] == INF){
				dis[nx] = dis[a] + 1;
				dad[nx] = a;
				fila.push(nx);
			}
			else if(dad[a] != nx){
				r = min(r ,dis[a] + dis[nx] + 1);
				if(r == 3) return r;
			}
		}
	}
	
	return r;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int c = 1; c <= t; c++){
		int mDist = INF;
		int n, m;
		scanf("%d%d", &n, &m);
		
		vector<int> *edges = new vector<int>[n];
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			//if(c == 18)
				//printf("%d %d\n", u, v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		int mat[MAX][MAX];
		
		for(int i = 0; i < n; i++)
			memset(mat[i], -1, sizeof(mat[i]));
			
		for(int i = 0; i < n; i++){
			memset(dad, -1, sizeof(dad));
			for(int j = 0; j < n; j++)
				dis[j] = INF;
			
			mDist = min(mDist, bfs(i, edges));
		}

		
		if(mDist == INF)
			printf("Case %d: impossible\n", c);
		else
			printf("Case %d: %d\n", c, mDist);
	}

	return 0;
}
