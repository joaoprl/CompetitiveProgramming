// E. Hongcow Buys a Deck of Cards

#include <iostream>
#include <vector>
#include <climits>

#define N 140000

using namespace std;

class Card{
public:
  char c;
  int r, b;
};

int compute(vector<Card> cards, int bTokens, int rTokens, int bCards, int rCards, bool *bought, int *values){
  int t = 0;

  for(int i = 0; i < cards.size(); i++){
    if(bought[i]){
      t += (1 << i);
    }
  }
  if(values[t] != -1)
    return values[t];

  int rounds = INT_MAX;

  for(int i = 0; i < cards.size(); i++){
    if(!bought[i]){
      bought[i] = true;

      int bTokens2, rTokens2, rCards2, bCards2;

      bTokens2 = bTokens - max(cards[i].b - bCards, 0);
      rTokens2 = rTokens - max(cards[i].r - rCards, 0);

      int cRounds = 0;
      if(bTokens2 < 0){
        rTokens2 = rTokens2 - bTokens2;
        cRounds -= bTokens2;
        bTokens2 = 0;
      }
      if(rTokens2 < 0){
        bTokens2 = bTokens2 - rTokens2;
        cRounds -= rTokens2;
        rTokens2 = 0;
      }

      rCards2 = rCards + ((cards[i].c == 'R')? 1 : 0);
      bCards2 = bCards + ((cards[i].c == 'B')? 1 : 0);

      rounds = min(rounds, cRounds + compute(cards, bTokens2, rTokens2, bCards2, rCards2, bought, values));

      bought[i] = false;

    }
  }
  if(rounds == INT_MAX)
    return (values[t] = 0);
  else
    return (values[t] = rounds + 1);
}

int main(){
  int n;
  cin >> n;

  vector<Card> cards;
  char c;
  int r, b;
  for(int i = 0; i < n; i++){
    cin >> c >> r >> b;
    Card card;
    card.c = c;
    card.r = r;
    card.b = b;

    cards.push_back(card);
  }

  bool *bought = new bool[n];
  for(int i = 0; i < n; i++)
    bought[i] = false;

  int *values = new int[N];
  for(int i = 0; i < N; i++)
    values[i] = -1;

  cout << compute(cards, 0, 0, 0, 0, bought, values) << endl;

  return 0;
}
