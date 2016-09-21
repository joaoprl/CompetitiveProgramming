// A. Soldier and Cards

#include <iostream>
#include <list>

#include <cstdio>

using namespace std;

bool checkInitial(list<int> &deck1, list<int> &deck2, list<int> &iDeck1, list<int> &iDeck2){
  list<int>::const_iterator i, j;
  i = deck1.begin();
  j = iDeck1.begin();
  while(i != deck1.end() && j != iDeck1.end()){
    if(*i != *j)
      return false;
    i++;
    j++;
  }

  i = deck2.begin();
  j = iDeck2.begin();
  while(i != deck2.end() && j != iDeck2.end() && *i == *j){
    if(*i != *j)
      return false;
    i++;
    j++;
  }
  return true;
}

int main(){
  int n, k1, k2, card;
  list<int> deck1, deck2, iDeck1, iDeck2;
  cin >> n;

  cin >> k1;
  for(int i = 0; i < k1; i++){
    cin >> card;
    deck1.push_back(card);
    iDeck1.push_back(card);
  }

  cin >> k2;
  for(int i = 0; i < k2; i++){
    cin >> card;
    deck2.push_back(card);
    iDeck2.push_back(card);
  }

  int k = 0;
  do{
    if(deck1.front() > deck2.front()){
      card = deck2.front();
      deck2.pop_front();
      deck1.push_back(card);

      card = deck1.front();
      deck1.pop_front();
      deck1.push_back(card);
    }
    else if(deck2.front() > deck1.front()){
      card = deck1.front();
      deck1.pop_front();
      deck2.push_back(card);

      card = deck2.front();
      deck2.pop_front();
      deck2.push_back(card);
    }
    k++;
  }while(!deck1.empty() && !deck2.empty() && k < 500000);
  // 500000 > 1! + ... + 9!

  if(deck1.empty())
    cout << k << " 2\n";
  else if(deck2.empty())
    cout << k << " 1\n";
  else
    cout << "-1\n";

  return 0;
}
