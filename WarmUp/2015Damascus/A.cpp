// A. Random Fightings

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXSIZE 20

int main()
{
  int t;
  cin >> t;

  int n;
  double **a = new double*[MAXSIZE];
  for(int i = 0;  i < MAXSIZE; i++){
    a[i] = new double[MAXSIZE];
  }
  
  for(int c = 1; c <= t; c++){
    
    cin >> n;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	cin >> a[i][j];

    
    printf("Case %d:", c);
    for(int i = 0; i < n; i++)
      printf(" %.6f", (double)0);
    printf("\n");    
  }
  return 0;
}
