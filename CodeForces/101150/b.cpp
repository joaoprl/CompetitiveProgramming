
// B. Book Replacement

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

void remove(deque<int> &dq, int book){
  vector<int> v;
  while(dq.back() != book){
    v.push_back(dq.back());
    dq.pop_back();
  }
  dq.pop_back();
  while(v.size() != 0){
    dq.push_back(v.back());
    v.pop_back();
  }
}

int main(){
  ios::sync_with_stdio(false);
  int m, c, n;
  while(cin >> m >> c >> n && (m != 0 || c != 0 || n != 0)){
    vector< deque<int> > desks(m + 1, deque<int>());
    vector< vector<int> > students;
    int maxK = 0;
    for(int i = 0; i < n; i++){
      int k;
      cin >> k;
      maxK = max(maxK, k);
      students.push_back(vector<int>(k, 0));
      for(int j = 0; j < k; j++)
        cin >> students[i][j];
    }

    vector<int> requests;
    for(int i = 0; i < maxK; i++){
      for(int stud = 0; stud < n; stud++){
        if(i < students[stud].size())
          requests.push_back(students[stud][i]);
      }
    }

    int costs = 0;
    map<int, int> books;
    for(int i = 0; i < requests.size(); i++){
      int r = requests[i];

      int pos = books[r];
      if(pos == 0)
        costs += m + 1;
      else{
        costs += pos;
        remove(desks[pos], r);
      }

      if(desks[1].size() < c){
        desks[1].push_back(r);
        books[r] = 1;
        costs++;
      }
      else{
        int hold = 0;
        for(int d = 2; d < desks.size(); d++){
          if(desks[d].size() < c){
            hold = d;
            break;
          }
        }
        if(hold == 0)
          costs += m + 1;
        else{
          costs += hold;
          desks[hold].push_front(r);
        }

        int removed = desks[1].front();
        desks[1].pop_front();
        costs++;

        int put = 0;
        for(int d = 2; d < desks.size(); d++){
          if(desks[d].size() < c){
            put = d;
            break;
          }
        }
        if(put == 0)
          costs += m + 1;
        else{
          costs += put;
          desks[put].push_back(removed);
        }
        books[removed] = put;

        if(hold == 0)
          costs += m + 1;
        else{
          costs += hold;
          desks[hold].pop_front();
        }
        desks[1].push_back(r);
        books[r] = 1;
        costs++;
      }
    }
    cout << costs << endl;
  }

  return 0;
}
