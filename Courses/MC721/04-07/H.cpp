
#include <iostream>

#define N 10000

using namespace std;


int main(){
  ios::sync_with_stdio(false);

  int n, num, streak, oldStreak;

  while(cin >> n && n != 0){
    oldStreak = streak = 0;
    for(int i = 0; i < n; i++){
      cin >> num;

      oldStreak = max(oldStreak + num, num);
      streak = max(streak, oldStreak);
    }

    if(streak > 0)
      cout << "The maximum winning streak is " << streak << ".\n";
    else
      cout << "Losing streak.\n";
  }

  return 0;
}
