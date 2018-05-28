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

//Random Supply Card
int randomCard()
{
	int card = (rand() % 26);
	
	return card;
}

int main(int argc, char *argv[])
{
	int numPlayers = 2;
	int k[10] = {smithy, adventurer, council_room, feast, gardens, mine, remodel, village, salvager, great_hall};
	int seed = 10;
	struct gameState state;
	int random1 = randomCard();
	int random2 = 0;
	int random3 = 0;
	
	do{
		random2 = randomCard();
	}while(random1 == random2);
		
	do{
		random3 = randomCard();
	}while(random1 == random3 || random2 == random3);
   
	//Print which test is being run
	printf("Unit Test - Is Game Over\n");
	
	int initSuccess = initializeGame(numPlayers, k, seed, &state);
	if(initSuccess != 0)
	{
	   printf("Game failed to initialize\n");
	}	
	
	//Province Cards Tests

	//Still Have Province Cards, No Supply Piles Empty
	assertTrue(0, isGameOver(&state), "Game Continues, Have Province Cards -");	
	
	//Out of Province Cards, No Supply Piles Empty
	//Empty Povince Pile 
	state.supplyCount[province] = 0;
	
	assertTrue(1, isGameOver(&state), "Game is Over, No Province Cards -");

	//Supply Piles Tests
	//Still Have Province Cards, No Supply Piles Empty
	state.supplyCount[province] = 5;
	
	assertTrue(0, isGameOver(&state), "Game Continues, Have Supply Cards -");	
	
	//Still Have Province Cards, 3 Supply Piles Empty
	state.supplyCount[random1] = 0;
	state.supplyCount[random2] = 0;
	state.supplyCount[random3] = 0;
	
	assertTrue(1, isGameOver(&state), "Game is Over, 3 Supplies Out -");
	
    return 0;
}