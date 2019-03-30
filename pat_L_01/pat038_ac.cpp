#include <iostream>
#include <cstring>

using namespace std;

#define MAXS 100005

int main(void){
	char num[MAXS];
	int A, N;
	int jw = 0, i;
	memset(num, 0, sizeof(num));

	cin>>A>>N;
	if(N == 0){
		cout<<0<<endl;
		return 0;
	}

	for(i = 1; i <= N; ++i){
		num[i] = (A * (N + 1 - i) + jw) % 10 + '0';
		jw = ((A * (N + 1 - i) + jw) - (A * (N + 1 - i) + jw) % 10)/10;
	}

	if(jw > 0)
		cout<<jw;
	for(i = N; i >= 1; --i)
		cout<<num[i] - '0';
	cout<<endl;

	return 0;
}
