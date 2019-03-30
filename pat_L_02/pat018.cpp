#include <iostream>

using namespace std;

#define MAXS 1000

int main(void){
	int que_A[MAXS] = {0};
	int front_A = -1, rear_A = -1;

	int que_B[MAXS] = {0};
	int front_B = -1, rear_B = -1;

	int N, a, count;
	cin >> N;
	while(N > 0){
		cin >> a;
		if(a % 2 == 0){
			++rear_B;
			que_B[rear_B] = a;
//			cout << "que_B["<< rear_B <<"]=" << que_B[rear_B] <<",rear_B=" << rear_B << ",a=" << a <<endl; test
		}else{
			++rear_A;
			que_A[rear_A] = a;
//			cout << "que_A["<< rear_A <<"]=" << que_A[rear_A] <<",rear_A=" << rear_A << ",a=" << a <<endl; test
		}

		--N;
	}

	count = 0;

	for(int i = 0; i < 1; ++i){
		if(front_A != rear_A){
			++front_A;
			cout<< que_A[front_A];
			++count;
//			flag = 1;
		}
	}

	if(front_A == rear_A && front_B != rear_B){
		++front_B;
		cout << que_B[front_B];
	}

	while(rear_A != front_A && rear_B != front_B){
		if(count < 2){
			++front_A;
			cout << " " <<que_A[front_A];
			++count;
		}else{
			count = 0;
			++front_B;
			cout<< " " << que_B[front_B];
		}
	}

	while(rear_A != front_A){
		++front_A;
		cout << " " << que_A[front_A];
	}

	while(rear_B != front_B){
		++front_B;
		cout << " " << que_B[front_B];
	}

	cout << endl;

	return 0;

}
