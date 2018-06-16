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
