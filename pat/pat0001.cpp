#include <stdio.h>
#include <stdlib.h>

void prinT(int N){
	for(int i = 1; i <= N; ++i)
		printf("%d\n", i);
}

int main(){
	int N;
	scanf("%d", &N);
	prinT(N);
	return 0;
}


