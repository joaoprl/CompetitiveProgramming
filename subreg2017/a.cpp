#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) //cerr << setprecision(10) << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define mkp make_pair
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

//const int INF = 0x3f3f3f3f;

#define	MAX2 1000000000100
#define MAX 1000500
#define INF 8000000000000000000

vector< vi > s;
vi a, lazy;
int n, q;

void build(int id = 1, int l = 0, int r = n){
	//cout << "build " << id << endl;
	s[id].assign(9, 0);

	//printf("ok1\n");
	if(r - l < 2){
		s[id][1] = 1;
		return;
	}

	int mid = (l + r)/2;
	build(id* 2, l, mid);
	build(id*2 + 1, mid, r);


	for(int i = 0; i < 9; i++)
		s[id][i] = s[id*2][i] + s[id*2 + 1][i];
}

void upd(int id, int l, int r, int x){
	vi aux(9);
	lazy[id] += x;

	for(int i = 0; i < 9; i++)
		aux[(i+x)%9] = s[id][i];
	for(int i = 0; i < 9; i++)
		s[id][i] = aux[i];
}

void shift(int id, int l, int r){
	int mid = (l + r)/2;

	upd(id*2, l, mid, lazy[id]);
	upd(id*2 + 1, mid, r, lazy[id]);

	lazy[id] = 0;
}

void increase(int x, int y, int v, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, v);
		return;
	}
	shift(id, l, r);
	int mid = (l + r)/2;
	increase(x, y, v, id*2, l, mid);
	increase(x, y, v, id*2 + 1, mid, r);

	for(int i = 0; i < 9; i++)
		s[id][i] = s[id*2][i] + s[id*2 + 1][i];
}

vi sum(int x, int y, int id = 1, int l = 0, int r = n){
	//cout << "sum id = " << id << endl;

	vi aux;
	aux.assign(9, 0);
	if(x >= r or l >= y) return aux;
	if(x <= l && r <= y) return s[id];

	//cout << "ok1\n" << endl;
	shift(id, l, r);
	int mid = (l + r)/2;
	vi ve(9), vd(9);

	ve = sum(x, y, 2*id, l, mid);
	vd = sum(x, y, 2*id + 1, mid, r);

	for(int i = 0; i < 9; i ++)
		aux[i] = ve[i] + vd[i];

	return aux;
}

int main(){

	vi vf;

	scanf("%d %d", &n, &q);

	s.resize(4*n+4);
	lazy.resize(4*n + 4);

	build();

	int A, B;

	for(int k = 0; k < q; k++){

		//if(k%1000 == 0)
			//printf("k = %d\n", k);

		scanf("%d %d", &A, &B);

		vf = sum(A, B + 1);

		//printf("sum ok\n");

		int f, mx = -1;

		for(int i = 0; i <9; i++){
			if(vf[i] > mx){
				mx = vf[i];
				f = i;
			}

			else if(mx == vf[i] && i > f)
				f = i;
		}

		increase(A, B + 1, f);

	//	for(int z = 0; z < n; z++){
	//		if(s[z].size() != 0)
	////			for(int om = 0; om < 9; om ++)
	//				cout << s[z][om] << " ";
		//	cout << endl;
		//}

	}

	int f;

	for(int j = 0; j < n; j++){
		vf = sum(j, j+1);
		for(int i = 0; i <9; i++){
			if(vf[i] == 1){
				f = i;
				break;
			}
		}
		printf("%d\n", f);
	}



	return 0;
}
