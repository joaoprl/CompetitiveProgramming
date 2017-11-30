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

vi v;

int main(){
	int n;
	
	while(cin >> n){
		v.clear();
		v.resize(n);
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> v[i];
			sum += v[i];
		}
		
		if(sum%n != 0){
			printf("-1\n");
			continue;
		}
		
		int med = sum/n;
		
		int res = 0;
		
		for(int i = 0; i < n; i++){
			res += abs(v[i] - med);
		}
		
		res /= 2;
		
		res++;
		
		cout << res << endl;
		
	}
	
	
	return 0;
}
