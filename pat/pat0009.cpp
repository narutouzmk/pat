#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int Count_Digit(const int N, const int D);

int main(){
	int N, D;
	scanf("%d %d", &N, &D);

	printf("%d\n",Count_Digit(N, D));

	return 0;
}

int Count_Digit(const int N, const int D){
	if(N == 0) return 1;
	int i, k, c;
	c = 0;
	k = N > 0 ? N : -N;
	while(k > 0){
		i = k % 10;
		if(i == D){
			++c;
		}
		k /= 10;
	}

	return c;
}
