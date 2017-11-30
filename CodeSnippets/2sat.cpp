// 2sat
// O(N + M)

int n;
vector <vector <int>> g, gt;
vector <bool> used;
vector <int> order, comp;

void dfs1 (int v) {
	used [v] = true;
	for (size_t i = 0; i <g [v] .size (); ++ i) {
		int to = g [v] [i];
		if (! used [to])
			dfs1 (to);
	}
	order.push_back (v);
}

void dfs2 (int v, int cl) {
	comp [v] = cl;
	for (size_t i = 0; i <gt [v] .size (); ++ i) {
		int to = gt [v] [i];
		if (comp [to] == -1)
			dfs2 (to, cl);
	}
}

int main () {
    // build g and its transpost, gt

	used.assign (n, false);
	for (int i = 0; i <n; ++ i)
		if (! used [i])
			dfs1 (i);

	comp.assign (n, -1);
	for (int i = 0, j = 0; i <n; ++ i) {
		int v = order [ni-1];
		if (comp [v] == -1)
			dfs2 (v, j ++);
	}

    // if comp[i] == comp[i ^ 1] then there is no solution (i and ^1 belong to the same component)
	for (int i = 0; i <n; ++ i)
		if (comp [i] == comp [i ^ 1]) {
			puts ("NO SOLUTION");
			return 0;
		}

    // if comp[i] > comp[i ^ 1] then i is marked as true
	for (int i = 0; i <n; ++ i) {
		int ans = comp [i]> comp [i ^ 1]? i: i ^ 1;
		printf ("% d", ans);
	}

}
