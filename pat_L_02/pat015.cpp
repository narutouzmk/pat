#include <iostream>
#include <map>
#include <cstring>

using namespace std;

map<string, string> mp;
map<string, int> p;

int N;

//version 1.2
int main(void){
	string qq_num;
	string qq_pas;
	char ins;

	cin >> N;
	
	while(N--){
		cin >> ins >> qq_num >> qq_pas;
		if(ins == 'L'){
			if(mp[qq_num].empty()){
				cout << "ERROR: Not Exist" << endl;
			}else{
				if(mp[qq_num] == qq_pas){
					cout << "Login: OK" << endl;
				}else{
					cout <<"ERROR: Wrong PW" << endl;
				}
			}
		}

		if(ins == 'N'){
			if(!mp[qq_num].empty()){
				cout << "ERROR: Exist" << endl;
			}else{
				mp[qq_num] = qq_pas;
				cout << "New: OK" << endl;
			}
		}
	}
}

//version 1.1
/*int main(void){
	string qq_num;
	string qq_pas;
	char ins;
	
	map<string, string>::iterator it;
	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> ins >> qq_num >> qq_pas;
		if(ins == 'L'){
			if(p[qq_num] == 1){
				if(mp[qq_num] == qq_pas){
					cout <<"Login: OK" << endl;
				}else{
					cout <<"ERROR: Wrong PW" << endl;
				}
			}else{
				cout << "ERROR: Not Exist" << endl;
			}
		}

		if(ins == 'N'){
			if(p[qq_num] == 1){
				cout << "ERROR: Exist" << endl;
			}else{
				p[qq_num] = 1;
				mp[qq_num] = qq_pas;
				cout << "New: OK" << endl;
			}
		}
	}
	return 0;
}*/ //version 1.1

