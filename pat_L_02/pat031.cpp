#include <iostream>
#include <limits.h>
#include <cstdlib>

using namespace std;

#define MAXS 1001

struct BiTree{
	int k1, k2;
	int l, r;
};

typedef struct BiTree *bt;

bt tree[MAXS];
int N;
int mind = 0xc0c0c0c0;

bt getRoot(bt tree[]);
int judge1(bt root);
int judge2(bt root);

int main(void){
	int a, b, c, d;
	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> a >> b >> c >> d;
		tree[i] = (bt)malloc(sizeof(struct BiTree));
		tree[i] -> k1 = a;
		tree[i] -> k2 = b;
		tree[i] -> l = c;
		tree[i] -> r = d;
	}

	bt root = getRoot(tree);

//	cout << root -> k1 << " ," << root -> k2 << endl;//test
//	cout << judge1(root) << endl;//test
	if(root && judge1(root) && judge2(root)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}

bt getRoot(bt tree[]){
	int child[MAXS] = {0};
	bt root = NULL;
	for(int i = 0; i < N; ++i){
		if(tree[i] -> l != -1){
			child[tree[i] -> l] = 1;
		}


		if(tree[i] -> r != -1){
			child[tree[i] -> r] = 1;
		}
	}

	for(int i = 0; i < N; ++i){
		if(child[i] == 0){
			root = tree[i];
		}
	}

	return root;
}

int judge1(bt root){
	int b1 = 1, b2 = 1;
	if(root -> l == -1 && root -> r == -1){
		if(mind < root -> k1){
//			cout << "leaf:k1 = " <<root -> k1 << ",b=1" << endl;//test  
			mind = root -> k1;
			return 1;
		}
//		cout << "leaf:k1=" << root -> k1 << ",b=0" << endl;//test 
		return 0;
	}else{
//		cout << "node:k1=" << root -> k1 << endl;//test
		if(root -> l != -1){
			b1 = judge1(tree[root -> l]);
//			cout << "lchild:k1=" << tree[root -> l] -> k1 << ",b1=" << b1 << endl;
		}
		//cout << "node:k1=" <<root -> k1 << ",b1=" << b1 << endl;//test
		if(b1 == 0 || mind > root -> k1){
			return 0;
		}
		mind = root -> k1;
		if(root -> r != -1){
			b2 = judge1(tree[root -> r]);
//			cout << "rchild:k1=" << tree[root -> r] -> k1 << ",b2=" << b2 << endl;//test
		}
//		cout << endl;
		return b2;
	}
}

int judge2(bt root){
	bt que[MAXS];
	int front = -1, rear = -1;
	que[++rear] = root;

	while(front != rear){
		bt tmp = que[++front];
		int p = tmp -> k2;
		if(tmp -> l != -1){
			if(tree[tmp -> l] -> k2 < p){
				return 0;
			}else{
				que[++rear] = tree[tmp -> l];
			}
		}

		if(tmp -> r != -1){
			if(tree[tmp -> r] -> k2 < p){
				return 0;
			}else{
				que[++rear] = tree[tmp -> r];
			}
		}
	}

	return 1;
}



















