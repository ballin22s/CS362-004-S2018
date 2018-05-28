#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//Custom Assert Function
void assertTrue(int a, int b, char* testName)
{
	if(a == b)
	{
		printf("%s Test Successful\n", testName);
	}
	
	else
	{
		printf("%s Test Failed\n", testName);
	}
}

//Random Kingdom Card
int randomCard()
{
	int card = (rand() % 10);
	
	return card;
}

int main(int argc, char *argv[])
{
	int numPlayers = 2;
	int k[10] = {smithy, adventurer, council_room, feast, gardens, mine, remodel, village, salvager, great_hall};
	int seed = 10;
	struct gameState state;
	int choice1 = 0; //Required for this card
	int choice2 = 0;
	int choice3 = 0;
	int handpos = 0;
	int bonus = 0;
	int r = randomCard(); //get a random number between 0 and 9
   
	//Print which test is being run
	printf("Card Test - Salvager - Without Trashing\n");
	
	int initSuccess = initializeGame(numPlayers, k, seed, &state);
	if(initSuccess != 0)
	{
	   printf("Game failed to initialize\n");
	}
    
	//State of Game Before Salvager is Played
	int fullDeckSizeBefore = state.deckCount[whoseTurn(&state)] + state.handCount[whoseTurn(&state)] + state.discardCount[whoseTurn(&state)];;
	int numBuys = state.numBuys;
	int moneyToSpend = state.coins;
	
	//Play Salvager
	cardEffect(salvager, choice1, choice2, choice3, &state, handpos, &bonus);
   
	//State of Game After Salvager is Played
	int fullDeckSizeAfter = state.deckCount[whoseTurn(&state)] + state.handCount[whoseTurn(&state)] + state.discardCount[whoseTurn(&state)];
	
	//Test Correct Deck Size - Should Remain Unchanged
	assertTrue(fullDeckSizeBefore, fullDeckSizeAfter, "Correct Full Deck Size -");
	
	//Test Correct Number of Buys Remaining
	assertTrue(numBuys + 1, state.numBuys, "Correct Number of Buys Remaining -");
	
	//Test Correct Amount Money to Spend - Should Remain Unchanged
	assertTrue(moneyToSpend, state.coins, "Correct Amount Money to Spend -");
	
	//Change Choice
	//Get a Random Kingdom Card
	choice1 = k[r];
	
	//Print which test is being run
	printf("Card Test - Salvager - Trashing %d\n", choice1);
	
	//State of Game Before Salvager is Played
	fullDeckSizeBefore = state.deckCount[whoseTurn(&state)] + state.handCount[whoseTurn(&state)] + state.discardCount[whoseTurn(&state)];
	numBuys = state.numBuys;
	moneyToSpend = state.coins;
	int valueChoice = getCost(handCard(choice1, &state));
	
	//Play Salvager
	cardEffect(salvager, choice1, choice2, choice3, &state, handpos, &bonus);
   
	//State of Game After Salvager is Played
	//Test Correct Full Deck Size - One Card Should be Trashed
	assertTrue(fullDeckSizeBefore - 1, fullDeckSizeAfter, "Correct Full Deck Size -");
	
	//Test Correct Number of Buys Remaining
	assertTrue(numBuys + 1, state.numBuys, "Correct Number of Buys Remaining -");
	
	//Test Correct Amount Money to Spend - Additional $ Should be Available 
	assertTrue(moneyToSpend + valueChoice, state.coins, "Correct Amount Money to Spend -");
	 
	return 0;   
}


