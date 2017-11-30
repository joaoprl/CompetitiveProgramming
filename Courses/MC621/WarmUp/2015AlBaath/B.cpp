// B. 8 Queens, Again!!

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    bool line[8], row[8], princ[15], sec[15], valid;
    
    memset(line, 0, sizeof(line));
    memset(row, 0, sizeof(row));
    memset(princ, 0, sizeof(princ));
    memset(sec, 0, sizeof(sec));
    valid = true;

    
    for(int j = 0; j < 8; j++){
      
      char c;
      int x, y;

      cin >> c;
      x = c - 'A';

      cin >> c;

      y = c - '1';

      if(valid){
	if(line[x] || row[y] || princ[x + y] || sec[7 - x + y])
	  valid = false;	

	line[x] = true;
	row[y] = true;
	princ[x + y] = true;
	sec[7 - x + y] = true;
      }
    }
    if(valid)
      cout << "Valid\n";
    else
      cout << "Invalid\n";
  }
  return 0;
}
