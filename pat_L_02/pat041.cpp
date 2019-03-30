#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 306

struct Information{
	char num[20];
	int score;
	int point;
	int a1, a2;//a1考点内排序，a2考点外排序
};

typedef struct Information Inf;

//Inf inf[MAXN][MAXN];

vector<vector<Inf> > inf;

int N, K;

bool comp(const Inf &in1, const Inf &in2);
int main(void){
	int sum = 0, c = 0;
	scanf("%d", &N);
	getchar();

	inf.resize(MAXN + 1);
	
	while(N--){
		++c;
		scanf("%d", &K);
		getchar();
		if(K > 0){
			Inf tmp;
			sum += K;
			for(int i = 0; i < K; ++i){
				scanf("%s %d", tmp.num, &tmp.score);
				tmp.point = c;
				inf[c].push_back(tmp);
			}

			sort(inf[c].begin(), inf[c].end(), comp);
			inf[c][0].a1 = 1;
			for(int i = 1; i < inf[c].size(); ++i){
				if(inf[c][i].score == inf[c][i - 1].score){
					inf[c][i].a1 = inf[c][i - 1].a1;
				}else{
					inf[c][i].a1 = i + 1;
				}
			}

			/*for(int i = 0; i < inf[c].size(); ++i){
				cout << inf[c][i].num << " " <<inf[c][i].score << " " <<" "<< inf[c][i].a1 << endl;
			}
			cout << endl;*/
		}
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
