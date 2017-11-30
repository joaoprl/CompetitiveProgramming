
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double EPS = 1e-12;
double INF = 1e100;

struct PT{
	double x, y;
	PT(double x, double y) : x(x), y(y){}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c)	const { return PT(x*c, y*c); }
	PT operator / (double c)	const { return PT(x/c, y/c); }
};

double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }

PT ProjectPointSegment(PT a, PT b, PT c){
	double r = dot(b - a, b - a);
	if(fabs(r) < EPS) return a;
	r = dot(c - a, b - a) / r;
	if(r < 0) 	return a;
	if(r > 1)	return b;
	return a + (b - a) * r;
}

double DistancePointSegment(PT a, PT b, PT c){
	return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n){
		int l, h, xi, yi, xf, yf, oxi, oyi, oxf, oyf;
		cin >> l >> h;
		
		cin >> oyi >> oxf >> oyf;
		oxi = 0;
		PT ptli = PT(0, 0), ptlf = PT(0, h);
		PT ptri = PT(l, 0), ptrf = PT(l, h);
		PT pti = ptri, ptf = ptrf;		
		double dist = DistancePointSegment(pti, ptf, PT(oxf, oyf));
		
		for(int i = 1; i < n; i++){
			cin >> yi >> xf >> yf;
			xi = 0; pti = ptri; ptf = ptrf;
			if(i % 2 == 1){
				xi = l; pti = ptli; ptf = ptlf;
			}
				
			dist = min(dist, DistancePointSegment(PT(xi, yi), PT(xf, yf), PT(oxf, oyf)));
			dist = min(dist, DistancePointSegment(pti, ptf, PT(xf, yf)));
			
			oxi = xi;
			oxf = xf;
			oyi = yi;
			oyf = yf;
		}
		cout << fixed << setprecision(2) << dist << endl;
	}
	
	return 0;
}
