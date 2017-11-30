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
typedef vector<ll> vi;

//const int INF = 0x3f3f3f3f;

#define MAX 1e18
#define INF 8000000000000000000

vi org, fi;

int swap(int i, int j){
	if(j<=i)
		return 0;
	int res = j - i;
	int aux = org[j];
	for(int k = j; k > i; k--)
		org[k] = org[k-1];
	org[i] = aux;
	return res;
}

int main(){
	
	int n;
	
	while(cin >> n){
		org.clear(); fi.clear();
		for(int i = 0; i < n; i++){
			int aux;
			cin >> aux;
			org.pb(aux);
		}
		
		for(int i = 0; i < n; i++){
			int aux;
			cin >> aux;
			fi.pb(aux);
		}
		
		int res = 0;
		
		for(int i = 0; i < n; i++){
			int j = 0;
			while(org[j] != fi[i])
				j++;
			res += swap(i, j);
		}
		cout << res << endl;
	}
	
	return 0;
}
