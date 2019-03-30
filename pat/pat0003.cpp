#include <iostream>
#include <stdio.h>

#define MAXN 10

using namespace std;

int Sum(int List[], int N);

int main(){
	int List[MAXN], N, i;

	scanf("%d", &N);

	for(i = 0; i <N; ++i)
		scanf("%d", &List[i]);

	printf("%d\n", Sum(List, N));
	return 0;
}

int Sum(int List[], int N){
	int i, count = 0;
	for(i = 0; i < N; ++i){
		count += List[i];
	}
	return count;
}
