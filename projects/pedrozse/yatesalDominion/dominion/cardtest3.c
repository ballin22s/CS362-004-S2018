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
	printf("Card Test - Village\n");
	
	int initSuccess = initializeGame(numPlayers, k, seed, &state);
	if(initSuccess != 0)
	{
	   printf("Game failed to initialize\n");
	}
    
	//State of Game Before Village is Played
	int inHand = numHandCards(&state);
	int deckSize = state.deckCount[whoseTurn(&state)];
	int numActions = state.numActions;
	
	//Play Village
	cardEffect(village, choice1, choice2, choice3, &state, handpos, &bonus);
   
	//State of Game After Village is Played
	//Test Correct Hand Size - Should Stay the Same (added 1, discarded Village)
	assertTrue(inHand, numHandCards(&state), "Correct Hand Size -");
   
	//Test Correct Deck Size - Should Decrease by 1
	assertTrue(deckSize - 1, state.deckCount[whoseTurn(&state)], "Correct Deck Size -");
	
	//Test Correct Number of Actions - Should Increase by 2 (only playCard decreases actions to remove the one used for the Village)
	assertTrue(numActions + 2, state.numActions, "Correct Number of Actions Remaining -");
   
   return 0;   
}


