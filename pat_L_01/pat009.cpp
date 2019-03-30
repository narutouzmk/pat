#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int a, b, c;
	int flag;
	scanf("%d %d %d", &a, &b, &c);
	flag = a == b ? 1 : 0;
	if(flag)
		printf("C\n");
	else{
		flag = b == c ? 1 : 0;
		if(flag){
			printf("A\n");
		}else{
			printf("B\n");
		}
	}

	return 0;
}
