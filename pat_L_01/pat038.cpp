#include <iostream>
#include <cstring>

using namespace std;

#define MAXS 100005

int A, N;
//int digit = 1;
void input_n(int *a, int);
void add_big(int *a, int *b);

int main(void){
	int i, k;
	int RS[MAXS], TM[MAXS];
	memset(RS, 0, sizeof(RS));
	memset(TM, 0, sizeof(TM));

	cin >> A >> N;
	if(N == 0){
		cout << "0" <<endl;
		return 0;
	}

	for(i = 1; i <= N; ++i){
		input_n(TM, i);
		add_big(RS, TM);
	}
	i = MAXS;
	while(RS[i] == 0) --i;

	while(i>=0)
		cout<<RS[i--];
	cout<<endl;

	return 0;
}

void input_n(int *a, int n){
	int top = 0;
	memset(a, 0, sizeof(a));
//	for(int i = 0; i < MAXS; ++i) a[i] = 0;
	while(top < n){
//		if(n == 2) cout<<"zhixin"<<endl;
		a[top] = A;
//		if(n == 2) cout<<"A="<<A<<",a["<<top<<"]="<<a[top]<<endl;
		top++;
	}

/*	while(top >= 0){
		cout<<"n="<<n<<","<<"top="<<top<<",a["<<top<<"]="<<a[top]<<",";
		--top;
	}*/
//	if(n==2) cout<<endl;
//	cout<<endl;
}

void add_big(int rs[], int tm[]){
	int result, carry = 0;
	int i = 0, j = 0;
	for(j = 0; rs[j] != 0 || tm[j] != 0; ++j){
		result = rs[j] + tm[j];
		carry = result / 10;
		rs[j] = result % 10;
//		++digit;
//		cout<<rs[j];
		if(carry){
			int k = j+1;
			while(carry){
				result = rs[k] + carry;
				carry = result / 10;
				rs[k] = result % 10;
//				++digit;
				++k;
			}
		}
	}
/*	while(rs[j] != 0){
		cout<<rs[j]<<",";
	}
	cout<<"jiewei"<<endl;*/
}
