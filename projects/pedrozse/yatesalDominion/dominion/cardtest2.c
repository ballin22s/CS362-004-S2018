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

int main(int argc, char *argv[])
{
	int numPlayers = 2;
	int k[10] = {smithy, adventurer, council_room, feast, gardens, mine, remodel, village, salvager, great_hall};
	int seed = 10;
	struct gameState state;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handpos = 0;
	int bonus = 0;
   
	//Print which test is being run
	printf("Card Test - Adventurer\n");
	
	int initSuccess = initializeGame(numPlayers, k, seed, &state);
	if(initSuccess != 0)
	{
	   printf("Game failed to initialize\n");
	}
    
	//State of Game Before Adventurer is Played
	int inHand = numHandCards(&state);
	int deckSize = state.deckCount[whoseTurn(&state)];
	int moneyToSpend = state.coins;
	
	//Play Adventurer
	cardEffect(adventurer, choice1, choice2, choice3, &state, handpos, &bonus);
   
	//State of Game After Adventurer is Played
	updateCoins(whoseTurn(&state), &state, bonus);
	int newDeckSize = state.deckCount[whoseTurn(&state)];
	
	//Test Correct Hand Size - Should Have 2 Additional $ Cards
	assertTrue(inHand + 1, numHandCards(&state), "Correct Hand Size -");
   
	//May Not be a Valid Test, May Have to Shuffle Discard In, Increasing the Size
	//Test Correct Deck Size
	assertTrue(1, (deckSize - 2 >= newDeckSize), "Correct Deck Size -"); 
	
	//Test Correct Amount Money to Spend - Additional $ Should be Available 
	assertTrue(1, (moneyToSpend + 2 <= state.coins), "Correct Amount Money to Spend -");
   
   return 0;   
}


