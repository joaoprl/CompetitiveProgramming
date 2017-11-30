
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

int main(){
	ll a, b;
	
	while(cin >> a >> b){
		string s;
		
		cin >> s;
		
		int nb = 0, nw = 0;
		
		for(int i = 0; i < s.size(); i++)
			if(s[i] == 'B')
				nb++;
			else
				nw++;
		
		int i = nb - 1;
		
		while(i >= 0 && s[i] == 'B')
			i--;
		
		int j = nb;
		
		while(j < s.size() && s[j] == 'W')
			j++;
		
		ll cost = 0;
		
		while( i >= 0 && j < s.size() && (j - i)*(a - b) <= a){
			cost += (j - i)*(a - b);
			swap(s[i], s[j]);
			while(i >= 0 && s[i] == 'B')
				i--;
			while(j < s.size() && s[j] == 'W')
				j++;
		}
		
		for(int k = nb; k < s.size(); k++)
			if(s[k] == 'B')
				cost += a;
		
		cout << cost << endl;
	}
	
	return 0;
}
