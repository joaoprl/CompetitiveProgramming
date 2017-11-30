
#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	vector<int> a(5, 0), b(5, 0);
	
	while(cin >> a[0]){
		bool f = true;
		for(int i = 1; i < 5; i++)
			cin >> a[i];
		for(int i = 0; i < 5; i++)
			cin >> b[i];
		bool p = true;
		for(int i = 0; i < 5; i++)
			p = p && a[i] == 1 - b[i];
		if(p)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	
	return 0;
}
