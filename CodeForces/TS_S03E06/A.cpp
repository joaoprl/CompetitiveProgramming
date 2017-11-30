
// A. The Bagette Master

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int, int> pi;

#define MAX 100010
#define eps 1e-9
#define pi acos(-1)

int main(){
  double l, x, y, z, w, d;

  cin >> l >> x >> y >> z >> w >> d;

  double t[4] = {pi,pi,pi,pi};

  double res = (x + y + z + w);

  t[1] = acos((x*x + y*y - d*d)/(2*x*y));
  t[3] = acos((z*z + w*w - d*d)/(2*z*w));
  t[0] = acos((x*x + d*d - y*y)/(2*x*d)) + acos((d*d + w*w - z*z)/(2*d*w));
  t[2] = acos((y*y + d*d - x*x)/(2*y*d)) + acos((d*d + z*z - w*w)/(2*d*z));

  for(int i = 0; i < 4; i++){

    if(abs(t[i] - pi) > eps ){
      if(t[i] < pi/2){
        res += 2*l*(1/tan(t[i]) + 1/sin(t[i]));
      }
      else{
        res += 2*l*(1/sin(t[i]) - tan(t[i] - pi/2));
      }

     // printf("res = %lf\n", res);
    }
    //printf("t[%d] = %lf\n", i, t[i]);
  }

  printf("%.3lf\n", res);

}
close
