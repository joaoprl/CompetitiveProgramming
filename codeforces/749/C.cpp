// C. Voting

#include <iostream>
#include <queue>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  queue<int> r, d;
  char c;
  for(int i = 0; i < n; i++){
    cin >> c;
    if(c == 'D')
      d.push(i);
    else
      r.push(i);
  }

  while(r.size() != 0 && d.size() != 0){
    if(r.front() < d.front()){
      d.pop();
      r.push(r.front() + n);
      r.pop();
    }
    else{
      r.pop();
      d.push(d.front() + n);
      d.pop();
    }
  }

  if(r.size() == 0)
    cout << "D\n";
  else
    cout << "R\n";

  return 0;
}
