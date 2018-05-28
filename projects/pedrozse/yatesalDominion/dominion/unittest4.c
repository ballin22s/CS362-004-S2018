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
	int i;
   
	//Print which test is being run
	printf("Unit Test - Shuffle\n");
	
	int initSuccess = initializeGame(numPlayers, k, seed, &state);
	if(initSuccess != 0)
	{
	   printf("Game failed to initialize\n");
	}
	
	//Set 2 Decks Equally 
	state.deckCount[0] = 10;
	state.deckCount[1] = 10;
	
	for(i = 0; i < 10; i++)
	{
		state.deck[0][i] = k[i];
		state.deck[1][i] = k[i];
	}
	
	shuffle(0, &state);
	
	//Test Change in Card Order
	int different = 0;
	
	for(i = 0; i < 10; i++)
	{
		if(state.deck[0][i] != state.deck[1][i])
		{
			different++;
		}	
	}
	
	if(different > 0)
	{
		different = 1;
	}
	
	assertTrue(1, different, "Card Order Changed -");
	
	//Test No Cards in Deck to Shuffle
	state.deckCount[0] = 0;
	assertTrue(-1, shuffle(0, &state), "No Cards to Shuffle -");
	
    return 0;
}










