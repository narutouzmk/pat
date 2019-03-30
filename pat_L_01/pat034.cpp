#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*int C, NUM[11];

template <typename T>
void printVector(ostream &out, vector<T> vec){
	if(vec.size() == 0){
		cout << "Not Fount" << endl;
		return;
	}

	for(int i = 0; i < C; ++i){
		if(NUM[i] > vec.size()){
			out << "Not Found" <<endl;
		}else{
			out << vec[NUM[i]] << endl;
		}
	}
}

int main(){
	string word;
	vector<string> vec;

	int N;
	cin >> N;
	cin.get();//读取一个字符
	while(N > 0){
		getline(cin, word);
		vec.push_back(word);
		--N;
	}

	cin >> C;
	for(int i = 0; i < C; ++i){
		cin >> NUM[i];
	}

	printVector(cout, vec);

	return 0;
}*/

typedef struct Info{
	char name[11];
	char birthday[11];
	char sex;
	char phoneNumber[17];
	char mobileNumber[17];
}Info;

void input(Info info[], int m);
void output(Info info[], int m);

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	Info info[n];
	input(info, n);
	output(info, n);

	return 0;
}


void input(Info info[], int n){
	int i;
	for(i = 0; i < n; ++i){
		scanf("%s %s %c %s %s", info[i].name, info[i].birthday, &info[i].sex, info[i].phoneNumber, info[i].mobileNumber);
		getchar();
	}
}

void output(Info info[], int n){
	int m, j;

	scanf("%d", &m);
	getchar();

	int a[m];

	for(j = 0; j < m; ++j){
		scanf("%d", &a[j]);
		getchar();
	}

	for(j = 0; j < m; ++j){
		if(a[j] >= 0 && a[j] < n){
			printf("%s %s %s %c %s\n", info[a[j]].name, info[a[j]].phoneNumber, info[a[j]].mobileNumber, info[a[j]].sex, info[a[j]].birthday);
		}else{
			printf("Not Found\n");
		}
	}
}
