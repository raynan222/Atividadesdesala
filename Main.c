#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
		int cmpfunc (const void * a, const void * b) {
   		return ( *(int*)a - *(int*)b );
		}

		int main () {
		char lixo[200],ch,opcao[2],nomearquivo[200],gaussianon[11]={'G','a','u','s','s','i','a','n','o',' '},p2[3]={'P','2'},tmask[2],sobeln[7]={'S','o','b','e','l',' '},laplacen[12]={'L','a','p','l','a','c','i','a','n','o',' '},prewittn[9]={'P','r','e','w','i','t','t',' '},Denoise[9]={'D','e','n','o','i','s','e',' '};
		unsigned char **matriz,aux;
		float **matrizvariavel,**matrizrec,**matrizexp,soma,mask=3.0;
		int alt=-1,lar=-1,count=0,esc=-1,j,i,k,l,m,n,a,b,c,zero=0,*vet,maskint;
		int laplace[3][3] = {{0, -1, 0},{-1, 4, -1},{0, -1, 0}};
		int prewitt[3][3] = {{-1, 0, 1},{-1, 0, 1},{-1, 0, 1}};
		int sobel[3][3] = {{-1, 0, 1},{-2, 0, 2},{-1, 0, 1}};
		FILE *fp;
		FILE *ps;

		count=0;
		system("clear");
		printf("Digite o nome do arquivo sem extensão:\n");
		gets (nomearquivo);
		strcat (nomearquivo,".ascii.pgm");
		fp = fopen (nomearquivo,"r");

		if (fp==NULL){
			system("clear");
			printf("Não foi possivel abrir o arquivo.\nPressione ENTER para sair!");
			gets();
			exit(1);
		}

		while (count==0){
			system("clear");
			printf("\nArquivo selecionado: %s\n\nSelecione uma das opções abaixo:\n\n(A)Aplicar filtro de Sobel.\n(B)Aplicar filtro Laplaciano.\n(C)Aplicar filtro de prewitt.\n(D)Aplicar filtro Gaussiano(3x3).\n(E)Aplicar filtro Gaussiano(5x5).\n(F)Aplicar filtro Gaussiano(7x7).\n(G)Aplicar filtro denoise(3x3).\n(H)Aplicar filtro denoise(5x5).\n(I)Aplicar filtro denoise(9x9).\n(X)Sair.\n\n",nomearquivo);
			gets(&opcao);
			if(opcao[zero]=='a'||opcao[zero]=='A'||opcao[zero]=='1'){
				count=10;
			}
			if(opcao[zero]=='b'||opcao[zero]=='B'||opcao[zero]=='2'){
				count=20;
			}
			if(opcao[zero]=='c'||opcao[zero]=='D'||opcao[zero]=='3'){
				count=30;
			}
			if(opcao[zero]=='d'||opcao[zero]=='D'||opcao[zero]=='4'){
				count=40;
				mask=3.0;
			}
			if(opcao[zero]=='e'||opcao[zero]=='E'||opcao[zero]=='5'){
				count=40;
				mask=5.0;
			}
			if(opcao[zero]=='f'||opcao[zero]=='F'||opcao[zero]=='6'){
				count=40;
				mask=7.0;
			}
			if(opcao[zero]=='g'||opcao[zero]=='G'||opcao[zero]=='7'){
				count=50;
				mask=3.0;
			}
			if(opcao[zero]=='h'||opcao[zero]=='H'||opcao[zero]=='8'){
				count=50;
				mask=5.0;
			}
			if(opcao[zero]=='i'||opcao[zero]=='I'||opcao[zero]=='9'){
				count=50;
				mask=7.0;
			}
			if(opcao[zero]=='x'||opcao[zero]=='X'||opcao[zero]=='0'){
				system("clear");
				exit(1);
			}
		}

		system("clear");
		if(count<60){
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
				}
			}

			 /////////////////////////////////////////////////
			//Criação da matriz de tamanho igual ao arquivo//
		  /////////////////////////////////////////////////

			matriz=(unsigned char**)malloc((alt+(mask-1))*sizeof(unsigned char*));
			for (i=0;i<(alt+(mask-1));i++){
				matriz[i]=(unsigned char*)malloc((lar+(mask-1))*sizeof(unsigned char));
			}
			matrizrec=(float**)malloc((alt+(mask-1))*sizeof(float*));
			for (i=0;i<(alt+(mask-1));i++){
				matrizrec[i]=(float*)malloc((lar+(mask-1))*sizeof(float));
			}

			 /////////////////////////////////////
			//Preenche a matriz com borda com 0//
		  /////////////////////////////////////

			for (i=0; i<alt+(mask-1); i++) {
				for (j=0; j<lar+(mask-1); j++) {
					matriz[i][j]=0;
					matrizrec[i][j]=0;
				}
			}
			if(count==40){
				matrizvariavel=(float**)malloc(mask*sizeof(float*));
				for (i=0;i<mask;i++){
					matrizvariavel[i]=(float*)malloc(mask*sizeof(float));
				}
	
				 ////////////////////////////////////////
				//Preenche a matriz de filtro variavel//
			  ////////////////////////////////////////

				for (i=0; i<floor(mask); i++) {
					for (j=0; j<floor(mask); j++) {
						matrizvariavel[i][j]=1/(mask*mask);
					}
				}
			}

			 ////////////////////////////////////////
			//preenche a matriz atraves do arquivo//
		  ////////////////////////////////////////

			for (i = floor(mask/2); i< alt+floor(mask/2); i++) {
				for (j = floor(mask/2); j< lar+floor(mask/2); j++) {
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

			////////////////
		  //Filtro Sobel//
		 ////////////////

			if(count==10){
				mask=3.0;
				for (i=floor(mask/2); i<alt+floor(mask/2); i++) {
					for (j=floor(mask/2); j<lar+floor(mask/2); j++) {
						soma=0;				
						for (k=i-floor(mask/2),a=0;a<mask; k++, a++) {
							for (l=j-floor(mask/2),b=0;b<mask; l++, b++) {
								soma+=(matriz[k][l]*sobel[a][b]);
							}
						}
						if(soma>esc){
							soma=esc;
						}
						else if(soma<0){
							soma=0;
						}
						matrizrec[i][j]=floor(soma);
					}
				}

				 ///////////////////
				//Salva o arquivo//
			  ///////////////////


				strcat(sobeln,nomearquivo);
				ps = fopen(sobeln, "w");
				fprintf(ps,"%s\n",p2);
				fprintf(ps,"#Aplicação de filtro Sobel criada por Raynan S. (IFCE)\n");
				fprintf(ps,"%d %d\n",lar, alt);
				fprintf(ps,"%d\n",esc);
				c=0;
				for(i=floor(mask/2); i<alt+floor(mask/2); i++){
					for(j=floor(mask/2); j<lar+floor(mask/2); j++){
						fprintf(ps,"%.0f\t\t",matrizrec[i][j]);
						c++;
						if (c>=10){
							fprintf(ps,"\n");
							c=0;
						}
					}
				}
			}

			/////////////////////
		  //Filtro laplaciano//
		 /////////////////////

			if(count==20){
				mask=3.0;
				for (i=floor(mask/2); i<alt+floor(mask/2); i++) {
					for (j=floor(mask/2); j<lar+floor(mask/2); j++) {
						soma=0;				
						for (k=i-floor(mask/2),a=0;a<mask; k++, a++) {
							for (l=j-floor(mask/2),b=0;b<mask; l++, b++) {
								soma+=(matriz[k][l]*laplace[a][b]);
							}
						}
						if(soma>esc){
							soma=esc;
						}
						else if(soma<0){
							soma=0;
						}
						matrizrec[i][j]=floor(soma);
					}
				}

				 ///////////////////
				//Salva o arquivo//
			  ///////////////////


				strcat(laplacen,nomearquivo);
				ps = fopen(laplacen, "w");
				fprintf(ps,"%s\n",p2);
				fprintf(ps,"#Aplicação de filtro Laplaciana criada por Raynan S. (IFCE)\n");
				fprintf(ps,"%d %d\n",lar, alt);
				fprintf(ps,"%d\n",esc);
				c=0;
				for(i=floor(mask/2); i<alt+floor(mask/2); i++){
					for(j=floor(mask/2); j<lar+floor(mask/2); j++){
						fprintf(ps,"%.0f\t\t",matrizrec[i][j]);
						c++;
						if (c>=10){
							fprintf(ps,"\n");
							c=0;
						}
					}
				}
			}

			/////////////////
		  //Filtro Prewitt//
		 /////////////////

			if(count==30){
				mask=3.0;
				for (i=floor(mask/2); i<alt+floor(mask/2); i++) {
					for (j=floor(mask/2); j<lar+floor(mask/2); j++) {
						soma=0;				
						for (k=i-floor(mask/2),a=0;a<mask; k++, a++) {
							for (l=j-floor(mask/2),b=0;b<mask; l++, b++) {
								soma+=(matriz[k][l]*prewitt[a][b]);
							}
						}
						if(soma>esc){
							soma=esc;
						}
						else if(soma<0){
							soma=0;
						}
						matrizrec[i][j]=floor(soma);
					}
				}

				 ///////////////////
				//Salva o arquivo//
			  ///////////////////


				strcat(prewittn,nomearquivo);
				ps = fopen(prewittn, "w");
				fprintf(ps,"%s\n",p2);
				fprintf(ps,"#Aplicação de filtro Prewitt criada por Raynan S. (IFCE)\n");
				fprintf(ps,"%d %d\n",lar, alt);
				fprintf(ps,"%d\n",esc);
				c=0;
				for(i=floor(mask/2); i<alt+floor(mask/2); i++){
					for(j=floor(mask/2); j<lar+floor(mask/2); j++){
						fprintf(ps,"%.0f\t\t",matrizrec[i][j]);
						c++;
						if (c>=10){
							fprintf(ps,"\n");
							c=0;
						}
					}
				}
			}
			 ////////////////////
			//Filtro Gaussiano//
		  ////////////////////

			if(count==40){

				for (i=floor(mask/2); i<alt+floor(mask/2); i++) {
					for (j=floor(mask/2); j<lar+floor(mask/2); j++) {
						soma=0;				
						for (k=i-floor(mask/2),a=0;a<mask; k++, a++) {
							for (l=j-floor(mask/2),b=0;b<mask; l++, b++) {
								soma+=(matriz[k][l]*matrizvariavel[a][b]);
							}
						}
						if(soma>esc){
							soma=esc;
						}
						else if(soma<0){
							soma=0;
						}
						matrizrec[i][j]=floor(soma);
					}
				}

				 ///////////////////
				//Salva o arquivo//
			  ///////////////////

				sprintf (tmask,"%.0f",mask);
				strcat(gaussianon,tmask);
				strcat(gaussianon,"x");
				strcat(gaussianon,tmask);
				strcat(gaussianon," ");
				strcat(gaussianon,nomearquivo);
				ps = fopen(gaussianon, "w");
				fprintf(ps,"%s\n",p2);
				fprintf(ps,"#Aplicação de filtro Gaussiana de %.0fx%.0f criada por Raynan S. (IFCE)\n",mask,mask);
				fprintf(ps,"%d %d\n",lar, alt);
				fprintf(ps,"%d\n",esc);
				c=0;
				for(i=0; i<alt; i++){
					for(j=0; j<lar; j++){
						fprintf(ps,"%.0f\t\t",matrizrec[i][j]);
						c++;
						if (c>=10){
							fprintf(ps,"\n");
							c=0;
						}
					}
				}
			}

			 /////////////////////
			//Filtro de Denoise//
		  /////////////////////

			if(count==50){
				vet=(int*)malloc(mask*mask*sizeof(int));
				for (i=floor(mask/2); i<alt+floor(mask/2); i++) {
					for (j=floor(mask/2); j<lar+floor(mask/2); j++) {
						maskint=0;
						soma=0;				
						for (k=i-floor(mask/2),a=0;a<mask; k++, a++) {
							for (l=j-floor(mask/2),b=0;b<mask; l++, b++) {
								vet[maskint++]=matriz[k][l];
							}
						}
						qsort(vet, mask*mask, sizeof(int), cmpfunc);
						maskint=floor((mask*mask)/2);
						matrizrec[i][j]=vet[maskint];
					}
				}

				 ///////////////////
				//Salva o arquivo//
			  ///////////////////

				sprintf (tmask,"%.0f",mask);
				strcat(Denoise,tmask);
				strcat(Denoise,"x");
				strcat(Denoise,tmask);
				strcat(Denoise," ");
				strcat(Denoise,nomearquivo);
				ps = fopen(Denoise, "w");
				fprintf(ps,"%s\n",p2);
				fprintf(ps,"#Aplicação de filtro Denoise de %.0fx%.0f criada por Raynan S. (IFCE)\n",mask,mask);
				fprintf(ps,"%d %d\n",lar, alt);
				fprintf(ps,"%d\n",esc);
				c=0;
				for(i=0; i<alt; i++){
					for(j=0; j<lar; j++){
						fprintf(ps,"%.0f\t\t",matrizrec[i][j]);
						c++;
						if (c>=10){
							fprintf(ps,"\n");
							c=0;
						}
					}
				}
			}


		system("clear");
		exit(1);
		}
		free(matriz);
		free(matrizvariavel);
		free(matrizrec);
		fclose(fp);
		fclose(ps);
		return 0;
	}
