#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	int Speed;
	char *S = NULL;;
	scanf("%d", &Speed);
	if(Speed <= 60){
		S = "OK";
		printf("Speed: %d - %s\n", Speed, S);
	}else{
		S = "Speeding";
		printf("Speed: %d - %s\n", Speed, S);
	}

	return 0;
}
