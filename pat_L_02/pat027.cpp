#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#define mst(a) memset(a, 0, sizeof(a));

using namespace std;

/*
 parent (直系)父
 child (直系)孩子
 ancestor 祖先
 sibling 同辈
 descendant 后裔
 */

const int maxn = 100 + 5;
string s;
map<string, int> maps;
int a[maxn], fa[maxn];
vector<int> vec[maxn];

bool dfs(int a, int b){
	if(vec[a].size() == 0){
		return false;
	}
	for(size_t i = 0; i < vec[a].size(); ++i){
		if(vec[a][i] == b)
			return true;
		if(dfs(vec[a][i], b))
			return true;
	}

	return false;
}

bool solve(string stra, string strb, char ch){
	int a = maps[stra], b = maps[strb];
	switch(ch){
		case 'p':
			return a == fa[b];
			break;
		case 'c':
			return fa[a] == b;
			break;
		case 'a': 
			return dfs(a, b);
			break;
		case 's': 
			return fa[a] == fa[b];
			break;
		case 'd':
			return dfs(b, a);
			break;
	}
}

int main(void){
	int n, test, cnt = 0;
	cin >> n >> test;
	getchar();
	while(n--){
		string name = "";
		s = "";
		getline(cin, s);
		int len = (int)s.size();
		int k = 0;
		for(int i = 0; i < len; ++i){
			if(s[i] != ' ')
				name += s[i];
			else
				k++;
		}

		k /= 2;
		maps[name] = cnt++;
		int id = maps[name];
		if(k != 0){
			vec[a[k]].push_back(id);
			fa[id] = a[k];
		}else{
			fa[id] = -1;
		}
		a[k+1] = id;
	}

	while(test--){
		string n1, n2, n3, temp;
		cin >> n1 >> temp >> temp >> n2 >> temp >> n3;
		if(solve(n1, n3, n2[0]))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}

	return 0;
}
