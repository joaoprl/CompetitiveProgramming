// D. Dating On-Line

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define PI 3.141592653589793

using namespace std;

int main(){
  int n, score;
  vector<int> scores;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> score;
    scores.push_back(score);
  }
  sort(scores.begin(), scores.end(), greater<int>());

  int sz = scores.size();
  long long area = scores[0] * scores[1] + scores[sz - 1] * scores[sz - 2];
  for(int k = 0; k + 2 < sz; k++){
    area += scores[k] * scores[k + 2];
  }

  printf("%.3lf\n", ((double)area) * sin(2 * PI / n) / 2);

  return 0;
}
