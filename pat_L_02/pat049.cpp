#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

struct cmp{
	bool operator()(int a, int b){
		return a > b;
	}
};

int N, K;

priority_queue<int, vector<int>, cmp> pq;
map<string, priority_queue<int, vector<int>, cmp> > stus;

bool cmp(int a, int b);
int main(void){
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= K; ++i){
		int c, n;
		scanf("%d %d", &c, &n);
		for(int j = 0; j < n; ++j){
			char name[5];
			scanf("%s", name);
			stus[name].push(c);
		}
	}

	for(int i = 0; i < N; ++i){
		char name[5];
		scanf("%s", name);
		pq = stus[name];
		printf("%s %d", name, (int)pq.size());
		while(!pq.empty()){
			printf(" %d", pq.top());
			pq.pop();
		}
		printf("\n");
	}
	return 0;
}
/*vector<string> course[2510];
map<string, int> mp;
int main(void){
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= K; ++i){
		int m , n;
		scanf("%d %d", &m, &n);
		for(int j = 0; j < n; ++j){
			char name[5];
			scanf("%s", name);
			course[m].push_back(name);
			if(mp.count(name) == 0){
				mp[name] = 0;
			}
			mp[name]++;
		}
	}

	for(int i = 0; i < N; ++i){
		char name[5];
		scanf("%s", name);
		printf("%s %d", name, mp[name]);
		for(int j = 1; j <= K; ++j){
			if(count(course[j].begin(), course[j].end(), name) != 0){
				printf(" %d", j);
			}
		}
		printf("\n");
	}

	return 0;
}*/

/*struct Student{
	char name[5];
	vector<int> course;
};

unordered_map<string, Student> stmp;

int main(void){
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= K; ++i){
		int a, n;
		scanf("%d %d", &a, &n);
		for(int j = 0; j < n; ++j){
			char name[5];
			scanf("%s", name);
			strcpy(stmp[name].name, name);
			stmp[name].course.push_back(a);
		}
	}

	for(int i = 0; i < N; ++i){
		char name[5];
		scanf("%s", name);
		printf("%s %d", name, stmp[name].course.size());
		for(int j = 0; j < stmp[name].course.size(); ++j){
			printf(" %d", stmp[name].course[j]);
		}
		printf("\n");
	}
	return 0;
}*/
