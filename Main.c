#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main () {
		char lixo[200],ch,mascara='0';
		unsigned char **matriz,aux;
		int alt=-1,lar=-1,esc=-1,count=-1,j,i,k,ak,mask;
		system("clear");
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
		
		while (count<0){
			printf("\nQual tamanho de mascara sera usada?\n(a)Mascara de 3x3.\n(b)Mascara de 5x5.\n(c)Mascara de 7x7.\n(d)Inserir valor manualmente.\n");
			scanf("%c",&mascara);
			if(mascara=='a'||mascara=='A'){
				mask=3;
				count++;
			}
			if(mascara=='b'||mascara=='B'){
				mask=5;
				count++;
			}
			if(mascara=='c'||mascara=='C'){
				mask=7;
				count++;
			}
			if(mascara=='d'||mascara=='D'){
				printf("Atenção o valor da mascara deve ser impar para ser utilizavel!\n\nExemplo de entrada: 11\n\nResultado: Mascara 11x11\n\n");
				scanf("%d",&mask);
				if(mask%2==0){
					printf("VALOR INSERIDO INVALIDO\n");
				}

				if(mask%2!=0){
					count++;
				}
			}
			else{
				system("clear");
				printf("Opção invalida\n");
			}
		}
		system("clear");
		 ////////////////////
		//while da largura//
	  ////////////////////

		while(lar<0){
			ch=fgetc(fp);
			if (ch=='P'){
				ch=fgetc(fp);
				ch=fgetc(fp);
				ch=fgetc(fp);
			}
			if (ch=='#'){
				fgets(lixo, 200, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&lar);
			}
		}

		 ///////////////////
		//while da altura//
	  ///////////////////

		while(alt<0){
			ch=fgetc(fp);
			if (ch=='#'){
				fgets(lixo, 200, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&alt);
			}
		}

		 ///////////////////
		//while da escala//
	  ///////////////////

		while(esc<0){
			ch=fgetc(fp);
			if (ch=='#'){
				fgets(lixo, 200, fp);
			}
			else{
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%d ",&esc);
				printf("Dados do Arquivo\nLargura da imagem em pixeis: %dpx\nAltura da imagem em pixeis: %dpx\nValor do branco(MAXIMO): %d\n",lar,alt,esc);
			}
		}

		 /////////////////////////////////////////////////
		//Criação da matriz de tamanho igual ao arquivo//
	  /////////////////////////////////////////////////

		matriz=(unsigned char**)malloc((alt+(mask-1))*sizeof(unsigned char*));
		for (i=0;i<(alt+(mask-1));i++){
			matriz[i]=(unsigned char*)malloc((lar+(mask-1))*sizeof(unsigned char));
		}
	
		 ///////////////////////////
		//Preenche a matriz com 0//
	  ///////////////////////////

		for (i=0; i<alt+(mask-1); i++) {
			for (j=0; j<lar+(mask-1); j++) {
				matriz[i][j]=0;
			}
		}
		 ////////////////////////////////////////
		//preenche a matriz atraves do arquivo//
	  ////////////////////////////////////////

		for (i = (mask/2); i< alt+(mask/2); i++) {
			for (j = (mask/2); j< lar+(mask/2); j++) {
				unsigned char x;
				ch = fgetc(fp);
				if (ch =='#'){
					fgets(lixo, 200,fp);
					j--;
					continue;
				}
				fseek(fp, -2, SEEK_CUR);
				fscanf(fp, "%hhu ",&x);
				matriz[i][j] = x;
			}
		}

		 ///////////////////
		//Printa a matriz//
	  ///////////////////

		printf("\nMATRIZ PREENCHIDA A PARTIR DO ARQUIVO\n");
		for (i=0; i<alt+(mask-1); i++) {
			for (j=0; j<lar+(mask-1); j++) {
				printf("%hhu\t", matriz[i][j]);
			}
			printf("\n");
		}
			free(matriz);
			fclose(fp);

		return 0;
	}
