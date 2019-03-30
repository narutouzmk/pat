#include <iostream>
#include <cstring>

#define MAXS 10

using namespace std;

struct TreeNode{
	char name;
	int lchild;
	int rchild;
};

typedef struct TreeNode Node;

Node tree_a[MAXS];
Node tree_b[MAXS];

int comp(int, int);
int build(Node *);

int main(void){
	int N1, N2;
	
	N1 = build(tree_a);
	N2 = build(tree_b);

	if(comp(N1, N2)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}

int build(Node *t){
	int n, i, check[10] = {0};
	char a, b;
	int root = -1;

	cin >> n;
	if(n){
		for(i = 0; i < n; ++i){
			cin >> t[i].name >> a >> b;
			if(a != '-'){
				t[i].lchild = a - '0';
				check[t[i].lchild] = 1;
			}else{
				t[i].lchild = -1;
			}
			if(b != '-'){
				t[i].rchild = b - '0';
				check[t[i].rchild] = 1;
			}else{
				t[i].rchild = -1;
			}
		}	
		
		for(i = 0; i < n; ++i)
			if(check[i] == 0)
				break;
		root = i;
	}

	return root;
}

int comp(int r1, int r2){
	if(r1 == -1 && r2 == -1 )
		return 1;
	if((r1 == -1 && r2 != -1) || (r1 != -1 && r2 == -1))
		return 0;
	if(tree_a[r1].name != tree_b[r2].name)
		return 0;
	if((tree_a[r1].lchild == -1) && (tree_b[r2].lchild == -1))
		return comp(tree_a[r1].rchild, tree_b[r2].rchild);

	if((tree_a[r1].lchild != -1) && (tree_b[r2].lchild != -1) && (tree_a[tree_a[r1].lchild].name == tree_b[tree_b[r2].lchild].name)){
		return comp(tree_a[r1].lchild, tree_b[r2].lchild)&&comp(tree_a[r1].rchild, tree_b[r2].rchild);
	}else{
		return comp(tree_a[r1].lchild, tree_b[r2].rchild)&&comp(tree_a[r1].rchild, tree_b[r2].lchild);
	}
}
