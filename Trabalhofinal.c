#include <stdio.h>
#include <stdlib.h>
int main () {
	char ch, str[200],straux[200];
	int **matrix; 
	int i=3,k=0,j=0,p=0,mtflag=2,lar,alt,bmax,pixcount,b;
	int num=0;
	FILE *claramentenaoeumponteiro;
	claramentenaoeumponteiro = fopen ("feep.ascii.pgm","r");
	if (claramentenaoeumponteiro==NULL){
		printf("Deu não man...\n");
		exit(1);
	}
	while(i--){ /*Cria o 'matrix' alocado dinamicamente note que o range e de 0 a (largura-1), guarda o valor maximo de cor com 'bmax'*/
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
			if(mtflag==2){
				matrix = malloc (num * sizeof (int *));
				lar=num;
				mtflag-=1;
				pixcount=num;
			}
			if(mtflag==1){
					for (int alt = 0; alt < lar; ++alt){
						matrix[lar] = malloc (num * sizeof (int));
					}
				mtflag-=1;
				pixcount*=num;
			}
			if(mtflag==0){
				bmax=num;
				mtflag-=1;
			}
		}
	}
	fgets (str, 200, claramentenaoeumponteiro);
	while(b>=alt){
		if(str[k]=='0'||str[k]=='1'||str[k]=='2'||str[k]=='3'||str[k]=='4'||str[k]=='5'||str[k]=='6'||str[k]=='7'||str[k]=='8'||str[k]=='9'){
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
			printf ("%d",num);
			if(i>=lar){
				b++;
				i=0;
			}
			matrix[i][b]=num;
			i++;
			k=0;
			b++;
		}
		else{
			fgets (str, 200, claramentenaoeumponteiro);
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
	free (matrix);
	return 0;
}
