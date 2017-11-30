#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct point{
	ll x, y;
	point() { x = y = 0; }
	point(ll _x, ll _y) : x(_x), y(_y) { }
	bool operator<(point p) const{
		if(x != p.x)
			return x < p.x;
		return y < p.y;
	}
	bool operator==(point p) const{
		return x == p.x && y == p.y;
	}
};

ll abs2(ll x){ return max(x, -x); }

ll cp(point a, point b){
	return a.x * b.y - a.y * b.x;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n){

		vector<point> ps;
		ll x, y;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			ps.push_back(point(x, y));
		}

		vector<ll> ar;
		ar.push_back(0);
		for(int i = 0; i < 2 * n; i++)
			ar.push_back(cp(ps[i % n], ps[(i + 1) % n]));

		for(int i = 1; i < ar.size(); i++)
			ar[i] += ar[i - 1];

		for(int i = 0; i < n; i++)
			ps.push_back(ps[i]);

		ll carol = 0, carla = 0;
		for(int i = 0; i < n; i++){
			int lo = i + 2;
			int hi = i + n - 2;

			while(lo != hi){
				int mid = (hi + lo) / 2;

				ll vol1, vol2;
				vol1 = abs2(ar[mid] - ar[i] + cp(ps[mid], ps[i]));
				vol2 = abs2(ar[i + n] - ar[mid] + cp(ps[i + n], ps[mid]));
				ll volmid = min(vol1, vol2);

				mid++;
				vol1 = abs2(ar[mid] - ar[i] + cp(ps[mid], ps[i]));
				vol2 = abs2(ar[i + n] - ar[mid] + cp(ps[i + n], ps[mid]));
				ll volmidg = min(vol1, vol2);

				if(volmidg > volmid)
					lo = mid;
				else{
					hi = mid - 1;
				}
			}

			int mid = (hi + lo) / 2;

			ll vol1, vol2;
			vol1 = abs2(ar[mid] - ar[i] + cp(ps[mid], ps[i]));
			vol2 = abs2(ar[i + n] - ar[mid] + cp(ps[i + n], ps[mid]));
			ll volmid = min(vol1, vol2);

			if(vol1 < vol2)
				swap(vol1, vol2);

			if(vol1 > carol){
				carol = vol1;
				carla = vol2;
			}
		}
		cout << carol << " " << carla << endl;
	}

	return 0;
}
