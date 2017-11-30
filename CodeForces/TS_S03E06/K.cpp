
// K. Average Speed

#include<bits/stdc++.h>

using namespace std;

double convt(string s){
  double res = 0;
  res += 10*(double)(s[0] - '0') + (double)(s[1]-'0');
  res += (10*(double)(s[3] - '0') + (double)(s[4]-'0'))/60;
  res += (10*(double)(s[6] - '0') + (double)(s[7]-'0'))/3600;

  return res;
}

double convs(string s){
  int i = s.size() - 1;
  double mul = 1;
  double res = 0;
  while(i > 8){
    res += mul*(double)(s[i] - '0');
    mul *= 10;
    i--;
  }

  return res;
}

int main(){
  double dist = 0;
  double time = 0;
  double speed = 0;
  string s;

  getline(cin, s);
  while(s.size() != 0){
   // cout << "string " << s << endl;
    if(s.size() == 8){
      double time1 = convt(s);
      dist += (time1 - time)*speed;
      time = time1;
      cout << s << " " << fixed << setprecision(2) << dist << " " <<"km" << endl;
    }

    else{
      double time1 = convt(s);
      dist += (time1-time)*speed;
      time = time1;
      speed = convs(s);
    }
    getline(cin, s);
  }
}
close
