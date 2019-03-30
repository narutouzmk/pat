#include<iostream>
#include<string>
#include <map>
using namespace std;

map<int, string> mp;

int main(void){
	string op, msg;
	int N, priority;

	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> op;
		if(op == "PUT"){
			cin >> msg >> priority;
			mp.insert(pair<int, string>(priority, msg));
		}else if(op == "GET"){
			if(mp.size()){
				map<int, string>::iterator it = mp.begin();
				cout << it -> second << endl;
				mp.erase(it -> first);
			}else{
				cout << "EMPTY QUEUE!" << endl;
			}
		}
	}

	return 0;
}
