#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main () {
		char lixo[200],ch,opcao;
		unsigned char **matriz,**matrizvariavel,aux,soma;
		int alt=-1,lar=-1,esc=-1,count=-1,j,i,k,l,mask;
		int laplace[3][3] = {{0, -1, 0},{-1, 4, -1},{0, -1, 0}};
		int prewit[3][3] = {{-1, 0, 1},{-1, 0, 1},{-1, 0, 1}};
		int sobel[3][3] = {{-1, 0, 1},{-2, 0, 2},{-1, 0, 1}};
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
			system("clear");
			printf("Arquivo selecionado: %s\nSelecione uma das opções abaixo.\n\n(a)Aplicar filtro de media ponderada.\n(b)Aplicar filtro Gaussiano.\n(c)Aplicar filtro Laplaciano.\n(d)Aplicar filtro de prewit.\n(e)Sair.\n",lixo);
			scanf("%c",&opcao);
			if(opcao=='a'||opcao=='A'||opcao=='1'){
			}
			if(opcao=='b'||opcao=='B'||opcao=='2'){
				count++;
			}
			if(opcao=='c'||opcao=='D'||opcao=='3'){
			}
			if(opcao=='d'||opcao=='D'||opcao=='4'){
			}
			if(opcao=='e'||opcao=='E'||opcao=='5'){		
					exit(1);
			}
		}
		while (count<1){
			printf("\nQual tamanho de mascara sera usada?\n(a)Mascara de 3x3.\n(b)Mascara de 5x5.\n(c)Mascara de 7x7.\n(d)Inserir valor manualmente.\n");
			scanf("%c",&opcao);
			if(opcao=='a'||opcao=='A'||opcao=='3'){
				mask=3;
				count++;
			}
			if(opcao=='b'||opcao=='B'||opcao=='5'){
				mask=5;
				count++;
			}
			if(opcao=='c'||opcao=='C'||opcao=='7'){
				mask=7;
				count++;
			}
			if(opcao=='d'||opcao=='D'){
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

		matrizvariavel=(unsigned char**)malloc(mask*sizeof(unsigned char*));
		for (i=0;i<mask;i++){
			matrizvariavel[i]=(unsigned char*)malloc(mask*sizeof(unsigned char));
		}
	
		 /////////////////////////////////////
		//Preenche a matriz com borda com 0//
	  /////////////////////////////////////

		for (i=0; i<alt+(mask-1); i++) {
			for (j=0; j<lar+(mask-1); j++) {
				matriz[i][j]=0;
			}
		}

		 ////////////////////////////////////////
		//Preenche a matriz de filtro variavel//
	  ////////////////////////////////////////

		for (i=0; i<mask; i++) {
			for (j=0; j<mask; j++) {
				matrizvariavel[i][j]=1;
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

		 //////////////////////
		//Printa as matrizes//
	  //////////////////////

		printf("\nMATRIZ PREENCHIDA A PARTIR DO ARQUIVO\n");
		for (i=0; i<alt+(mask-1); i++) {
			for (j=0; j<lar+(mask-1); j++) {
				printf("%hhu\t", matriz[i][j]);
			}
			printf("\n");
		}
		printf("\nMATRIZ MASCARA\n");
		for (i=0; i<mask; i++) {
			for (j=0; j<mask; j++) {
				printf("%hhu\t", matrizvariavel[i][j]);
			}
			printf("\n");
		}

		 ////////////////////
		//Filtro Gaussiano//
	  ////////////////////

		for (i=(mask/2); i<alt+(mask/2); i++) {
			for (j=(mask/2); j<lar+(mask/2); j++) {
				soma=0;				
				for (k=(i-(mask/2)); k<((mask/2)+i); k++) {
					for (l=(j-(mask/2)); l<((mask/2)+j); l++) {
						soma=soma+matriz[k][l]+matriz[i][j];
					}
				}
				matriz[i][j]=soma/(mask*mask);
			}
		}


			free(matriz);
			free(matrizvariavel);
			fclose(fp);

		return 0;
	}
