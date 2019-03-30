#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <cctype>
using namespace std;

int N, M;
set<string> Set[1010];

void deal(string st, set<string> &const_set);
int main(void){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		while(true){
			string s;
			cin >> s;
			if(s == "#" && s.size() == 1)
				break;
			deal(s, Set[i]);
		}
	}

	scanf("%d", &M);

	for(int i = 0; i < M; ++i){
		int count = 0, a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		//printf("执行\n");
		for(set<string>::iterator it = Set[a].begin(); it != Set[a].end(); ++it){
			if(Set[b].count(*it) != 0){
				++count;
			}
		}
		//printf("count=%d\n", count);
		printf("%.1f%%\n", count * 100.0 / ( Set[a].size() + Set[b].size() - count));
	
	}
	return 0;
}

void deal(string st, set<string> &const_set){
	//printf("执行\n");
	for(int i = st.size() - 1; i >= 0; --i){
		if(isalpha(st[i])){
			st.erase(i + 1, st.size());
			break;
		}
	}

	st.push_back('0');//哨兵

	while(st.size() > 1){
		for(int i = 0; i < st.size(); ++i){
			if(isalpha(st[i])){
				st.erase(0, i);
				break;
			}else if(i == st.size() - 1){
				st.erase(0, i);//跳出while循环
				break;
			}
		}

		for(int i = 0; i < st.size(); ++i){
			if(!isalpha(st[i])){
				string tmp = st.substr(0, i);
				if(i >= 10){
					tmp = tmp.substr(0, 10);
				}
				if(i >= 3){
					const_set.insert(tmp);
				}
				st.erase(0, i);
				break;
			}else{
				st[i] = tolower(st[i]);
			}
		}
	}

/*	for(set<string>::iterator it = const_set.begin(); it != const_set.end(); ++it){
		cout << *it <<" ";
	}
	cout << endl;*/
	return;
}
