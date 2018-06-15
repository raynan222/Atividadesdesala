#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int** md(int alt,int lar);
	int main () {
		char lixo[200],ch;
		int alt=-1,lar=-1,esc=-1,i,j,si,sj,li,aux,laux,**matriz,count=0,laplaci[9]={-1,-1,-1,-1,8,-1,-1,-1,-1};
		printf("Digite o nome do arquivo sem extensão:\n");
		gets (lixo);
		strcat (lixo,".ascii.pgm");
		FILE *fp;
		fp = fopen (lixo,"r");

		if (fp==NULL){
			printf("Não foi possivel abrir o arquivo.\nPressione ENTER para sair!");
			gets();
			exit(1);
		}

		while(lar<0){
			ch=fgetc(fp);
			if (ch=='P'){
				ch=fgetc(fp);
				ch=fgetc(fp);
				ch=fgetc(fp);
			}
			if (ch=='#'){
				fgets(lixo, 1000, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&lar);
				printf("\n%d lar\n",lar);
			}
		}
		while(alt<0){
			ch=fgetc(fp);
			if (ch=='#'){
				fgets(lixo, 1000, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&alt);
				printf("\n%d alt\n",alt);
			}
		}
		while(esc<0){
			ch=fgetc(fp);
			if (ch=='#'){
				fgets(lixo, 1000, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&esc);
				printf("\n%d esc\n",esc);
			}
		}
		matriz=(int**)malloc((alt+2)*sizeof(int*));
		for (i=0;i<(alt+2);i++){
			matriz[i]=(int*)malloc((lar+2)*sizeof(int));
		}
		for (i=0; i<alt+2; i++) {
			for (j=0; j<lar+2; j++) {
				matriz[i][j]=0;
			}
		}
		printf("\nA SEGUIR MATRIZ ZERA AJUSTADA PARA 3x3\n");
		for (i=0; i<alt+2; i++) {
			for (j=0; j<lar+2; j++) {
				printf("%d\t", matriz[i][j]);
			}
			printf("\n");
		}
		j=1, i=1,count=0;
		while(count<alt*lar){
			ch=fgetc(fp);
			if (ch=='#'){
				fgets(lixo, 1000, fp);
			}
			if (ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
				fseek(fp, -1, SEEK_CUR);
				fscanf(fp, "%d ",&aux);
				matriz[i][j]=aux;
				j++;
				if(j>lar){
					i++;
					j=1;
				}
				count++;
			}
		}
		printf("\nA SEGUIR MATRIZ CRIADA\n");
		for (i=0; i<alt+2; i++) {
			for (j=0; j<lar+2; j++) {
				printf("%d\t", matriz[i][j]);
			}
			printf("\n");
		}
		j=0, i=0,count=0,si=0,sj=0;
		while(count<alt+2){
			if(li>2||li>5){
				i++;
				j=sj;
			}
			if(li>8){
				li=0;
				sj++;
				j++;
				i=si;
			}
			if(j>lar){
				si++;
				j=0;
				sj=0;
				count++;
			}
			matriz[i][j]+=laplaci[li];
			li++;
			j++;
		}
		printf("\nA SEGUIR MATRIZ laplaciada\n");
		for (i=0; i<alt+2; i++) {
			for (j=0; j<lar+2; j++) {
				printf("%d\t", matriz[i][j]);
			}
			printf("\n");
		}
			free(matriz);
			fclose(fp);

		return 0;
	}
