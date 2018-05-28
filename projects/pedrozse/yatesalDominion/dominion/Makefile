CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o	
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	
allunittests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 dominion.o rngs.o
	echo "unittest1.c:" >> unittestresults.out
	./unittest1 >> unittestresults.out 2>&1
	gcov unittest1.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out	
	./unittest2 >> unittestresults.out 2>&1
	gcov unittest2.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	./unittest3 >> unittestresults.out 2>&1
	gcov unittest3.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out	
	./unittest4 >> unittestresults.out 2>&1
	gcov unittest4.c >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out	
	./cardtest1 >> unittestresults.out 2>&1
	gcov cardtest1.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out	
	./cardtest2 >> unittestresults.out 2>&1
	gcov cardtest2.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out	
	./cardtest3 >> unittestresults.out 2>&1
	gcov cardtest3.c >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	./cardtest4 >> unittestresults.out 2>&1
	gcov cardtest4.c >> unittestresults.out

	echo "dominion.c:" >> unittestresults.out	
	gcov dominion.c >> unittestresults.out 2>&1
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	
allrandomtests: randomtestadventurer randomtestcard1 randomtestcard2 dominion.o rngs.o
	echo "randomtestadventurer.c:" >> randomtestadventurer.out	
	./randomtestadventurer >> randomtestadventurer.out 2>&1
	gcov randomtestadventurer.c >> randomtestadventurer.out

	echo "randomtestcard1.c:" >> randomtestcard1.out	
	./randomtestcard1 >> randomtestcard1.out 2>&1
	gcov randomtestcard1.c >> randomtestcard1.out
	
	echo "randomtestcard2.c:" >> randomtestcard2.out
	./randomtestcard2 >> randomtestcard2.out 2>&1
	gcov randomtestcard2.c >> randomtestcard2.out

	echo "dominion.c:" >> randomtestresults.out	
	gcov dominion.c >> randomtestresults.out 2>&1
	cat dominion.c.gcov >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2 *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
