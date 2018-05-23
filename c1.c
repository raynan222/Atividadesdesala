#include <stdio.h>
#include <stdlib.h>
int main () {
	FILE *fp;
	fp=fopen ("test.txt","w");
	if (fp==NULL) {
		printf ("O arquivo nao pode ser aberto\n");
		exit (1);
	}
	char a;
	scanf("%c", &a);
	putc(a,fp);
	fclose (fp);
	return 0;
	
}
