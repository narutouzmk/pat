#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 105;
const int INF = 0x7fffffff;

struct activity{
	int sta;
	int end;
	int cost;
	bool flag;//sta是否是活动的起点
};

vector<vector<activity> > vedge;//某个事件的邻接事件

vector<int> in_degree;//入度
vector<int> out_degree;//出度
vector<int> ve;//事件的最早发生时间
vector<int> vl;//事件的最晚发生时间

vector<activity> vact;//所有的活动
vector<int> l;//活动的最早开始时间
vector<int> e;//活动的最迟开始时间

int n, m;
vector<int> vSta;//入度为0的原点
vector<int> vEnd;//出度为0的终点
int MinTime; //完成时间

bool isTop(vector<int> in_degree);//拓扑排序是否合理
void solve_ve();//事件的最早发生时间
void solve_vl();//事件的最晚发生时间
bool cmp(activity a1, activity a2);//比较两个活动的先后次序

int main(){
	cin >>n >>m;
	vedge.resize(n + 1);
	in_degree.resize(n + 1, 0);
	out_degree.resize(n + 1, 0);
	ve.resize(n + 1, 0);
	vl.resize(n + 1, INF);
	vact.clear();
	l.resize(m + 1);
	e.resize(m + 1);

	activity actTmp;
	
	for(int i = 0; i < m; ++i){
		cin >> actTmp.sta >> actTmp.end >> actTmp.cost;
		
		actTmp.flag = true;
		vact.push_back(actTmp);
		in_degree[actTmp.end]++;
		out_degree[actTmp.sta]++;
		vedge[actTmp.sta].push_back(actTmp);
		actTmp.flag = false;
		vedge[actTmp.end].push_back(actTmp);
	}

	if(!isTop(in_degree)){
		cout<<0<<endl;
		return 0;
	}

	for(int i = 1; i <= n; ++i){
		if(in_degree[i] == 0){
			vSta.push_back(i);
		}
		if(out_degree[i] == 0){
			vEnd.push_back(i);
		}
	}

	solve_ve();

	//完成整个工程需要的时间
	MinTime = 0;
	for(int i = 1; i <= n; ++i){
		if(ve[i] > MinTime){
			MinTime = ve[i];
		}
	}

	solve_vl();

	vector<activity> critical;
	int criLen = 0;
	//l, e求解，并求出关键路径
	for(int i = 0; i < m; ++i){
		l[i] = ve[vact[i].sta];
		e[i] = vl[vact[i].end] - vact[i].cost;

		if(e[i] == l[i]){
			critical.push_back(vact[i]);
			criLen++;
		}
	}

	sort(critical.begin(), critical.end(), cmp);

	cout << MinTime << endl;

	for(int i = 0; i < criLen; ++i){
		cout<< critical[i].sta << "->" << critical[i].end << endl;
	}

	return 0;
}


bool isTop(vector<int> in_degree){
	vector<bool> vis(n + 1, false);

	int num = 0;
	while(num < n){
		int nowNum = -1;
		for(int i = 1; i <= n; ++i){
			if(!vis[i] && in_degree[i] == 0){
				nowNum = i;
				break;
			}
		}

		if(nowNum == -1){
			return false;
		}

		vis[nowNum] = true;
		in_degree[nowNum] = -1;

		int len = vedge[nowNum].size();
		for(int i = 0; i < len; ++i){
			activity tmp = vedge[nowNum][i];
			if(tmp.flag){
				if(vis[tmp.end] == false){
					in_degree[tmp.end]--;
				}
			}
		}

		++num;
	}

	if(num == n)
		return true;
	return false;
}

//求事件最早发生事件
void solve_ve(){
	vector<int>::iterator it = vSta.begin();
	vector<bool> vis(n + 1, false);

	while(it != vSta.end()){
		queue<int> que;
		que.push(*it);
		ve[*it] = 0;
		vis[*it] = true;

		while(!que.empty()){
			int nowNum = que.front();
			que.pop();

			int len = vedge[nowNum].size();
			for(int i = 0; i < len; ++i){
				activity tmp = vedge[nowNum][i];
				if(vis[tmp.end])
					continue;
				if(tmp.flag){
					in_degree[tmp.end]--;
					ve[tmp.end] = max(ve[tmp.end], ve[nowNum] + tmp.cost);
					if(in_degree[tmp.end] == 0){
						que.push(tmp.end);
						vis[tmp.end] = true;
					}
				}
			}
		}

		++it;
	}
}

//求事件的最迟发生时间
void solve_vl(){
	vector<int>::iterator it = vEnd.begin();
	vector<bool> vis(n + 1, false);

	while(it != vEnd.end()){
		int endP = *it;
		vl[endP] = MinTime;
		queue<int> que;
		que.push(endP);

		vis[endP] = true;
		out_degree[endP] = -1;

		while(!que.empty()){
			int nowNum = que.front();
			que.pop();

			int len = vedge[nowNum].size();
			for(int i = 0; i < len; ++i){
				activity tmp = vedge[nowNum][i];
				if(vis[tmp.sta])
					continue;
				if(tmp.flag == false){
					out_degree[tmp.sta]--;
					vl[tmp.sta] = min(vl[tmp.sta], vl[nowNum] - tmp.cost);
					if(out_degree[tmp.sta] == 0){
						vis[tmp.sta] = true;
						que.push(tmp.sta);
					}
				}
			}
		}
		++it;
	}
}


bool cmp(activity a1, activity a2){
	if(a1.sta < a2.sta){
		return true;
	}else if(a1.sta == a2.sta){
		if(a1.end > a2.end){
			return true;
		}
	}

	return false;
}
