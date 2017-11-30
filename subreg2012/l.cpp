
#include <iostream>
#include <vector>
#include <bitset>


#define N 100000

typedef long long ll;

using namespace std;

vector<ll> primes;
ll _sieve_size;
bitset<10000010> bs;


void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++)
		if(bs[i]){
			for(ll j = i * i; j <= _sieve_size; j += i) 
				bs[j] = 0;
			primes.push_back((int) i);
		}
}

ll tot(ll n){
	ll PF_idx = 0, PF = primes[PF_idx], ans = n;
	while(n != 1 && (PF * PF <= n)){
		if(n % PF == 0)
			ans -= ans / PF;
		while(n % PF == 0)
			n /= PF;
		PF = primes[++PF_idx];
	}
	if(n != 1) 
		ans -= ans / n;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	sieve(N);
	ll n;
	while(cin >> n){
		cout << tot(n) / 2 << endl;
	}
	
	return 0;
}
