#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define TOR_V 3
#define RIB_V 9

int main(){
	int tor_d = 0, rib_d = 0;
	int T, count = 0;
	scanf("%d", &T);

	do{
		--T;
		++count;
		tor_d += TOR_V;
		rib_d += RIB_V;
		if(count == 10){
			count = 0;
			if(rib_d > tor_d){
				if(T > 30){
					T -= 30;
					tor_d += 30 * TOR_V;
				}else{
					tor_d += T * TOR_V;
					T = 0;
				}
			}
		}
		//printf("%-3d %-3d %-3d\n", tor_d, rib_d, rest);
	}while(T > 0);

	if(tor_d == rib_d){
		printf("-_- %d\n", tor_d);
	}
	else{
		printf("%s %d\n", tor_d > rib_d ? "@_@" : "^_^", tor_d > rib_d ? tor_d : rib_d);
	}

	return 0;
}
