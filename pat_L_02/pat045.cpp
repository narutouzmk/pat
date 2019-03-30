#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

map<long long, long long> mp;
int N, K, M;
int main(void){
	long long id, len;
	char c;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%lld%c%lld", &id, &c, &len);
		if(c == 'x'){
			id = -id;
		}
		if(!mp.count(id)){
			mp[id] = 0;
		}
		if(len > 0 && len <= K){
			mp[id] += K;
		}else{
			mp[id] += len;
		}
	}

	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		scanf("%lld%c", &id, &c);
		if(c == 'x'){
			id = -id;
		}
		if(mp.count(id)){
			printf("%lld\n", mp[id]);
		}else{
			printf("No Info\n");
		}
	}

	return 0;
}
