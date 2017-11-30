// I. Diferença entre Datas

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void initialize(struct tm &t, int year, int month, int day){
  t.tm_sec = t.tm_min = t.tm_hour = 0;
  t.tm_mday = day;
  t.tm_mon = month - 1;
  t.tm_year = year - 1900;
  t.tm_isdst = false;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    int year1, month1, day1, year2, month2, day2;
    char c;
    cin >> year1 >> c >> month1 >> c >> day1 >> year2 >> c >> month2 >> c >> day2;

    struct tm t1, t2;
    initialize(t1, year1, month1, day1);
    initialize(t2, year2, month2, day2);

    cout << abs(mktime(&t1) - mktime(&t2)) / (60 * 60 * 24) << endl;

  }
  
  return 0;
}
