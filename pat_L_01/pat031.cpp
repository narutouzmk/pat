#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

#define MAXS 106

void reverse(char *, int, int);
void swap(char *, char *);

int main(void){
	int N, len = 0, i = 0;
	char A[MAXS], c;

	while((c = getchar()) != '\n'){
		A[i] = c;
		++i;
	}
	
	A[i] = '\0';

	scanf("%d", &N);
	N = N % i;

	reverse(A,0,N-1);
	reverse(A,N,i-1);
	reverse(A,0,i-1);
	
	puts(A);
	return 0;
}

void reverse(char *A, int left, int right){
	int i, j;
	i = left;
	j = right;
	while(i < j){
		swap(&A[i], &A[j]);
		++i;
		--j;
	}
}

void swap(char *a, char *b){

	char tmp;//在这里tmp不能是char *tmp，否则会出现核心转换错误.
	tmp = *a;
	*a = *b;
	*b = tmp;
}
