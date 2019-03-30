#include <iostream>
#include <stack>

using namespace std;

int main(void){
	stack<int> st1;//输入
	stack<int> st2;//输出
	int N1, N2, tmp;

	cin >> N1 >> N2;
	if(N1 > N2){
		tmp = N1;
		N1 = N2;
		N2 = tmp;
	}

	int data;
	char op;
	while(true){
		cin >> op;
		if(op == 'A'){
			cin >> data;
			if(st1.size() < N1){
				st1.push(data);
			}else if(st1.size() == N1 && st2.empty()){
				while(!st1.empty()){
					st2.push(st1.top());
					st1.pop();
				}
				st1.push(data);
			}else{
				cout << "ERROR:Full" << endl;
			}
		}else if(op == 'D'){
			if(!st2.empty()){
				cout << st2.top() << endl;
				st2.pop();
			}else if(!st1.empty()){
				while(!st1.empty()){
					st2.push(st1.top());
					st1.pop();
				}
				cout << st2.top() << endl;
				st2.pop();
			}else{
				cout << "ERROR:Empty" << endl;
			}
		}else if(op == 'T'){
			break;
		}
	}

	return 0;
}
