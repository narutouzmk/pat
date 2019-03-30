#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void){
	int a, b;
	char op;
	scanf("%d %c %d", &a, &op, &b);

	switch(op){
		case '+':
			printf("%d\n", a + b);
			break;
		case '-':
			printf("%d\n", a - b);
			break;
		case '*':
			printf("%d\n", a * b);
			break;
		case '/':
			if(b == 0){
				printf("ERROR: zero divided\n");
			}else{
				printf("%d\n", a / b);
			}
			break;
		case '%':
			if(b == 0){
				printf("ERROR: zero divided\n");
			}else{
				printf("%d\n", a % b);
			}
			break;
		default:
			printf("ERROR\n");
	}
	return 0;
}
