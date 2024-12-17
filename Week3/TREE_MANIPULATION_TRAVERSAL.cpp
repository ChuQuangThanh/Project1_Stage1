#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	int id;
	Node* leftMostChild; // con tro tro den nut con trai nhat
	Node* rightSibling; // con tro tro dne nut anh em ben phai giong kieu p -> next kieu the
}Node;
Node* root; // con tro toi nut goc

Node* makeNode(int v)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p -> id = v; p -> leftMostChild = NULL ; p -> rightSibling = NULL;
	return p;
}
Node *find(int v , Node * r)
{
	//tim nut co dinh danh la id tren cay co goc r
	if (r == NULL) return NULL;
	if (r -> id == v) return r;
	Node* p = r -> leftMostChild;
	while(p != NULL){
		Node *h = find(v, p);
		if (h != NULL) return h;
		p = p -> rightSibling;
	}
	return NULL;
}

void insert(int u , int v)
{
	// tao 1 cay co nut la u , chen vao danh sach nut con cua nut co id =  v
	//
	Node *r = find(v ,  root);
	Node *p = find(u , root);
	if (p != NULL) return;
	p = makeNode(u);
	if (r -> leftMostChild == NULL)
	   r -> leftMostChild = p;
	else
	{
	    Node* h = r -> leftMostChild;
		while (h -> rightSibling != NULL)
		    h = h -> rightSibling;
		h -> rightSibling = p;
	}
}

void printTree(Node *r)
{
     if (r == NULL) return;
	 printf("%d ",r -> id);
	 for (Node *p = r -> leftMostChild ; p != NULL ; p = p -> rightSibling)
	 printf("%d ",p -> id);
	 printf("\n");
	 for (Node *p = r -> leftMostChild ; p != NULL ; p = p -> rightSibling)
	 printTree(p);
}

void preOrder(Node *r)
{
	if (r == NULL) return;
	printf("%d ",r -> id);
	Node *p = r -> leftMostChild;
	while (p != NULL){
		preOrder(p);
		p = p -> rightSibling;
	}
}

void inOrder(Node *r)
{
	if (r == NULL) return;
	Node *p = r -> leftMostChild;
	inOrder(p);
	printf("%d ",r -> id);
	if (p != NULL)
	    p = p -> rightSibling;
	while (p != NULL){
		inOrder(p);
		p = p -> rightSibling;
	}
}
void postOrder(Node *r)
{
	if (r == NULL) return;
	Node *p = r -> leftMostChild;
	while (p != NULL){
		postOrder(p);
		p = p -> rightSibling;
	}
	printf("%d ",r -> id);
}

int countLeaves(Node *r)
{
	if (r == NULL) return 0;
	int s = 0;
	Node * p = r -> leftMostChild;
	if (p == NULL) s = 1;
	while (p != NULL)
	{
		s += countLeaves(p);
		p = p -> rightSibling;
	}
	return s;
}

int height(Node *p)
{
	if (p == NULL) return 0;
	int maxh = 0;
	Node *q = p -> leftMostChild;
	while (q != NULL){
		int h = height(q);
		if (h > maxh) maxh = h;
		q = q -> rightSibling;
	}
	return maxh + 1;
}

int depth(Node *r , int v , int d){
	// d la do sau cua mut r
	if (r == NULL) return -1;
	if (r -> id == v) return d;
	Node* p = r -> leftMostChild;
	while (p != NULL){
		if (p -> id == v) return d + 1;
		int dv = depth(p , v ,d + 1);
		if (dv > 0) return dv;
		p = p -> rightSibling;
	}
	return -1;
}

int depth(Node *r , int v){
	return depth(r ,v ,1);
}

Node *parent(Node *p , Node *r){
	if (r == NULL) return NULL;
	Node *q = r -> leftMostChild;
	while (q != NULL)
	{
		if (p == q) return r;
		Node *pp = parent(p , q);
		if (pp != NULL) return pp;
		q = q -> rightSibling;
	}
	return NULL;
}

int count(Node *r)
{
	if (r == NULL) return 0;
	int i = 1;
	Node *p = r -> leftMostChild;
	while (p != NULL)
	{
		i += count(p);
		p = p -> rightSibling;
	}
	return i;
}

int main()
{
	char cmd[50];
	while (1)
	{
		scanf("%s",cmd);
		if (strcmp(cmd , "MakeRoot") == 0)
		{
			int v; scanf("%d",&v);
			root = makeNode(v);
		}
		if (strcmp(cmd , "Insert") == 0)
		{
			int u , v ; scanf("%d%d",&u,&v);
			insert(u ,v);
		}
		if (strcmp(cmd , "InOrder") == 0)
		{
			inOrder(root);
			printf("\n");
		}
		if (strcmp(cmd , "PreOrder") == 0)
		{
			preOrder(root);
			printf("\n");
		}
		if (strcmp(cmd , "PostOrder") == 0)
		{
			postOrder(root);
			printf("\n");
		}
		if (strcmp(cmd , "*") == 0)
		break;
	}
// 	printTree(root);
	//printf("Count = %d CountLeaves = %d ",count(root),countLeaves(root));
	return 0;
}
