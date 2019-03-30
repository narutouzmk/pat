#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(ostream &out, vector<T> vec){
	if(vec.size() == 0){
		return;
	}

	out << vec[0];
	for(int i = 1; i < vec.size(); ++i){
		out<<" "<<vec[i];
	}
	out << endl;

	return;
}

int main(){
	vector<string> vec;
	string word;

	while(cin >> word){
		vec.push_back(word);
	}

	reverse(vec.begin(), vec.end());
	printVector(cout, vec);

	return 0;

}
/*int main(void){
	string s;
	int cnt_n = 0, flag = 1, start = 0;
	int i, j;

	getline(cin, s);
	
	for(i = 0; i < s.length(); ++i){
		if(s[i] != ' '){
			start = i;
			break;
		}
	}

	for(i = s.length() - 1; i >= 0; --i){
		if(s[i]!=' '){
			flag = 0;
			++cnt_n;
		}else if(!flag){
			flag = 1;
			for(j = i + 1; j <= i + cnt_n; ++j){
				cout << s[j];
			}
			if(i+1 != start){
				cout << " ";
			}
			cnt_n = 0;
		}
	}

	for(i = start; i < start + cnt_n; ++i){
		cout << s[i];
	}

	cout << endl;

	return 0;
}*/
