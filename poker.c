#include <stdio.h>

typedef enum {
  Diamonds,
  Heart,
  Spades,
  Clubs
} Suit;

typedef enum {
  Two = 2, Three, Four,
  Five, Six, Seven,
  Eight, Nine, Ten,
  Jack, Queen, King,
  Ace
} Value;

typedef struct {
  Suit suit;
  Value value;
} Card;

typedef enum {
  HighCard,
  Pair,
  TwoPair,
  ThreeOfAKind = 8,
  Straight,
  Flush,
  FullHouse,
  FourOfAKind,
  StraightFlush,
  RoyalFlush
} PokerHand;

PokerHand checkHand(Card cards[5]) {
  Card changer;
  for (unsigned int i = 0; i < 5; i++) {
    for (unsigned int j = i; j < 5; j++) {
      if (cards[i].value < cards[j].value) {
        changer = cards[i];
        cards[i] = cards[j];
        cards[j] = changer;
      }
    }
  }
  printf("%u", cards[0].value);
  return cards[0].value;
}

int main() {
  Card hands[][5] = {
    { // Royal Flush
      {Diamonds, Ace},
      {Diamonds, King},
      {Diamonds, Queen},
      {Diamonds, Jack},
      {Diamonds, Ten}
    }, { // Full house
      {Heart, Jack},
      {Spades, Jack},
      {Clubs, Jack},
      {Spades, Two},
      {Heart, Two}
    }, { // Three of a Kind
      {Diamonds, Ten},
      {Spades, Seven},
      {Diamonds, Four},
      {Spades, Four},
      {Heart, Four}
    }, { // Pair
      {Spades, Ace},
      {Heart, Jack},
      {Spades, Jack},
      {Heart, Seven},
      {Clubs, Four}
    }, { // High Card (No pair)
      {Clubs, Nine},
      {Heart, Seven},
      {Diamonds,Six},
      {Spades, Four},
      {Heart, Two}
    },
  };
  Card myCards[5];
  Card oponentCards[5];

  unsigned handIndex;
  scanf("%u", &handIndex);
  for (int i = 0; i < 5; i++) {
    myCards[i] = hands[handIndex][i];
    scanf("%u %u", &oponentCards[i].suit, &oponentCards[i].value);
  }
  PokerHand myHand = checkHand(myCards);
  PokerHand oponentHand = checkHand(oponentCards);
  printf("%u %u %u\n", myHand, oponentHand, RoyalFlush);
  if (myHand > oponentHand) {
    switch (myHand) {
      case RoyalFlush:
        printf("É... simplesmente não tinha como me bater!\n");
        break;
      case StraightFlush:
      case FourOfAKind:
      case FullHouse:
        printf("Já era! Você não tinha chance!\n");
        break;
      case Flush:
      case Straight:
      case ThreeOfAKind:
        printf("É boy! Quem sabe da próxima vez...\n");
        break;
      default:
        printf("Tive sorte!\n");
    }
  } else if (oponentHand > myHand) {
    printf("Não valeu! Cê tá roubando!!!\n");
  } else if (myCards[0].value > oponentCards[0].value) {
    printf("Ufa! Por pouco!");
  } else {
    printf("Nan!! Bicho melado da gota!\n");
  }
  return 0;
}
