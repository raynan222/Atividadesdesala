#include <stdio.h>
#include <stdlib.h>
int main () {
	FILE *fp;
	char ch;
	fp=fopen ("test.txt","r");
	if (fp==NULL) {
		printf ("O arquivo nao pode ser aberto\n");
		exit (1);
	}
	while(ch!=EOF){
		ch=getc(fp);
		if(ch!=EOF){
			printf("%c",ch);
		}
	}
	fclose (fp);
	return 0;
	
}
