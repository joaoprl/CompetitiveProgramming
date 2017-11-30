// FFT

#include <iostream>
#include <complex>
#include <cstring>

using namespace std;

// O(n logn)
typedef complex<double> comp;
const double pi = acos(-1.0);
const int MAXN = 505000;

int rev[MAXN * 2];

void fft(comp p[], int n, bool invert){
  int dig = 0;
  while((1 << dig) < n)
    dig++;
  for(int i = 0; i < n; i++){
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (dig - 1));
    if(rev[i] > i)
      swap(p[i], p[rev[i]]);
  }

  for(int len = 2; len <= n; len <<= 1){
    double angle = 2 * pi / len;
    if(invert)
      angle *= -1;
    comp wgo(cos(angle), sin(angle));
    for(int i = 0; i < n; i+= len){
      comp w(1);
      for(int j = 0; j < (len >> 1); j++){
        comp a = p[i + j], b = w * p [i + j + (len >> 1)];
        p[i + j] = a + b;
        p[i + j + (len >> 1)] = a - b;
        w *= wgo;
      }
    }
  }
  if(invert)
    for(int i = 0; i < n; i++)
      p[i] /= n;
}

comp a[MAXN * 2], b[MAXN * 2];
int ans[MAXN * 2];
int alen, blen, total;

int main(){
  ios::sync_with_stdio(false);
  int n, num;
  cin >> n;

  for(int i = 0; i < MAXN; i++)
    a[i] = b[i] = 0;

  for(int i = 0; i < n; i++){
    cin >> num;
    a[num] = b[num] = 1;
  }

  n = 200000;
  int len = 1;
  while(len < n)
    len *= 2;

  total = len;
  total *= 2;

  fft(a, total, false);

  for(int i = 0; i < total; i++)
    a[i] = a[i] * a[i];

  fft(a, total, true);

  int m, count = 0;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> num;
    if(floor(a[num].real() + 0.5) != .0 || b[num] != .0)
      count++;
  }
  cout << count << endl;


  return 0;
}
