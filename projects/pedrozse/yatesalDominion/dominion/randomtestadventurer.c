#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main() {
  printf("***** RANDOM TEST *****\n");
  printf("File: randomcardtestadventurer.c\n");
  printf("Function: adventurerCard()\n");
  printf("***********************\n");
	
    struct gameState G;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};  
    int deckSize;
    int handSize;
    int i;
    int j;
    int q;
    int randomCard;
    int randK;
    int m;
    int coinCount;
    int x;
    int discardCopper;
    int discardSilver;
    int discardGold;
    int coinCountBefore;
    int testPassed = 0;
    int drawTestFailed = 0;
    int discardTestFailed = 0;
    int passed = 1;
    
    srand(time(NULL));
   //randomize hand size
    for(i = 0; i < 1000000; i++){
        initializeGame(numPlayers, k, seed, &G);
        coinCountBefore = 0;
        deckSize = rand() % (MAX_DECK + 1);
   //set handsize
        handSize = rand() % (deckSize + 1);
      
        
        G.deckCount[0] = deckSize - handSize;
        G.handCount[0] = handSize;
                
        for (j = 0; j < numPlayers; j++){
            for(q = 0;q < G.deckCount[j]; q++){
                randomCard = rand() % (50 + 1);
                randK = rand() % (10);
                if(randomCard == 1){
                    G.deck[j][q] = copper;
                } else if(randomCard == 2){
                    G.deck[j][q] = silver;
                }else if(randomCard == 3){
                    G.deck[j][q] = gold;
                }else {
                    G.deck[j][q] = k[randK];
                }
            }
        } 
        
        for(m = 0; m < G.handCount[curPlayer]; m++){
            if(G.hand[curPlayer][m] == copper || G.hand[curPlayer][m] == silver || G.hand[curPlayer][m] == gold){
                coinCountBefore++;
            }
        }
        
        coinCount = 0;
        
        for(m = 0; m < G.handCount[curPlayer]; m++){
            if(G.hand[curPlayer][m] == copper || G.hand[curPlayer][m] == silver || G.hand[curPlayer][m] == gold){
                coinCount++;
            }
        }

        discardCopper = 0;
        discardSilver = 0;
        discardGold = 0;
        for(x = 0; x < G.discardCount[curPlayer]; x++){
            if(G.discard[curPlayer][x] == copper) {
                discardCopper++;
            } else if(G.discard[curPlayer][x] == silver) {
                discardSilver++;
            } else if(G.discard[curPlayer][x] == gold) {
                discardGold++;
            }
        }

        if(coinCount > (coinCountBefore + 2)){
            printf("Too many cards drawn: Test Failed\n\n");
            drawTestFailed++;
            passed = 0;
        }
        
        if( coinCount < coinCountBefore){
            printf("Fewer cards exist in hand than were first present: Test Failed\n\n");
            drawTestFailed++;
            passed = 0;
        }
        if(discardCopper != 0){
            printf("Copper was discarded: Test Failed\n\n");
            discardTestFailed++;
            passed = 0;
        }

        if(discardSilver != 0){
            printf("Silver was discarded: Test Failed\n\n");
            discardTestFailed++;
            passed = 0;
        }

        if(discardGold != 0){
            printf("Gold was discarded: Test Failed\n\n");
            discardTestFailed++;
            passed = 0;
        }

        if(passed == 1){
            testPassed++;
        }
   }
   
   printf("\n");
   printf("\n***** RESULTS *****\n");
   printf("PASSED TESTS: %d\n",testPassed);
   printf("FAILED TESTS: %d\n",discardTestFailed);
	 
   if (discardTestFailed == 0) {
       printf ("***** PASSED RANDOM TEST *****\n\n");
   }
   
   printf ("****** COVERAGE ******\n");
   return 0;
}