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
   
	//Print which test is being run
	printf("Unit Test - Gain Card\n");
	
	int initSuccess = initializeGame(numPlayers, k, seed, &state);
	if(initSuccess != 0)
	{
	   printf("Game failed to initialize\n");
	}
	
	//Set Card Counts
	state.discardCount[whoseTurn(&state)] = 0;
	state.deckCount[whoseTurn(&state)] = 0;
	state.handCount[whoseTurn(&state)] = 0;
	
	
	//Test Discard Gains Card
	gainCard(copper, &state, 0, whoseTurn(&state));
	assertTrue(1, state.discardCount[whoseTurn(&state)], "Discard Pile Gains Card -");
	
	//Test Deck Gains Card
	gainCard(copper, &state, 1, whoseTurn(&state));
	assertTrue(1, state.deckCount[whoseTurn(&state)], "Deck Gains Card -");		
	
	//Test Hand Gains Card
	gainCard(copper, &state, 2, whoseTurn(&state));
	assertTrue(1, state.handCount[whoseTurn(&state)], "Hand Pile Gains Card -");	
	
    return 0;
}










