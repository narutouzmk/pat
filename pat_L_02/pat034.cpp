#include <iostream>
#include <vector>

using namespace std;

#define MAX 0x3f3f3f3f
#define MIN 0xc0c0c0c0

struct activity{
	int sta;
	int end;
	bool flag;
};

typedef struct activity activity;

vector<vector<activity> > vedge;
vector<int> in_degree;
vector<int> out_degree;
vector<int> vSta;
vector<int> vEnd;

bool isTop(vector<int>);

int N;

int main(void){
	int k;
	activity actTmp;
	cin >> N;
	vedge.resize(N + 1);
	in_degree.resize(N + 1, 0);
	out_degree.resize(N + 1, 0);

	for(int i = 1; i <= N; ++i){
		cin >> k;
		actTmp.flag = true;
		actTmp.end = i;
		for(int j = 0; j < k; ++j){
			cin >> actTmp.sta;
			vedge[actTmp.sta].push_back(actTmp);
			actTmp.flag = false;
			vedge[actTmp.end].push_back(actTmp);
			actTmp.flag = true;

			in_degree[actTmp.end]++;
			out_degree[actTmp.sta]++;
		}
	}

	if(isTop(in_degree)){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}

	return 0;
}

bool isTop(vector<int> in_degree){
	vector<int> vis(N + 1, 0);
	int num = 0;

	while(num < N){
		int newNum = -1;
		for(int i = 1; i <= N; ++i){
			if(in_degree[i] == 0){
				newNum = i;
				break;
			}
		}

		if(newNum == -1){
			break;
		}

		vis[newNum] = 1;
		in_degree[newNum] = -1;

		int len = vedge[newNum].size();
		for(int i = 0; i < len; ++i){
			activity tmp = vedge[newNum][i];
			if(tmp.flag){
				if(!vis[tmp.end]){
					--(in_degree[tmp.end]);
				}
			}
		}
		++num;
	}

	if(num == N){
		return true;
	}

	return false;
}
