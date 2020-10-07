#include <stdio.h>
#include <stdlib.h>

char *scang() {

	int pos = 0;
	char c;
	char *p = malloc(1 * sizeof(char));
		
	fflush(stdin);
	do {
		c = getche();

		if(c != 13) {
			p[pos] = c;
			pos++;
			p = realloc(p, (pos+1) * sizeof(char));
		}
	}while(c != 13);

	printf("a");
	
	p[pos] = '\0';
	
	return p;
}