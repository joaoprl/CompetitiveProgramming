// Lights, Snakes and Cages

#include <iostream>

using namespace std;

int minArr(int *ch){
  if(ch[0] <= ch[1])
    if(ch[0] <= ch[2])
      return 0;
  if(ch[1] <= ch[2])
    return 1;
  return 2;
}

int main(){
  int n;
  cin >> n;

  int *ch = new int[3];
  int *wr = new int[3];
  ch[0] = ch[1] = ch[2] = 0;

  int *arr = new int[n + 1];
  for(int i = 1; i <= n; i++)
    arr[i] = -1;

  int *in = new int[n + 1];
  for(int i = 1; i <= n; i++)
    cin >> in[i];

  int k, size, j;
  for(int i = 1; i <= n; i++){
    if(arr[i] == -1){
      size = 1;
      k = i;
      while(in[k] != i){
        k = in[k];
        size++;
      }

      int last = -1;
      wr[1] = minArr(ch);
      ch[wr[1]] += 2;
      wr[0] = minArr(ch);
      ch[wr[0]] += 2;
      wr[2] = minArr(ch);
      ch[wr[2]] += 2;

      k = i;
      j = 0;
      while(arr[k] == -1){
        if(arr[in[k]] != wr[j])
          arr[k] = wr[j];
        else{
          j = (j + 1) % 3;
          arr[k] = wr[j];
        }

        ch[arr[k]]++;
        j = (j + 1) % 3;
        k = in[k];
      }
    }
  }

  for(int i = 1; i <= n; i++)
    cout << (char)(arr[i] + 'A');
  cout << "\n";

  delete[] in;
  delete[] arr;
  delete[] ch;

  return 0;
}
