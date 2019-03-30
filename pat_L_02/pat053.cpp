#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000

int N;
vector<int> st;

int main(void){
	int n;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &n);
		st.push_back(n);
	}

	for(int i = 0; i < N; ++i){
		scanf("%d", &n);
		st.push_back(n);
	}

	sort(st.begin(), st.end());

	printf("%d\n", st[N - 1]);
	return 0;
}
