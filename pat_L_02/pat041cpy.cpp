#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 30010

struct Information{
	char num[20];
	int score;
	int point;
	int a1, a2;
};

typedef struct Information Inf;

Inf inf[MAXN];
int N, K;

bool comp(const Inf &in1, const Inf &in2);
int main(void){
	int sum = 0, c = 0;
	int i = 0;
	scanf("%d", &N);
	getchar();

	while(N--){
		++c;
		scanf("%d", &K);
		getchar();
		if(K > 0){
			int start = i;
			sum += K;
			for(; i < K + start; ++i){
				Inf tmp;
				scanf("%s %d", tmp.num, &tmp.score);
				tmp.point = c;
				inf[i] = tmp;
			}
			
			sort(inf+start, inf+K+start, comp);
			inf[start].a1 = 1;
			for(int j = start + 1; j < i; ++j){
				if(inf[j].score == inf[j - 1].score){
					inf[j].a1 = inf[j - 1].a1;
				}else{
					inf[j].a1 = j - start + 1;
				}
			}
			/*for(int j = 0; j < i; ++j){
				cout << inf[j].num << " " << inf[j].score << " " << inf[j].a1 << endl;
			}
			cout << endl;*/
		}
	}

	
	sort(inf, inf+sum, comp);
	inf[0].a2 = 1;
	for(int j = 0; j < sum; ++j){
		if(inf[j].score == inf[j - 1].score){
			inf[j].a2 = inf[j - 1].a2;
		}else{
			inf[j].a2 = j + 1;
		}
	}
	printf("%d\n", sum);
	for(int j = 0; j < sum; ++j){
		printf("%s %d %d %d\n", inf[j].num, inf[j].a2, inf[j].point, inf[j].a1);	
	}
	return 0;
}

bool comp(const Inf &in1, const Inf &in2){
	if(in1.score > in2.score){
		return true;
	}else if(in1.score == in2.score && strcmp(in1.num, in2.num) < 0){
		return true;
	}else{
		return false;
	}
}
