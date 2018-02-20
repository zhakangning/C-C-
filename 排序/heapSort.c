#include <stdio.h>
#include <stdlib.h>


typedef struct btree{
	int data;
	struct btree *left,*right;
}BTREE;

//把数组元素放入二叉树
BTREE *createTree(int *a, int n)
{
	
	if(n==0){
		return NULL;
	}
	BTREE *root=(BTREE *)malloc(sizeof(BTREE));
	root->data=*a;
	root->left=createTree(a+1,n/2);
	root->right=createTree(a+1+n/2,n-n/2-1);
	return root;
}

void preVisit(BTREE *r)
{
	if(NULL==r)
		return ;
	
	printf("%d ",r->data);
	preVisit(r->left);
	preVisit(r->right);
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	BTREE *root=createTree(a, sizeof(a)/sizeof(*a));
	preVisit(root);
	printf("\n");
	return 0;
}

