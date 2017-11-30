// E. xortion

#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--){
    int n, q;
    cin >> n >> q;

    int *a = new int[n];
    for(int i = 0; i < n; i++)
      cin >> a[i];

    int x, m, p;
    for(int i = 0; i < q; i++){
      cin >> x;
      
      m = a[0] ^ x;
      p = 0;

      for(int j = 1; j < n; j++){
	if((int)(a[j] ^ x) > m){
	  m = a[j] ^ x;
	  p = j;
	}
      }
      cout << p + 1 << "\n";
    }    
  }
  return 0;
}
