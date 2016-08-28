// E. Ant on a Chessboard

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
  int n, x, y, r, sq;

  cin >> n;

  while(n > 0){ 
    sq = (int)sqrt(n);
    r = n - (sq * sq);
    
    y = 1;
    x = sq;
    
    if(r > 0){
      if(r >= sq + 1){
	y += sq;
	r -= sq + 1;
	x++;
	x -= r;      
      }else{
	y += r - 1;
	x++;
      }
    }
    
    if(sq % 2 == 1){
      r = x;
      x = y;
      y = r;
    }
    cout << x << " " << y << "\n";      

    cin >> n;
    
  }
  
  return 0;
}
