#include <iostream>

#define CHS 26

using namespace std;

class Tree{
	int count;
	Tree **subtrees;

	void query(string currS, pair<string, int> &out){
		if(count < 2)
			return;
    if(count >= 2 && currS != ""){
      if(out.first.size() < currS.size() || (out.first.size() == currS.size() && out.first > currS))
        out = { currS, count } ;
    }

		for(int i = 0; i < CHS; i++){
			if(subtrees[i] != NULL){
				subtrees[i]->query(currS + (char)(i + 'A'), out);
			}
		}
	}

public:

	Tree(){
		subtrees = new Tree*[CHS];
		for(int i = 0; i < CHS; i++)
			subtrees[i] = NULL;
    count = 0;
	}

  void clear(){
    count = 0;
    for(int i = 0; i < CHS; i++){
      if(subtrees[i] != NULL){
        subtrees[i]->clear();
      }
    }
  }

  void insert(string str, int pos){
		count++;

		if(pos == str.size())
			return;

		int ch = str[pos] - 'A';

		if(subtrees[ch] == NULL)
			subtrees[ch] = new Tree();

		subtrees[ch]->insert(str, pos + 1);
	}

	void insert(string str){
		insert(str, 0);
	}

	void query(pair<string, int> &out){
		return query("", out);
	}

	~Tree(){
		delete[] subtrees;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int n;
  cin >> n;

  Tree tr;
  while(n--){
    tr.clear();
		string na;
    cin >> na;
		for(int i = 0; i < na.size(); i++)
			tr.insert(na, i);

    pair<string, int> str = {"", 0};
    tr.query(str);
    if(str.second != 0)
      cout << str.first << " " << str.second << endl;
    else
      cout << "No repetitions found!" << endl;
	}

	return 0;
}
