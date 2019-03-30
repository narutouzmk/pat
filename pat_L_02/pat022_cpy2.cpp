#include <iostream>

using namespace std;

#define MAXS 1000

int main(void){
	int st1[MAXS], st2[MAXS];
	int N1, N2, top1, top2, data;
	char op;
	top1 = 0;
	top2 = 0;
	cin >> N1 >> N2;
	if(N1 > N2){
		int tmp = N1;
		N1 = N2;
		N2 = tmp;
	}

	while(true){
		cin >> op;
		if(op == 'A'){
			cin >> data;
			if(top1 < N1){
				st1[++top1] = data;
			}else if((top1 == N1) && (top2 == 0)){
				while(top1 > 0){
					st2[++top2] = st1[top1];
					--top1;
				}
				st1[++top1] = data;
			}else{
				cout << "ERROR:Full" <<endl;
			}
		}else if(op == 'D'){
			if(top2 > 0){
				cout << st2[top2--] << endl;
			}else if(top2 == 0 && top1 > 0){
				while(top1 > 0){
					st2[++top2] = st1[top1];
					--top1;
				}
				cout << st2[top2--] << endl;
			}else{
				cout << "ERROR:Empty" << endl;
			}
		}else if(op == 'T'){
			break;
		}
	}

	return 0;
}
