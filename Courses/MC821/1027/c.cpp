
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while(t--){
		int at, ad, bt, bd, h;
		cin >> at >> ad >> bt >> bd >> h;

		int ti = 0;
		int f = 0;
		while(h > 0){
			if(ti % ad == 0){
				h -= at;
			}
			if(h <= 0){
				f = 1;
				break;
			}

			if(ti % bd == 0){
				h -= bt;
			}
			if(h <= 0)
				f = 2;
			ti++;
		}

		if(f == 1)
			cout << "Andre" << endl;
		else if(f == 2)
			cout << "Beto" << endl;
	}

	return 0;
}
