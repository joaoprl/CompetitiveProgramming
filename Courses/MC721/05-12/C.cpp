
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

class Word{
public:
  string id1, id2, word;
  Word(string id1, string id2, string word){
    this->id1 = id1;
    this->id2 = id2;
    this->word = word;
  }

  bool isFrom(string id){
    return id == id1 || id == id2;
  }
};

int main(){
  ios::sync_with_stdio(false);

  int m;
  while(cin >> m){
    string o, d;
    cin >> o >> d;
    string st1, st2, w;
    set<Word> words;
    // unordered_map<string, vector<Word> > ids;
    for(int i = 0; i < m; i++){
      cin >> st1 >> st2 >> w;
      words.insert(Word(st1, st2, w));

      // ids[st1] =
    }
  }

  return 0;
}
