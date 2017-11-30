#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	string n;
	while(cin >> n){

		int p = 0;
		while(n[p] == '0')
			p++;
		n = string(n.begin() + p, n.end());

		vector<int> count(10, 0);

		for(int i = 0; i < n.size(); i++){
			while(count[n[i] - '0'] == 2){
				n[i]--;
				for(int j = i + 1; j < n.size(); j++)
					n[j] = '9';

				while(n[i] < '0'){
					for(int j = i; j < n.size(); j++)
						n[j] = '9';

					count[n[i - 1] - '0']--;
					n[i - 1]--;
					i--;
				}
			}
			count[n[i] - '0']++;
		}

		p = 0;
		while(n[p] == '0')
			p++;

		for(int i = p; i < n.size(); i++)
			cout << n[i];
		cout << endl;
	}

	return 0;
}
