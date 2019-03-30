#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode{
	int data;
	struct TreeNode *lchild, *rchild;
};

typedef struct TreeNode Node;

int judge(int *, int *, int);
int build(Node *&, int);//建二叉查找树
int is_SMAE(Node *, Node *);//判断两二叉树是否相等

int main(void){
	int N, L, i;
	int num[10] = {0};
	int test[10] = {0};

	while(cin >> N >> L){
	if(N == 0)
		return 0;

	for(i = 0; i < N; ++i){
		cin >> num[i];//标准二叉树
	}

	while(L > 0){//测试用次数

		for(i = 0; i < N; ++i)
			cin >> test[i];//测试二叉树数组

		if(judge(num, test, N)){
			cout << "Yes" << endl;
		}else{
			cout << "No" <<endl;
		}

		L--;
	}
	}
	return 0;
}

int judge(int *A, int *B, int n){
	Node *r1 = NULL, *r2 = NULL;
	int i;
	
	for(i = 0; i < n; ++i)
		build(r1, A[i]);

	for(i = 0; i < n; ++i)
		build(r2, B[i]);

	return is_SMAE(r1, r2);
}

int build(Node *&root, int key){//建树思路:二叉树指针按引用传值，先找插入位置，再插入
	if(root == NULL){
		root = (Node *)malloc(sizeof(struct TreeNode));
		root -> data = key;
		root -> lchild = NULL;
		root -> rchild = NULL;
		return 1;
	}else if(root -> data == key){
		return 0;
	}else{
		if(root -> data > key){
			return build(root -> lchild, key);
		}else{
			return build(root -> rchild, key);
		}
	}
}

int is_SMAE(Node *r1, Node *r2){//判断两树是否相等
	if(r1 == NULL && r2 == NULL)
		return 1;
	if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
		return 0;
	if(r1 -> data != r2 -> data)
		return 0;
	else{
		return is_SMAE(r1 -> lchild, r2 -> lchild) && is_SMAE(r1 -> rchild, r2 -> rchild);
	}
}
