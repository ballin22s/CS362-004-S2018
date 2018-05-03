#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//random character generation
char inputChar() {

    int n = (rand() % (126 - 32 + 1)) + 32;
    char ch = (char) n;
    
    return ch;
}

char *inputString() {

	char *str = (char *) malloc(sizeof(char) * 6);
		
    int i;
		
    for(i = 0; i < 5; i++) {
       int n = (rand() % (116 - 101 + 1)) + 101;
       char c = (char) n; 
       str[i] = c;
    }
		
    str[5] = '\0';
		
    return str;
}

void testme() {
	
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
	
	time_t endwait;
	time_t start = time(NULL);
	time_t seconds = 300;
	
	endwait = start + seconds;
	
  printf("start time is : %s", ctime(&start));
	
  while (start < endwait) {
					
	    tcCount++;
	    c = inputChar();
	    s = inputString();
			
			start = time(NULL);
		
	    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

	    if (c == '[' && state == 0) state = 1;
	    if (c == '(' && state == 1) state = 2;
	    if (c == '{' && state == 2) state = 3;
	    if (c == ' '&& state == 3) state = 4;
	    if (c == 'a' && state == 4) state = 5;
	    if (c == 'x' && state == 5) state = 6;
	    if (c == '}' && state == 6) state = 7;
	    if (c == ')' && state == 7) state = 8;
	    if (c == ']' && state == 8) state = 9;
	    
			if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9) {
	      printf("error ");
	      exit(200);
	    }
			
		
  }
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    testme();
    return 0;
}