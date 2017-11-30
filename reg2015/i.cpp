#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;

	while(cin >> t){

		int res = 0;

		for(int i = 0; i < 5; i++){
			int aux;
			cin >> aux;

			if(aux == t)
				res++;
		}

		cout << res << endl;
	}
	return 0;
}
