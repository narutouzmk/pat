#include <iostream>

using namespace std;

/*并查集
 2019/02/12/思路以每个俱乐部第一个人为基点，之后的人来一个人就把此人作为当前俱乐部并查集基点的根，理解为头插法顺序，后来的反而是树根
 */

int vis[30000+10];//代表每个人
int root[30000+10];//代表结算每个人认识的人

int getRoot(int x){
	if(vis[x] == x)
		return vis[x];
	vis[x] = getRoot(vis[x]);
	return vis[x];
}

void join(int a, int b){
	int x = getRoot(a);
	int y = getRoot(b);
	if(x != y){
		vis[x] = y;
	}
}

int main(void){
	int n, m;
	int x, y, k;
	int maxn = 0;

	cin >> n >> m;

	for(int i = 1; i <= n; ++i){
		vis[i] = i;
	}

	for(int i = 0; i < m; ++i){
		cin >> k >> x;
		for(int j = 1; j < k; ++j){
			cin >> y;
			join(x, y);
		}
	}

	for(int i = 1; i <= n; ++i){
		int t = getRoot(i);
		root[t]++;
		if(root[t] > maxn){
			maxn = root[t];
		}
	}

	cout << maxn << endl;
	return 0;
}
