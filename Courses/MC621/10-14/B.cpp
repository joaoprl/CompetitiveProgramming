// B. 23 out of 5

#include <iostream>
#include <cstdlib>


using namespace std;

bool calculate(int *values, int v){
  int k = 0;
  for(int i = 0; i < 5; i++)
    if(values[i] != -1)
      k++;
  if(k == 1){
    for(int i = 0; i < 5; i++)
      if(values[i] == v && v != -1)
        return true;
    return false;
  }
  int value;


  bool b = false;
  for(int i = 0; i < 5; i++){
    if(values[i] != -1){
      value = values[i];
      values[i] = -1;

      b |= calculate(values, v - value);
      b |= calculate(values, v + value);
      if(value != 0 && v % value == 0)
        b |= calculate(values, v / value);

      values[i] = value;
    }
  }
  return b;
}
int main(){
  int values[5];
  cin >> values[0] >> values[1] >> values[2] >> values[3] >> values[4];

  while(values[0] != 0 || values[1] != 0 || values[2] != 0 || values[3] != 0 || values[4]!= 0){
    if(calculate(values, 23))
      cout << "Possible\n";
    else cout << "Impossible\n";

    cin >> values[0] >> values[1] >> values[2] >> values[3] >> values[4];
  }

  return 0;
}
