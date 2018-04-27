#include <stdio.h>

int v[100];

int fib(int n);

int main () {
	int i;
	int n;
	for (i=2;i<=100;v[i++]=0);
	scanf ("%d", &n);
	printf ("%d", fib(n));
	return 0;
}

int fib(int n){
	if(v[n-1]!=0){
		return v[n-1];
	}
	else if(n<=2){
		return v[n-1]=1;
	}
	else{
		v[n-1]=fib(n-1)+fib(n-2);
		return v[n-1];
	}
}
