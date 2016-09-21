// G. Seleção

#include <cstdio>
#include <queue>

#define MOD (long long)(1e9+7)

using namespace std;

int main(){
  long long n, sum, x, median;
  priority_queue<long long, vector<long long>, greater<long long> > min_q;
  priority_queue<long long> max_q;

  scanf("%lld", &n);
  scanf("%lld", &median);
  sum = median;

  for(int i = 1; i < n; i++){
    scanf("%lld", &x);

    if(x <= median){
      if(min_q.size() > max_q.size())
        max_q.push(x);
      else{
        min_q.push(median);

        max_q.push(x);
        median = max_q.top();
        max_q.pop();
      }
    }
    else if(x > median){
      if(min_q.size() > max_q.size()){
        max_q.push(median);

        min_q.push(x);
        median = min_q.top();
        min_q.pop();
      }
      else
        min_q.push(x);
    }
    sum = (sum + median) % MOD;
  }
  printf("%lld\n", sum);

  return 0;
}
