// Agora vai......................
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main () {
		char lixo[200],ch,arquivo;
		int i,alt=-1,lar=-1,esc=-1;
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

		while(alt<0){
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
				fscanf(fp, "%d ",&alt);
				printf("\n%d alt\n",alt);
			}
		}
		while(lar<0){
			ch=fgetc(fp);
			if (ch=='#'){
				fgets(lixo, 1000, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&lar);
				printf("\n%d lar\n",lar);
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
		fclose(fp);
		return 0;
	}
