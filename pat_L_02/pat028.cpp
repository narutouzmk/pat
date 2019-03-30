#include <iostream>
#include <cstdlib>

using namespace std;

struct BiTree{
	int data;
	struct BiTree *lchild, *rchild;
};

typedef struct BiTree *bt;

int N, count = 0;
int num[1009];
int predit = -32766;
int post = 32766;

bt build_tree(bt, int);

int judge_left(bt);
int judge_right(bt);

//void lnr(bt);//test
void lrn(bt);
int main(void){
	int tmp;
	int left = 0, right = 0;
	bt root = NULL;
	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> tmp;
		root = build_tree(root, tmp);
	}

	//lnr(root);//test
	left = judge_left(root);
	right = judge_right(root);

	if(left || right){
		cout << "YES" <<endl;
		lrn(root);
		if(count > 0){
			cout << num[0];
			for(int i = 1; i < count; ++i){
				cout << " " << num[i];
			}
		}
	}else{
		cout << "NO";
	}
	cout << endl;
	return 0;
}

bt build_tree(bt root, int leaf){
	if(root == NULL){
		root = (struct BiTree*)malloc(sizeof(struct BiTree));
		root -> data = leaf;
		root -> lchild = NULL;
		root -> rchild = NULL;
	}else{
		if(root -> data > leaf){
			root -> lchild = build_tree(root -> lchild, leaf);
		}else{
			root -> rchild = build_tree(root -> rchild, leaf);
		}
	}

	return root;
}

int judge_left(bt root){
	if(root == NULL){
		return 1;
	}else{
		int b1, b2;
		b1 = judge_left(root -> lchild);
		if(b1 == 0 || predit > root -> data){
			return 0;
		}
		predit = root -> data;
		b2 = judge_left(root -> rchild);
		return b2;
	}
}

int judge_right(bt root){
	if(root == NULL){
		return 1;
	}else{
		int b1, b2;
		b1 = judge_right(root -> lchild);
		if(b1 == 0 || root -> data > post){
			return 0;
		}
		post = root -> data;
		b2 = judge_right(root -> rchild);
		return b2;
	}
}

void lrn(bt root){
	if(root != NULL){
		lrn(root -> lchild);
		lrn(root -> rchild);
		num[count++] = root -> data;
	}
}

/*void lnr(bt root){
	if(root != NULL){
		lnr(root -> lchild);
		cout << root -> data << " ";
		lnr(root -> rchild);
	}
}*/
