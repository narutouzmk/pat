#include <iostream>
#include <cstdio>
#include <string.h>
#define MAXS 10001

using namespace std;

int main(void){
	int N, K;
	int i, j, flag;
	char s[MAXS][11] = {0};//这里如果采用char *A[N] ,用gets()会内存溢出.
	char tmp[10] = {0};
	scanf("%d %d", &N, &K);
	getchar();

	for(i = 0; i < N; ++i){
		gets(s[i]);
	}

	for(i = 1; i < N; ++i){
		flag = 0;
		for(j = 1; j < N; ++j){
			if(strcmp(s[j], s[j-1]) < 0){
				strcpy(tmp, s[j]);
				strcpy(s[j], s[j-1]);
				strcpy(s[j-1], tmp);
				flag = 1;
			}
		}

		if(!flag || i == K){
			for(i = 0; i < N; ++i){
				puts(s[i]);
			}
			break;
		}
	}
	return 0;
}

