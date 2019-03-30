#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

int main(void){
	char c;
	int count = 0, i = 0;
	int n[100] = {0}, top = -1;
	while(scanf("%c", &c)){
		if(c == '.'){
			n[++top] = count;
			break;
		}
		if(isspace(c)){
			n[++top] = count;
			fflush(stdin);
			count = 0;
		}else{
			++count;
		}
	}

	while(n[top] == 0 && top > -1){
		--top;
	}

	if(top == -1){
		++top;
	}
	for(i = 0; i < top; ++i){
		if(n[i] != 0)
			printf("%d ", n[i]);
	}

	if(n[top] != 0){
		printf("%d\n", n[top]);
	}else{
		printf("\n");
	}
	return 0;
}
