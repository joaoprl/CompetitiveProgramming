
#include <iostream>
#include <vector>

#define MOD 998244353
#define M 5001

using namespace std;
typedef long long ll;

class Integer{
	ll val;
	public:
	Integer(){
		val = 0;
	}
	Integer(const ll &v){
		val = v % MOD;
	}

	Integer operator+(const Integer &v){
		return (val + v.val) % MOD;
	}

	Integer operator*(const Integer &v){
		return (val * v.val) % MOD;
	}

  Integer operator*(const ll &v){
    return (v * val) % MOD;
  }

	Integer operator-(const int &v){
		return (val - v + MOD) % MOD;
	}

	explicit operator int(){
		return val;
	}

  friend ostream& operator<<(ostream &os, const Integer &m);
};

ostream& operator<<(ostream& os, const Integer &m){
  return os << m.val;
}

Integer mat[M][M];
Integer fat[M];

int main(){
  ios::sync_with_stdio(false);

  mat[0][0] = 1;
  for(int i = 1; i < M; i++){
    mat[i][0] = 1;
    for(int j = 1; j <= i; j++)
      mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
  }
  fat[0] = 1;
  for(int i = 1; i < M; i++)
    fat[i] = fat[i - 1] * i;

  int a, b, c;
  cin >> a >> b >> c;

  Integer out, out1 = 0, out2 = 0, out3 = 0;
  for(int k = 0; k <= min(a, b); k++)
    out1 = out1 + mat[a][k] * mat[b][k] * fat[k];
  for(int k = 0; k <= min(b, c); k++)
    out2 = out2 + mat[b][k] * mat[c][k] * fat[k];
  for(int k = 0; k <= min(a, c); k++)
    out3 = out3 + mat[a][k] * mat[c][k] * fat[k];

  out = out1 * out2 * out3;
  cout << out << endl;

  return 0;
}
