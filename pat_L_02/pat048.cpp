#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10010

struct customer{
	char name[4];
	int arrTime, proTime;
};

unordered_map<string, int> friendMap, customerId;
bool vis[MAXN];
vector<string> friends[110], result;

/*****
 窗口时间: 银行最早能受理业务的时间
 *****/

int N, M;
bool cmp(string s1, string s2);

int main(void){
	scanf("%d %d", &N, &M);
	fill(vis, vis + N, false);
	for(int i = 0; i < M; ++i){
		int len;
		scanf("%d", &len);
		for(int j = 0; j < len; ++j){
			char name[4];
			scanf("%s", name);
			friends[i].push_back(name);
			friendMap[name] = i;
		}
	}

	customer customers[N];

	for(int i = 0; i < N; ++i){
		char name[4];
		scanf("%s %d %d", name, &customers[i].arrTime, &customers[i].proTime);
		if(customers[i].proTime > 60){
			customers[i].proTime = 60;
		}
		strcpy(customers[i].name, name);
		customerId[name] = i;
	}

	int totalTime = 0;//总的等待时间
	int window = customers[0].arrTime;//一开始的窗口时间应该设置为最先到达顾客的时间
	for(int i = 0; i < N; ++i){
		if(vis[i]){
			continue;
		}
		//find找到被查找元素的位置
		if((friendMap.find(customers[i].name)) == friendMap.end()){
			if(window > customers[i].arrTime){
				totalTime += window - customers[i].arrTime;
				window += customers[i].proTime;
			}else{
				window = customers[i].arrTime + customers[i].proTime;
			}
			vis[i] = true;
			result.push_back(customers[i].name);
			continue;
		}

		int friendId = friendMap[customers[i].name];
		sort(friends[friendId].begin(), friends[friendId].end(), cmp);

		for(int j = 0; j < friends[friendId].size(); ++j){
			int id = customerId[friends[friendId][j]];
			if(j > 0 && customers[id].arrTime > window){
				break;
			}

			if(vis[id]){
				continue;
			}

			if(window > customers[id].arrTime){
				totalTime += window - customers[id].arrTime;
				window += customers[id].proTime;
			}else{
				window = customers[id].arrTime + customers[id].proTime;
			}
			vis[id] = true;
			result.push_back(friends[friendId][j]);
		}
	}

	for(int i = 0; i < result.size(); ++i){
		printf("%s\n", result[i].c_str());
	}
	printf("%.1f\n", totalTime * 1.0 / N);
	return 0;
}

bool cmp(string s1, string s2){
	return customerId[s1] < customerId[s2];
}
