#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define MAXS 1000

int main(){
	int A = MAXS, B = MAXS;
	int sum = 0, i, c;
	scanf("%d %d", &A, &B);
	if(A == B){
		printf("%5d\n", A);
		sum = A;
	}else{
		c = 0;
		for(i = A; i <= B; ++ i){
			sum += i;
			++c;
			if(c < 5){
				printf("%5d", i);
			}else{
				c = 0;
				printf("%5d\n", i);
			}
		}
		if((B - A + 1) % 5 != 0)
			printf("\n");
	}
	printf("Sum = %d\n", sum);
	return 0;
}
