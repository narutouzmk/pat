#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

priority_queue<int> pq;

int N, M;

int main(void){
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i){
		int a;
		scanf("%d", &a);
		pq.push(a);
	}

	printf("%d", pq.top());
	pq.pop();
	int a = N > M ? M : N;
	for(int i = 1; i < a; ++i){
		printf(" %d",pq.top());
		pq.pop();
	}

	printf("\n");
	return 0;
}
