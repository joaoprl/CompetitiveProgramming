
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000010
ll ac[MAX];
ll ac2[MAX];
int main(){
	int t;
	cin >> t;
	ac[0] = 0;
	ac2[0] = 0;
	ac2[1] = 0;
	for(ll i = 1; i < MAX; i++){
		ac[i] = ac[i-1] + ((i + 1)*i)/2;
	}
	for(ll i = 2; i < MAX; i++){
		ac2[i] = ac2[i-2] + ((i -1)*i)/2;
	}
	while(t--){
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", ac[n] + ac2[n]);
	}
	return 0;
}
