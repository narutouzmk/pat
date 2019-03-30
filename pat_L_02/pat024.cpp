#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

map<string ,int> mp;

int main(void){
	int N, count;
	double percent;
	string s;
	cin >> N;
	count = N;
	cin.get();
	while(count > 0){
		getline(cin, s);
		mp[s]++;
		--count;
	}

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		count = it -> second;
		percent =  count / (double)N * 100;
		cout << it -> first << " " << fixed << setprecision(4) << percent << "%" <<endl;
	}

	return 0;
}
