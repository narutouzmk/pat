#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define MAXS 10001

int num[MAXS] = {0};

int main(void){
	int i, j, m,N, K;
	int flag = 0;
	scanf("%d %d", &N, &K);

	for(i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	m = 0;
	for(i = N-1; i > 0; --i){
		flag = 0;
		for(j = 1; j <= i; ++j){
			if(num[j] < num[j-1]){
				swap(num[j], num[j-1]);
				flag = 1;
			}
		}
		++m;
		if(m == K || flag == 0){
			for(i = 0; i < N-1; ++i){
				printf("%d ", num[i]);
			}
			break;
		}
	}

	printf("%d\n", num[N-1]);

	return 0;
}
