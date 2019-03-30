#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void Print_Factorial(const int N);

int main(){
	int N;
	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}
void Print_Factorial(const int N){
	if(N == 0){
		printf("1\n");
	}else if(N > 0){
		int fac[10000] = {0}, digit = 0;
		int result, carry = 0;
		int i, j, k = 1;
		fac[0] = 1;
		for(i = 2; i <= N; ++i){
			carry = 0;
			for(j = 0; j <= digit; ++j){
				result = fac[j] * i + carry;
				fac[j] = result % 10;
				carry = result / 10;
			}
			while(carry){
				fac[++digit] = carry % 10;
				carry /= 10;
			}
		}
		for(i = digit; i >= 0; --i)
			printf("%d", fac[i]);
		printf("\n");
	}
	else{
		printf("Invalid input\n");
	}
}
