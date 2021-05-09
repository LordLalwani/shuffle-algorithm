# Deck Sorting Algorithm

## What does this algorithm do?

You are given a deck containing N cards. While holding the deck:
1. Take the top card off the deck and set it on the table.
2. Take the next card off the top and put it on the bottom of the deck in your hand.
3. Continue steps 1 and 2 until all cards are on the table. This is a round.
4. Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.

This algorithm will determine how many rounds are required to get the deck of cards back into the original order.

---

## Considerations & Decisions

1. Decision to use linked lists instead of arrays due to its simplicity and also the dynamic data structure with pointers can easily mimic a list of cards. 


## Limitations / future upgrade notes

1. Testing: Due to a lack of time I haven't been able to get the testing effort of this codebase to a satisfactory level, this will be included in the future. 

---

## Dependencies
1. Gcc (c/cpp compiler)
2. Make (build/packaging tool)


## Compile, Build & Create A Executible

```bash
make build
```

## Test The Algorithm

```bash
./main.exe <Number_Of_Cards>
```