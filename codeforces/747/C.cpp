// C. Servers

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task{
public:
  int t, k, d, end;
  vector<int> servers;
};

bool comp(Task a, Task b){
  return a.end > b.end;
}

int main(){
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  Task *tasks = new Task[q];
  for(int i = 0; i < q; i++){
    cin >> tasks[i].t >> tasks[i].k >> tasks[i].d;
    tasks[i].end = tasks[i].t + tasks[i].d;
  }

  vector<Task> endHeap;
  make_heap(endHeap.begin(), endHeap.end(), comp);
  int emptyServers = n;

  int *servers = new int[n];
  for(int i = 0; i < n; i++)
    servers[i] = 0;

  vector<int> out;

  for(int i = 0; i < q; i++){
    while(endHeap.size() > 0 && endHeap.front().end <= tasks[i].t){
      pop_heap(endHeap.begin(), endHeap.end(), comp);
      Task t = endHeap.back();
      endHeap.pop_back();

      for(int j = 0; j < t.servers.size(); j++){
        servers[t.servers[j]] = 0;
      }

      emptyServers += t.k;
    }

    if(emptyServers >= tasks[i].k){
      int acc = 0;
      int used = 0;
      for(int j = 0; j < n; j++){
        if(servers[j] == 0){
          servers[j] = 1;
          tasks[i].servers.push_back(j);
          acc += j + 1;
          used++;
          if(used == tasks[i].k)
            break;
        }
      }
      emptyServers -= tasks[i].k;

      endHeap.push_back(tasks[i]);
      push_heap(endHeap.begin(), endHeap.end(), comp);

      out.push_back(acc);
    }
    else
      out.push_back(-1);
  }

  for(int i = 0; i < out.size(); i++)
    cout << out[i] << "\n";

  return 0;
}
