#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int Factorial(const int N);

int main(){
	int N, NF;

	scanf("%d", &N);
	NF = Factorial(N);

	if(NF)
		printf("%d! = %d\n", N, NF);
	else
		printf("Invalid input\n");
	return 0;
}

int Factorial(const int N){

	if(N < 0)
		return 0;
	int result = 1;
	for(int i = N; i > 0; --i){
		result *= i;
	}

	return result;
}
