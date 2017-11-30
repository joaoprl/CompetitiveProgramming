
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

const int INF = 1e9;
const double EPS = 1e-6;
const double PI = acos(-1);

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define MAX 1100
#define MAXC 17000000

int mem[MAXC];

int dp(int mask){
	if(mask == 0)
		return 0;
	
	if(mem[mask] == -1){
		int res = INF;
		int i = 0;
		while((mask & (1 << i)) == 0)
			i++;
	//	printf("achado = %d\n", i);
		for(int j = i + 1; j < 24; j++){
			if(mask & (1 << j)){
				res = min(res, dp((mask & ~(1 << i)) & ~(1 << j)) + min(abs(i - j), 24 - abs(i - j) ) );
			}
		}
		
		mem[mask] = res;
	}
	
	return mem[mask];
}

int main(){
	
	int n;
	int t[24];
	
	memset(mem, -1, sizeof(mem));
	
	while(cin >> n){
		memset(t, 0, sizeof(t));
		for(int i = 0; i < n; i++){
			int aux;
			cin >> aux;
			t[aux + 11]++;
		}
		
		int mask = 0;
		
		for(int i = 0; i < 24; i++)
			if(t[i]%2 == 1){
				mask = mask | (1 << i); 
			}
		
		//printf("Mask %o\n", mask);
		
		cout << dp(mask) << endl;
		
	}
	
	return 0;
}
