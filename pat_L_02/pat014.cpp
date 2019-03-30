#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int N;

map<string, int> mp;

int main(void){
	int maxn = -999, maxnnum = 0;
	string st1, st2;
	string ansst;

	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> st1 >> st2;
		mp[st1]++;
		mp[st2]++;
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it -> second > maxn){
			maxn = it -> second;
			ansst = it -> first;
		}
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it -> second == maxn){
			++maxnnum;
		}
	}

	cout << ansst << " " << maxn;
	if(maxnnum > 1){
		cout << " " << maxnnum << endl;
	}else{
		cout <<endl;
	}

	return 0;
}

/*vector<string> phoNum;

int main(void){

	int count = 1, min = 0;;
	cin >> N;
	string s, m;
	for(int i = 1; i <= N * 2; ++i){
		cin >> s;
		phoNum.push_back(s);
		cout << s << endl;
	}

	cout << endl;

	sort(phoNum.begin(), phoNum.end());

	for(vector<string>::iterator it = phoNum.begin(); it != phoNum.end(); ++it){
		cout << *it << endl;
	} //test
	cout << endl;

	vector<string>::iterator it = phoNum.begin();
	++it;
	for(; it != phoNum.end(); ++it){
		if(*(it - 1) != *(it)){
			if(count > min){
				min = count;
				count = 1;
				m = *(it - 1);
			}
		}else{
			++count;
		}
	}

	cout << m << " " << min << endl;
	return 0;
}*/
