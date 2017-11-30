#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define EPS 1e-10

struct point { double x, y;
	point() { x = y = 0.0;}
	point(double _x, double _y): x(_x), y(_y) {}
	bool operator < (point other) const{
	if(fabs(x - other.x) > EPS)
		return x < other.x;
	return y < other.y; }

	bool operator == (point other) const {
	return  (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }};

struct vec{ double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s){
	return vec(v.x*s, v.y*s);}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dot(vec a, vec b){return (a.x*b.x + a.y*b.y); }

double norm_sq(vec v){	return v.x*v.x + v.y*v.y;}

double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab)/norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab)/ norm_sq(ab);
	if(u < 0.0){c = point(a.x, a.y);
		return dist(p, a);}
	if(u > 1.0){c = point(b.x, b.y);
		return dist(p, b);}
	return distToLine(p, a, b, c);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;}

bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;}


int main(){

	ll n, a;

	while(cin >> n >> a && n != 0){

		vector<point> v;

		ll m = 0;

		v.resize(n);

		for(int i = 0; i < n; i++){
			double a, b;

			scanf("%lf %lf", &a, &b);

			v[i] = point(a, b);
		}

		vector<point> cor;
		cor.pb(point(0,0));
		cor.pb(point(a,0));
		cor.pb(point(0,a));
		cor.pb(point(a,a));

		for(int i = 0; i < n; i++){
			int s = 1;

			for(int j = 0; j < 4; j++){
				if(dist(v[i], cor[j]) > (double)a){
					s = 0;
					//printf("i = %d j = %d\n", i, j);
					//printf("%lf %lf\n", dist(v[i], cor[j]), (double)a + EPS);
				}
			}

			m += s;
		}

		printf("%.5lf\n", ((double)(m*a*a))/(double)n);
	}

	return 0;
}
