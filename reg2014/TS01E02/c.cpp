
#include <iostream>
#include <vector>
#define int long long

using namespace std;

int32_t main(){
	ios::sync_with_stdio(false);
	string s;
	while(cin >> s){
		vector<int> c = {1, 0, 0};
		int count = 0;
		int acc = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] < '0' || s[i] > '9'){
				c = {1, 0, 0};
				acc = 0;
			}
			else{
				acc = (acc + s[i] - '0') % 3;
				count += c[acc];
				c[acc]++;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}
