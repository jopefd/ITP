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

  if (cards[0].value == Ace &&
      cards[1].value == King &&
      cards[2].value == Queen &&
      cards[3].value == Jack &&
      cards[4].value == Ten &&
      cards[0].suit == cards[1].suit &&
      cards[1].suit == cards[2].suit &&
      cards[3].suit == cards[4].suit) {
    return RoyalFlush;
  } else if (cards[0].value == cards[1].value &&
             cards[1].value == cards[2].value &&
             cards[2].value != cards[3].value &&
             cards[2].value != cards[4].value) {
    return StraightFlush;
  } else if (cards[0].value == cards[1].value &&
             cards[1].value == cards[2].value &&
             cards[2].value != cards[3].value &&
             cards[2].value != cards[4].value) {
    return FourOfAKind;
  } else if (cards[0].value == cards[1].value &&
             cards[1].value == cards[2].value &&
             cards[2].value != cards[3].value &&
             cards[2].value != cards[4].value &&
             cards[3].value == cards[4].value) {
    return FullHouse; 
  } else if (cards[0].suit == cards[1].suit &&
             cards[1].suit == cards[2].suit &&    
             cards[3].suit == cards[4].suit &&    
             cards[0].value != cards[1].value + 1 &&    
             cards[1].value != cards[2].value + 1 &&    
             cards[2].value != cards[3].value + 1 &&    
             cards[3].value != cards[4].value + 1) {
    return Flush;           
  } else if (cards[0].suit != cards[1].suit &&
             cards[1].suit != cards[2].suit &&    
             cards[3].suit != cards[4].suit &&    
             cards[0].value == cards[1].value + 1 &&    
             cards[1].value == cards[2].value + 1 &&    
             cards[2].value == cards[3].value + 1 &&    
             cards[3].value == cards[4].value + 1) {
    return Straight;           
  } else if ((cards[0].value == cards[1].value &&    
             cards[1].value == cards[2].value) ||    
             (cards[1].value == cards[2].value &&
             cards[2].value == cards[3].value) ||
             (cards[2].value == cards[3].value &&
             cards[3].value == cards[4].value)) {
    return ThreeOfAKind;
  } else if (cards[0].value == cards[1].value ||    
             cards[1].value == cards[2].value ||
             cards[2].value == cards[3].value ||
             cards[3].value == cards[4].value) {
    return TwoPair;
  } else if ((cards[0].value == cards[1].value &&    
             cards[2].value == cards[3].value &&
             cards[0].value != cards[2].value) ||
             (cards[1].value == cards[2].value &&
             cards[3].value == cards[4].value &&
             cards[1].value != cards[3].value)) {
    return Pair;
  }
  
  return HighCard;
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
