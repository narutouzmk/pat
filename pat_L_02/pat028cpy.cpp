#include <iostream>
#include <cstdlib>

using namespace std;

int flag = 0, flag1 = 0, flag2 = 0;//flag控制最后一个元素后没有空格
/*
 基本思路:
	1.给定一个二叉树序列，先判断其是否是二叉排序树正序列
		判断方法：第一个值为根节点的值，则从下一个节点开始找到第一个节点值大于根节点值的结点，此节点就是二叉排序树的右子树根节点的值。
		再从该根节点到序列尾端，若存在值小于根节点值的结点，则可以说明该结点不是二叉排序树
	2.再判断该树的镜像，原理同1
	3.递归执行1,2.注意长度的划分。以正序列为例：若是先序序列，且是二叉排序树，只要找到了第一个值大于根节点值的结点，从此节点往后均为右子树。
 */
struct BiTree{
	int data;
	struct BiTree *lchild;
	struct BiTree *rchild;
};

typedef struct BiTree *bt;

void Printf(bt);
bt Find(int *, int);
bt FindMirror(int *, int);

int main(void){
	int n;
	int pre[1005];

	bt tl, tr;

	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> pre[i];
	}

	tl = Find(pre, n);
	tr = FindMirror(pre, n);

	if(tl && !flag1){
		cout << "YES" << endl;
		Printf(tl);
		cout << endl;
	}else if(tr && !flag2){
		cout << "YES" << endl;
		Printf(tr);
		cout << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}

bt Find(int *pre, int len){//pre按指针传递，所以i = 1代表当前指针的下一个位置
	int i, j;
	if(len == 0){
		return NULL;
	}

	bt root = (bt)malloc(sizeof(struct BiTree));
	root -> data = *pre;
	root -> lchild = NULL;
	root -> rchild = NULL;

	for(i = 1; i < len; ++i){
		if(pre[i] >= root -> data){
			break;
		}
	}

	for(j = i; j < len; ++j){
		if(pre[j] < root -> data){
			flag1 = 1;
			return NULL;
		}
	}

	root -> lchild = Find(pre+1, i - 1);
	root -> rchild = Find(pre + i, len - i);

	return root;
}

bt FindMirror(int *pre, int len){
	if(len == 0){
		return NULL;
	}

	int i, j;
	bt root = (bt)malloc(sizeof(struct BiTree));
	root -> data = *pre;
	root -> lchild = NULL;
	root -> rchild = NULL;

	for(i = 1; i < len; ++i){
		if(root -> data > pre[i]){
			break;
		}
	}

	for(j = i; j < len; ++j){
		if(pre[j] >= root -> data ){
			flag2 = 1;
			return NULL;
		}
	}

	root -> lchild = FindMirror(pre+1, i - 1);
	root -> rchild = FindMirror(pre + i, len - i);
	return root;
}

void Printf(bt root){
	if(root){
		Printf(root -> lchild);
		Printf(root -> rchild);
		if(!flag){
			flag = 1;
			cout << root -> data;
		}else{
			cout << " " << root -> data;
		}
	}
}
