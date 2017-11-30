#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define eps 1e-10

int n, l;

vi v;

bool suf(double d){
	if(((double)v[0] - d) > eps)
		return false;

	//printf("seg\n");

	if((double)(l - v[n-1]) > d + eps)
		return false;

	//printf("vai pro for\n");

	for(int i = 0; i < n - 1; i++){

		//printf("i = %d v = %d %d\n", i, v[i+1], v[i]);
		if((double)(v[i+1] - v[i]) > 2*(d + eps))
			return false;
	}

	return true;
}

int main(){
	cin >> n >> l;

	v.resize(n);

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);


	sort(v.begin(), v.end());


	double mn = 0;
	double mx = (double)(2*l);

	double md;

	int cnt = 1000;

	while(mx - mn > eps && (cnt--) > 0){
		md = (mx + mn)/2;
		//printf("mx = %lf mn = %lf md = %lf\n", mx, mn, md);
		if(suf(md)){
			mx = md;
		//	printf("op1\n");
		}
		else
			mn = md;
	}

	printf("%lf\n", md);


	return 0;
}
