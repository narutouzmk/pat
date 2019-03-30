#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1010

int N, P;
int vis[MAXN];
int nums[MAXN];

int main(void){
	memset(vis, 0, sizeof(vis));
	memset(nums, 0, sizeof(nums));

	scanf("%d %d", &N, &P);
	for(int i = 0; i < N; ++i){
		int num;
		scanf("%d", &num);

		for(int j = 0; j < P; ++j){
			if(!vis[(num + j) % P] || nums[(num + j) % P] == num){
				vis[(num + j) % P] = 1;
				nums[(num + 1) % P] = num;
				printf("%d", (num + 1) % P);
			}
		}

		if(i == N - 1){
			printf("\n");
		}else{
			printf(" ");
		}
	}

	return 0;
}
