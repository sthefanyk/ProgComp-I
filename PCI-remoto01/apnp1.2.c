#include <stdio.h>

int main(){

	int i;
	char p, s, t;

	printf("Digite tres caracteres: ");
	scanf("%c%c%c", &p, &s, &t);


	printf("- Combinacao 1: %c%c%c\n", p, s, t);
	printf("- Combinacao 2: %c%c%c\n", p, t, s);
	printf("- Combinacao 3: %c%c%c\n", s, p, t);
	printf("- Combinacao 4: %c%c%c\n", s, t, p);
	printf("- Combinacao 5: %c%c%c\n", t, s, p);
	printf("- Combinacao 6: %c%c%c\n", t, p, s);

	return 0;
}
