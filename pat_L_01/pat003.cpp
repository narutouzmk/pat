#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	int num;
	int stack[3] = {0}, top = -1;

	scanf("%d", &num);

	stack[++top] = num % 1000 / 100;
	stack[++top] = num % 100 / 10;
	stack[++top] = num % 10;

	while(stack[top] == 0) --top;

	while(top != -1)
		printf("%d", stack[top--]);
	printf("\n");

	return 0;
}
