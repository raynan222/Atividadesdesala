#include <stdio.h>
int main(){
	int botas[31][2],n,i,tam,count=0;
	char pe;
	scanf ("%d", &n);
	for (i=0;i<31;i++){
		botas[i][0]=0;
		botas[i][1]=0;
	}
	for (i=0;i<n;i++){
		scanf("%d %c", &tam, &pe);
		if (pe=='E'){
			botas[tam-30][1]++;
		}
		if (pe=='D'){
			botas[tam-30][0]++;
		}
	}
	for (i=0;i<31;i++){
		if(botas[i][0]>botas[i][1]){
			count+=botas[i][1];
		}
		else{
			count+=botas[i][0];
		}
	}
	printf("%d\n" ,count);
	return 0;
}
