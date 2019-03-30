#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAXS 100000

using namespace std;

/*int main(void){
	int a[MAXS], N;
	int curmax, thismax;
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin>>a[i];	
	}

	curmax = 0;
	thismax = 0;
	for(int i = 0; i < N; ++i){
		thismax += a[i];
		if(thismax > curmax){
			curmax = thismax;
		}

		if(thismax < 0){
			thismax = 0;
		}
	}

	cout << curmax << endl;
	return 0;
}*/

int maxS(int *, int, int);

int main(void){
	int a[MAXS], N;
	int maxsum = 0;

	cin>>N;

	for(int i = 0; i < N; ++i){
		cin >> a[i];
	}

	maxsum = maxS(a, 0, N-1);

	cout << maxsum <<endl;

	return 0;
}

int maxS(int *a, int left, int right){
	
	if(left >= right){
		return a[left];
	}

	int mid = left + (right - left) / 2;
	int leftmax = maxS(a, left, mid);
	int rightmax = maxS(a, mid+1, right);

	int curmax = 0;
	int midmax = 0; 
	for(int i = mid; i >= left; --i){
		curmax += a[i];
		if(curmax > midmax){
			midmax = curmax;
		}
	}
	curmax = midmax;

	for(int i = mid + 1; i <= right; ++i){
		curmax += a[i];
		if(curmax > midmax){
			midmax = curmax;
		}
	}

	int max = leftmax > midmax ? leftmax : midmax;
	max = max > rightmax ? max : rightmax;

	return max;
}



