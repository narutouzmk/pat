#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1010

int N, P;
char table[MAXN][10];
char input[10];
int vis[MAXN] = {0};

int getNum(char *);

int main(void){
	scanf("%d %d", &N, &P);
	for(int i = 0; i < N; ++i){
		scanf("%s", input);
		int num = getNum(input);
		for(int j = 0; j < P; ++j){
			int index = (num + j * j) % P;
			if(!vis[index] || strcmp(table[index], input) == 0){
				vis[index] = 1;
				strcpy(table[index], input);
				printf("%d", index);
				break;
			}

			index = (num - j * j) % P;
			while(index < 0){
				index += P;
			}

			if(!vis[index] || strcmp(table[index], input) == 0){
				vis[index] = 1;
				strcpy(table[index], input);
				printf("%d", index);
				break;
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

int getNum(char *c){
	int sum = 0, i = strlen(c) - 1, count = 0;
	int len = strlen(c) > 3 ? 3 : strlen(c);
	while(len--){
		sum += (c[i] - 'A') * (int)pow(32, count);
		--i;
		++count;
	}

	return sum;
}
