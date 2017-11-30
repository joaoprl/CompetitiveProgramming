// G. Graph Connectivity

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void dfs(vector<int> *edges, int v, int n, bool *found){
  if(found[v])
    return;

  found[v] = true;
  for(int i = 0; i < edges[v].size(); i++)
    dfs(edges, edges[v][i], n, found);
}

int main(){
  ios::sync_with_stdio(false);

  string line;
  getline(cin, line);
  istringstream iss(line);
  int t;
  iss >> t;

  bool first = true;
  getline(cin, line); // blank
  while(t--){

    char c;
    getline(cin, line);
    c = line[0];

    int n = c - 'A' + 1;
    vector<int> *edges = new vector<int>[n];

    while(getline(cin, line) && !line.empty()){
      edges[line[0] - 'A'].push_back(line[1] - 'A');
      edges[line[1] - 'A'].push_back(line[0] - 'A');
    }

    bool *found = new bool[n];
    for(int i = 0; i < n; i++)
      found[i] = false;

    int count = 0;
    for(int i = 0; i < n; i++){
      if(!found[i]){
        dfs(edges, i, n, found);
        count++;
      }
    }
    if(!first){
      cout << endl;
    }
    cout << count << endl;
    first = false;
  }

  return 0;
}
