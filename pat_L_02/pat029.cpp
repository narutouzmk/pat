#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

#define MAXS 10005

int main(void){
	int N, a;

	int sum = 0;

	while(!pq.empty())
		pq.pop();

	cin >> N;
	while(N--){
		cin >> a;
		pq.push(a);
	}

	while(pq.size() > 1){
		int i = pq.top();
		pq.pop();
		int j = pq.top();
		pq.pop();

		sum += i + j;

		pq.push( i + j);
	}

	cout << sum << endl;
	return 0;
}
