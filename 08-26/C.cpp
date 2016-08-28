// C. Help Dexter

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

void nextValid(long long &x, long long q){
  x += 2;
  
  stringstream out;
  out << x;
  string s = out.str();
  for(int i = 0; i < s.size(); i++)
    if(s[i] != '1' && s[i] != '2'){
      s.replace(s.begin() + i, s.end(), s.size() - i, '1');
      i--;
      while(s[i] != '1' && i >= 0){
	s[i] = '1';
	i--;
      }
      if(i >= 0)
	s[i] = '2';
      x = atoll(s.c_str());
      x++;
      break;
    }
}

void previousValid(long long &x, long long q){
  x -= 2;
  
  stringstream out;
  out << x;
  string s = out.str();
  for(int i = 0; i < s.size(); i++)
    if(s[i] != '1' && s[i] != '2'){      
      s.replace(s.begin() + i, s.end(), s.size() - i, '2');
      i--;
      while(s[i] != '2' && i >= 0){
	s[i] = '2';
	i--;
      }
      if(i >= 0)
	s[i] = '1';
      
      x = atoll(s.c_str());
      break;
    }
}

int main(){
  
  long long t, p, q, s, l, x, v;
  cin >> t;

  for(int i = 1; i <= t; i++){
    cin >> p >> q;
    q = 1 << q;

    v = (long long)pow(10, p - 1);
    x = 1;
    while(x < v)
      x = 10 * x + 1;
    x++;

    v = 2;
    while(v < x)
      v = 10 * v + 2;;
    while(x < v && x % q != 0)
      nextValid(x, q);
    
    s = 0;
    if(x <= v && x % q == 0)
      s = x;
    else{
      printf("Case %d: impossible\n", i);
      continue;
    }
    x = v;    
    while(x > s && x % q != 0)
      previousValid(x, q);

    l = 0;
    if(x > s)
      l = x;
     
    if(l == 0)
      printf("Case %d: %lld\n", i, s);
    else
      printf("Case %d: %lld %lld\n", i, s, l);
  }
  return 0;
}
