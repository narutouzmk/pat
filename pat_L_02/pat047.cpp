#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

/*struct Lesson{
	int n, count;
	vector<string> name;
};*/

/*typedef struct Lesson Lesson;
Lesson les[2600];*/

vector<string> course[2501];

int N, K;

int main(void){
	scanf("%d %d", &N, &K);


	for(int i = 0; i < N; ++i){
		char name[5];
		int c;
		scanf("%s", name);
		scanf("%d", &c);
		for(int j = 0; j < c; ++j){
			int n;
			scanf("%d", &n);
			course[n].push_back(name);
		}
	}

	for(int i = 1; i <= K; ++i){
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, (int)course[i].size());
		for(int j = 0; j < course[i].size(); ++j){
			printf("%s\n", course[i][j].c_str());
		}
		
	}
	return 0;
}
