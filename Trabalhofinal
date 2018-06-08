#include <stdio.h>
#include <stdlib.h>
int main () {
	char ch, str[200], v[27][7],straux[200];
	int i=3,k=0,j=0,p=0;
	int num=0;
	FILE *claramentenaoeumponteiro;
	claramentenaoeumponteiro = fopen ("feep.ascii.pgm","r");
	if (claramentenaoeumponteiro==NULL){
		printf("Deu não man...\n");
		exit(1);
	}
	while(i--){
		fgets (str, 200, claramentenaoeumponteiro);
		if (str[k]=='0'||str[k]=='1'||str[k]=='2'||str[k]=='3'||str[k]=='4'||str[k]=='5'||str[k]=='6'||str[k]=='7'||str[k]=='8'||str[k]=='9'){
			j=k;
			while(str[j]!=' '){
				j++;
			}
			p=0;
			while(k<=j){
				straux[p]=str[k];
				p++;
				k++;
			}
			num=atoi(straux);
			k=0;
		}
	}
//		if (ch!='0'||ch!='1'||ch!='2'||ch!='3'||ch!='4'||ch!='5'||ch!='6'||ch!='7'||ch!='8'||ch!='9'||ch!=' '){
//			fgets (str, 20000, claramentenaoeumponteiro); //pula a linha
//		}
//		else/*tenho que comparar achar e voltar*/{
//			printf("%c caractere pego", ch);
//			printf("%s resto da string", str);	
//		}
//	}
	
//	fgets (str, 20000, claramentenaoeumponteiro); //pula a linha
//	printf ("%s", str); // imprime string com a linha desejada
//	while (ch!=EOF){
//		ch=getc(claramentenaoeumponteiro);
//		if(ch!=EOF){
//			printf("%c", ch);
//		}
//	}
	fclose(claramentenaoeumponteiro);
	return 0;
}
