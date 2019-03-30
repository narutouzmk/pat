#include <iostream>

using namespace std;

#define MAXS 20006

int num[MAXS];

void build_heap(int *, int);
//void modify(int *, int, int);
void print_road(int *, int);
void modify(int, int);

int main(void){
	int N, M, i;
	//int num[MAXS] = {10001};
	int ptr[MAXS] = {0};

	cin >> N >> M;
	for(i = 1; i <= N; ++i)
		cin >> num[i];

	for(i = 1; i <= M; ++i)
		cin >> ptr[i];
	
/*	cout<<"之前"<<endl;
	for(i = 1; i <= N; ++i)
		cout << num[i] << " ";
	cout<<endl;*/ //debug
	
	build_heap(num, N);

	i = 1;
	while(M > 0){
		print_road(num, ptr[i]);
		++i;
		--M;
	}
	
	/*cout<<"之后"<<endl;
	for(i = 1; i <= N; ++i)
		cout << num[i] << " ";
	cout<<endl;*/ //debug

	return 0;
}

void build_heap(int *A, int n){
	int i, a;
	for(i = 1; i <= n; ++i){
		modify(A[i], i);
	}
}

/*void modify(int *A, int left, int right){
	int i, j, tmp;
	i = left;
	j = i * 2;
	tmp = A[i];
	while(j < right){
		if(j < right && A[j] > A[j+1]){
			++j;
		}
		if(tmp > A[j]){
			A[i] = A[j];
			i = j;
			j = j * 2;
		}else{
			break;
		}
	}

	A[i] = tmp;
}*/
void modify(int var, int n){
	while(var < num[n/2] && n/2 > 0){
		num[n] = num[n/2];
		n /= 2;
	}
	num[n] = var;
}

void print_road(int *A, int n){

	//cout<<"road:"<<endl;
	cout << A[n];
	n = n / 2;
	while(n){
		cout << " " << A[n];
		n /= 2;
	}
	cout<<endl;
}
