#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define MAX 0x3f3f3f3f 

struct activity{
	int sta;
	int end;
	int cost;
	bool flag;//判断该点是起点还是终点
};

vector<vector<activity> > vedge;//邻接链表
vector<activity> vact;//记录每个活动

vector<int> in_degree;//记录结点入度
vector<int> out_degree;//记录结点出度
vector<int> vSta;//记录入度为0的点
vector<int> vEnd;//记录出度为0的点

vector<int> l;//记录每个活动的最晚开始时间
vector<int> e;//记录每个活动的最早开始时间
vector<int> ve;//记录事件最早开始时间
vector<int> vl;//记录事件的最迟发生时间

int N, M;//结点个数和边数
int minTime; //完成整个项目所需的时间

bool isTop(vector<int> in_degree);//拓扑判断
void solve_ve();//求活动的最早发生时间
void solve_vl();//求活动的最迟发生时间
void cmp(activity a1, activity a2);//用于计算关键路径顺序

int main(void){
	cin >> N >> M;
	vedge.resize(N + 1);
	vact.clear();
	in_degree.resize(N + 1, 0);
	out_degree.resize(N + 1, 0);
	ve.resize(N + 1, 0);
	vl.resize(N + 1, MAX);
	e.resize();
	l.resize();

	activity tmp;
	for(int i = 0; i < M; ++i){
		cin >> tmp.sta >> tmp.end >> tmp.cost;
		tmp.flag = true;
		vact.push_back(tmp);
		vedge[tmp.sta].push_back(tmp);
		tmp.flag = false;
		vedge[tmp.end].push_back(tmp);
		out_degree[tmp.sta]++;
		in_degree[tmp.end]++;
	}

	if(!isTop(in_degree)){
		cout << 0 << endl;
		return 0;
	}

	for(int i = 1; i <= N; ++i){
		if(in_degree[i] == 0){
			vSta.push_back(in_degree[i]);
		}
		if(out_degree[i] == 0){
			vEnd.push_bach(out_degree[i]);
		}
	}

	solve_ve();
	minTime = 0;

	for(int i = 1; i <= N; ++i){
		if(ve[i] > minTime){
			minTime = ve[i];
		}
	}

	solve_vl();

	vector<activity> critical;
	int criLen = 0;
	for(int i = 0; i < m ++i){
		e[i] = ve[vact[i].sta];
		l[i] = vl[vact[i].end] - vact[i].cost;

		if(e[i] == l[i]){
			critical.push_back(vact[i]);
			++criLen;
		}
	}
}
