#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	while(cin >> n >> m){
		int fez = 0, faria = 0;
		for(int i = 0; i < m; i++){
			int b;
			cin >> b;
			int d;
			cin >> d;
			int sum = 0, aux;
			for(int i = 0; i < n - 1; i++){
				cin >> aux;
				sum += aux;
			}

			if( d + sum <= b){
				fez += d;

				while(10*d + sum <= b && d <= 1000)
					d *= 10;

				faria += d;
			}

			else{
				while(d + sum > b && d > 0)
					d /= 10;

				faria += d;
			}
		}

		cout << faria - fez << endl;
	}
	return 0;
}
