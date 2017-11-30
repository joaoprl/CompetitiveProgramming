#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define MAX 10000100

using namespace std;

bool solvable(int ans, vector<int> &add, int n){
	int count = 1;
	int pos = add.front() + ans;

	for(int i = 0; i < add.size(); i++){
		if(abs(add[i] - pos) > ans){
			pos = add[i] + ans;
			count++;
		}
	}

	if(count <= n)
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	vector<int> add;
	int n, m, t;
	int num;

	cin >> t;
	for(int c = 0; c < t; c++){
    int a = MAX, b = 0, ans;
    add.clear();
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> num;
			num *= 10;
			add.push_back(num);
			a = min(a, num);
			b = max(b, num);
		}
		sort(add.begin(), add.end());

		b = b - a;
		a = 0;

		while(a != b){
			ans = (a + b) / 2;

			if(solvable(ans, add, n))
				b = ans;
			else
				a = ans + 1;

		}

		cout << a / 10 <<  "." << a % 10 << endl;
	}

	return 0;
}
