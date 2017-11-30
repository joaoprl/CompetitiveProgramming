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

#define MAX 10010
#define INF 1000000000000000

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<ll> vi;

//const int INF = 0x3f3f3f3f;

ll mem[MAX][MAX][2];
ll v[MAX];

ll dp(int i, int j, int p){
	if(i == j)
		return (p == 1)? v[i] : 0;
	
	if(mem[i][j][p] == -INF){
		if(p == 1)
			mem[i][j][p] = max(dp(i + 1, j, 0) + v[i], dp(i, j - 1, 0) + v[j]);
		else
			mem[i][j][p] = min(dp(i+1, j, 1), dp(i, j-1, 1));
	}
	
	return mem[i][j][p];

}

int main(){
	
	int n;
	
	while(scanf("%d", &n) == 1){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				mem[i][j][0] = -INF;
				mem[i][j][1] = -INF;
			}
		
		for(int i = 0; i < n; i++){
			scanf("%lld", &v[i]);
		}
		
		printf("%lld\n", dp(0, n-1, 1));
	}
	
	return 0;
}
