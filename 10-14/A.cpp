// A. Word Transformation

#include <iostream>
#include <vector>
#include <set>

#define MAX 201
#define INF 1000

using namespace std;

int Dijkstra(int **graph, int from, int to, int V){
  set<int> Q;

  for(int i = 0; i < V; i++){
    dist[i] = INF;
    prev[i] = -1;
    Q.add(i);
  }
  dist[from] = 0;

  while(!Q.empty()){
    
  }
}


int dist(string str1, string str2){
  if(str1.size() != str2.size())
    return INF;

  int d = 0;
  for(int i = 0; i < str1.size() && i < str2.size(); i++)
    d++;
  return d;
}

int main(){
  int t;
  cin >> t;
  string str;
  vector<string> dic;
  int graph[MAX][MAX];

  while(t--){
    dic.clear();

    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++)
        graph[i][j] = 0;
    str = "";
    while(str != "*"){
      cin >> str;
      for(int i = 0; i < dic.size(); i++)
        if(dist(str, dic[i]) == 1){
          graph[dic.size()][i] = 1;
          graph[i][dic.size()] = 1;
        }
        dic.push_back(str);
    }

    string str1, str2;
    while(cin >> str1 >> str2){
      int from, to;
      for(int i = 0; i < dic.size(); i++){
        if(dic[i] == str1)
          from = i;
        if(dic[i] == str2)
          to = i;
      }
    }

    cout << str1 << " " << str2 << " " << DFS(graph, from, to) << "\n";


  }

  return 0;
}
