

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{
public:
  int v;
  int d;
  Edge(int v, int d){
    this->v = v;
    this->d = d;
  }
};

bool comp(Edge a, Edge b){
  return a.d > b.d;
}

int dist(string a, string b){
  int d = 0;
  for(int i = 0; i < 4; i++){
    int ma = max(a[i], b[i]);
    int mi = min(a[i], b[i]);
    d += min(ma - mi, mi + 10 - ma);
  }
  return d;
}

using namespace std;
int main(){
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for(int k = 0; k < t; k++){
    int n;
    cin >> n;
    vector<string> values;
    string value;
    int totalCost = 0;

    for(int i = 0; i < n; i++){
      cin >> value;
      values.push_back(value);
    }

    bool *chosen = new bool[n];
    for(int i = 0; i < n; i++)
      chosen[i] = false;

    chosen[0] = true;
    vector<Edge> minDist;

    for(int i = 0; i < n; i++){
      minDist.push_back(Edge(i, dist(values[0], values[i])));
      push_heap(minDist.begin(), minDist.end(), comp);
    }

    while(!minDist.empty()){
      pop_heap(minDist.begin(), minDist.end(), comp);
      Edge e = minDist.back();
      minDist.pop_back();

      if(!chosen[e.v]){
        chosen[e.v] = true;
        totalCost += e.d;
        for(int i = 0; i < n; i++){
          minDist.push_back(Edge(i, dist(values[e.v], values[i])));
          push_heap(minDist.begin(), minDist.end(), comp);
        }
      }
    }
    int mi = 1000000000;
    for(int i = 0; i < n; i++){
      mi = min(mi, dist("0000", values[i]));
    }
    cout << totalCost + mi << endl;
  }
  return 0;
}
