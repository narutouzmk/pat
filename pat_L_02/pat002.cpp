#include <iostream>
#include <cstring>

using namespace std;

#define MAXS 2001

int A[MAXS], B[MAXS];
int C[MAXS];

void add_num(int *, int *, int *);
void multiply(int *, int *, int *);
void outputs(int *);

int main(void){
	int a, b, i;
	int t1, t2;

	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(C, 0, sizeof(C));

	cin>>a;
	for(i = 0; i < a;++i){
		cin>>t1>>t2;
		A[t2] += t1;
	}

	cin>>b;
	for(i = 0; i < b; ++i){
		cin>>t1>>t2;
		B[t2] += t1;
	}

	multiply(A, B, C);
	outputs(C);
	
	add_num(A, B, C);
	outputs(C);

	return 0;
}

void add_num(int *A, int *B, int *C){
	int i, j, k;
	int sum;

	for(i = 0; i < MAXS; ++i)
		C[i] = 0;

	for(i = 0; i < MAXS; ++i){
		if(A[i] || B[i]){
			sum = A[i] + B[i];
			if(sum != 0)
				C[i] = sum;
		}
	}
}

void multiply(int *A, int *B, int *C){
	int i, j, k;
	int sum;
	k = 0;

	for(i = 0; i < MAXS; ++i)
		C[i] = 0;
	for(i = 0; i < MAXS; ++i){
		for(j = 0; j < MAXS; ++j){
			if(A[i] && B[j]){
				sum = A[i] * B[j];
				C[i+j] += sum;
			}
		}
	}
}

void outputs(int *C){
	int i = 2000;
	while(C[i] == 0 && i > -1){
		--i;
	}
	if(i == -1){
		cout<<"0 0"<<endl;
		return;
	}else if(i == 0){
		cout<<C[i]<<" "<<i<<endl;
		return;
	}
	cout<<C[i]<<" "<<i;
	--i;
	for(;i>=0; --i){
		if(C[i]){
			cout<<" "<<C[i]<<" "<<i;
		}
	}

	cout<<endl;
}









