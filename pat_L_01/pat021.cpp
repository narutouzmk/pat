#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
	int N, flag = 0;
	int X, Y;

	scanf("%d", &N);

	for(X = 0; X < sqrt(N); ++X){
		for(Y = 0; Y < sqrt(N); ++Y){
			if(X * X + Y * Y == N && X < Y){
				flag = 1;
				printf("%d %d\n", X, Y);
			}
		}
	}

	if(!flag){
		printf("No Solution\n");
	}
	return 0;
}
