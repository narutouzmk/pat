#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	int N, U, D;
	int pos = 0, minute = 0;

	scanf("%d %d %d", &N, &U, &D);
	do{
		++minute;
		pos += U;
		if(pos >= N)
			break;
		pos = pos - D;
		++minute;
	}while(1);

	printf("%d\n", minute);
	return 0;
}
