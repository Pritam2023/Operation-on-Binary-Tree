#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node* create();
void inorderTraversal(struct node* root);
void preorder(struct node *root);
void postorder(struct node *root);
int leafnode(struct node *root);
int nonleafnode(struct node *root);
int totalnode(struct node *root);
int height(struct node *root);
void mirrorimage(struct node *root);
main()
{
	struct node *root;
	int c,d,e,f;
	root=NULL;
	root=create();
	printf("Inorder Traversal:\n");
	inorderTraversal(root);
	printf("\npreorder Traversal:\n");
	preorder(root);
	printf("\npostorder Traversal:\n");
	postorder(root);
	c=leafnode(root);
	d=nonleafnode(root);
	e=totalnode(root);
	f=height(root);
	printf("\nleafnode:%d\n non-leafnode:%d\n total node:%d\n height of the tree:%d",c,d,e,f);
	mirrorimage(root);
	printf("Mirror image of this tree is:\n");
	printf("Inorder ,preorder and post order Traversal is:\n");
	inorderTraversal(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}
struct node* create()
{
	int x;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter -1 to stop or enter the data to insert:");
	scanf("%d",&x);
	if(x==-1)
	return 0;
	newnode->data=x;
	printf("Enter the data of right node of %d\n",x);
	newnode->right=create();
	printf("Enter the data of left node of %d\n",x);
	newnode->left=create();
	return newnode;
}
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->data);
  inorderTraversal(root->right);
}
void preorder(struct node *root){
	if(root==NULL)
	return;
	printf("%d->",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root){
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d->",root->data);
}
int leafnode(struct node *root){
	if(root==NULL)
	return 0;
	else if(root->left==NULL && root->right==NULL)
	return 1;
	else
	return (leafnode(root->left)+leafnode(root->right));
}
int nonleafnode(struct node *root)
{
	if(root==NULL || root->left==NULL && root->right==NULL)
	return 0;
	else
	return(nonleafnode(root->left)+nonleafnode(root->right)+1);
}
int totalnode(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	return(totalnode(root->left)+totalnode(root->right)+1);
}
int height(struct node *root)
{
	int lheight,rheight;
	if(root==NULL)
	return 0;
	else
	{
		lheight=height(root->left);
		rheight=height(root->right);
	}
	if(lheight>rheight)
	return ++lheight;
	else
	return ++rheight;
}
void mirrorimage(struct node *root)
{
	if(root!=NULL)
	{
		mirrorimage(root->left);
		mirrorimage(root->right);
		struct node *temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
	return;
}
