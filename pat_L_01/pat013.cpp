#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	double Open, High, Lower, Close;
	scanf("%lf %lf %lf %lf", &Open, &High, &Lower, &Close);
	if(Open == Close){
		printf("R-Cross");
	}else if(Open < Close){
		printf("R-Hollow");
	}else{
		printf("BW-Solid");
	}

	if((Lower < Open && Lower < Close) && (High > Open && High > Close)){
		printf(" with Lower Shadow and Upper Shadow\n");
	}else if(Lower < Open && Lower < Close){
		printf(" with Lower Shadow\n");
	}else if(High > Open && High > Close){
		printf(" with Upper Shadow\n");
	}else{
		printf("\n");
	}
	return 0;
}
