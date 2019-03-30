#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
//#define MAX 1000

/*int B[MAX];
int A, count = 0;

void dfs(int);*/

int main(){
	int i, j, k, A, count = 0;
	scanf("%d", &A);
	for(i = A; i <= A + 3; ++i){
		for(j = A; j <= A + 3; ++j){
			if(i != j){
				for(k = A; k <= A + 3; ++k){
					if(k != i && k != j){
						if(count < 5){
							++count;
							printf("%d ", i * 100 + j * 10 + k);
						}else{
							count = 0;
							printf("%d\n", i * 100 + j * 10 + k);
						}
					}
				}
			}
		}
	}
	/*for(int j = 0; j < 4; ++j)
		B[j] = A + j;

	dfs(0);*/

	return 0;
}

/*void dfs(int cur){
	int i;
	if(cur == 4){
		for(i = 0; i < 3; ++i){
			printf("%d", B[i]);
		}
		if(count < 5){
			++count;
			printf(" ");
		}else{
			count = 0;
			printf("\n");
		}
	}else{
		for(i = cur; i < 4; ++i){
			swap(B[cur], B[i]);
			dfs(cur + 1);
			swap(B[cur], B[i]);
		}
	}
}*/
