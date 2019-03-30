#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

map<string, int> mp;
int N;
void deal(string s, map<string, int> &mp);
int main(void){
	int count = 0, maxn = -1;
	string re;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		string tmp;
		getline(cin, tmp);
		deal(tmp, mp);
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it -> second > maxn){
			maxn = it -> second;
		}
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it -> second >= maxn){
			re = it -> first;
			break;
		}
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it -> second == maxn){
			++count;
		}
	}
	int flag = 0;
	for(int i = 0; i < re.size(); ++i){
		if(!flag){
			char c;
			c = toupper(re[i]);
			cout << c;
			flag = 1;
		}else{
			cout << re[i];
		}
	}
	cout << endl << maxn << endl;
	if(count > 0){
		cout << "And " << count << " more" << endl;
	}

	return 0;

}

void deal(string s, map<string, int> &mp){
	for(int i = s.size() - 1; i >= 0; --i){
		if(s[i] == '#'){
			s.erase(i , s.size());
			break;
		}
	}

	s.push_back('#');

	while(s.size() != 1){
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '#'){
				s.erase(0, i + 1);
				break;
			}else if(i == s.size() - 1){
				s.erase(0, s.size() - 1);
			}
		}

		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '#'){
				string tmp = s.substr(0, i);
				mp[tmp]++;
				s.erase(0, i);
				break;
			}else if(!isalpha(s[i])){
				continue;
			}else{
				s[i] = tolower(s[i]);
			}
		}
	}
}
