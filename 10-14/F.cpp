// F. GATTACA

#include <iostream>

using namespace std;

#define MAX_N 1010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

void constructSA(){
  int i, k, r;
  for(i = 0; i < n; i++)
    RA[i] = T[i];
  for(i = 0; i < n; i++)
    SA[i] = i;

  for(k = 1; k < n; k <<= 1 ){
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for(i = 1; i < n; i++)
      tempRA[SA[i]] =
        (RA[SA[i]] == RA[SA[i − 1]] && RA[SA[i] + k] == RA[SA[i − 1] + k ] )
          ? r : ++r;
    for(i = 0; i < n; i++)
      RA[i] = tempRA [i];
    if(RA[SA[n − 1]] == n − 1)
      break;
  }
}
