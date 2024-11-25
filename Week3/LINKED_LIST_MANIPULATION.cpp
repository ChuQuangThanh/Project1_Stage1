#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

Node *first = NULL;
Node *MakeNode(int x)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p -> value = x ; p -> next = NULL;
	return p;
}

int check(Node *h,int x)
{
    Node *p = h;
	while (p != NULL){
    	if (p -> value == x) return 1;
    	p = p -> next;
	}
	return 0;
}

void printList(Node *h)
{
	Node *p = h;
	while (p != NULL)
	{
		printf("%d ",p ->value);
		p = p -> next;
	}
}

Node *addlast(Node *h , int v)
{
	Node *p = MakeNode(v);
	if (h == NULL) return p;
	if (check(h,v)) return h;
	Node *q = h;
	while (q -> next != NULL) q = q -> next;
	q -> next = p;
	return h;
}

Node *addfirst(Node *h , int v)
{
	Node *p = MakeNode(v);
	if (h == NULL) return p;
	if (check(h,v)) return h;
	Node *q = h;
	p -> next = q;
	return p;
}

Node *addbefore(Node *h , int u , int v)
{
	//chen node co gia tri x = u vao trc x = v
	Node *p = MakeNode(u);
	Node *q = h;
	if (h == NULL) return NULL;
	if (check(h,u) || !check(h,v)) return h;
	if (h -> value == v) addfirst(h , u);
	while (q != NULL)
	{
		if (q -> next -> value == v)
		{
			p -> next = q -> next;
			q -> next = p;
			break;
		}
		q = q -> next;
	}
	return h;
}

Node *addafter(Node *h , int u , int v)
{
	//chen node co gia tri x = u vao sau x = v
	Node *p = MakeNode(u);
	Node *q = h;
	if (h == NULL) return NULL;
	if (check(h,u) || !check(h,v)) return h;
	while (q != NULL)
	{
		if (q -> value == v)
		{
			p -> next = q ->next;
			q -> next = p;
			break;
		}
		q = q -> next;
	}
	return h;
}

Node *removeNode(Node *h , int u)
{
	Node *p = h;
	if (h == NULL) return NULL;
	if (!check(h , u)) return h;
	if (h -> value == u)
	{
		Node *temp = h;
		h = h -> next;
	    free(temp);
	    return h;
	}
	while (p -> next != NULL)
	{
		if (p -> next -> value == u) break;
		p = p -> next;
	}
	if (p -> next != NULL)
	{
		Node *tmp = p -> next;
		p -> next = tmp -> next;
		free(tmp);
		return h;
	}
}

Node *reverseNode(Node *h)
{
	Node *pp = NULL;
	Node *p = h;
	Node *np = NULL;
	if (h = NULL) return NULL;
	while (p != NULL)
	{
		np = p -> next;
		p -> next = pp;
		pp = p;
		p = np;
	}
	return pp;
}

void freeList(Node *h)
{
	if (h == NULL) return;
	freeList(h -> next);
	free(h);
}
int main()
{
    int n , k, u ,v , b , c , d ,e , f;
    char a[1000];
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d",&k);
        first = addlast(first , k);
    }
    do
    {
        scanf("%s",a);
        if (strcmp(a,"addlast") == 0)
            {
                scanf("%d",&b);
                first = addlast(first , b);
            }
        if (strcmp(a,"addfirst") == 0)
            {
                scanf("%d",&c);
                first = addfirst(first , c);
            }
        if (strcmp(a ,"addafter") == 0)
            {
                scanf("%d%d",&u,&v);
                first = addafter(first , u , v);
            }
        if (strcmp(a , "addbefore") == 0)
            {
                scanf("%d%d",&d,&e);
                first = addbefore(first , d , e);
            }
        if (strcmp(a ,"remove") == 0)
            {
                scanf("%d",&f);
                first = removeNode(first , f);
            }
        if (strcmp(a , "reverse") == 0)
            {
                first = reverseNode(first);
            }
    } while (strcmp(a , "#") != 0);
    printList(first);
    freeList(first);
    return 0;
}
