#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodes{
    int id;
    struct Nodes *leftChild;
    struct Nodes *rightChild;
} Node;

Node *makeNode(int x)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p -> id = x;
    p -> leftChild = NULL;
    p -> rightChild = NULL;
    return p;
}

Node *find(Node *r, int x)
{
    if (r == NULL) return r;
    if (x == r -> id) return r;
    if (x > r -> id) return find(r -> rightChild, x);
    else return find(r -> leftChild, x);
}

Node *insert(Node *r, int x)
{
    if (r == NULL)
    {
        r = makeNode(x);
        return r;
    }
    if (x < r -> id) r -> leftChild = insert(r -> leftChild, x);
    else r -> rightChild = insert(r -> rightChild, x);
    return r;
}

void preOrder(Node *r)
{
    if (r == NULL) return;
    printf("%d ", r -> id);
    preOrder(r -> leftChild);
    preOrder(r -> rightChild);
}

Node *root = NULL;

int main()
{
    char s[50];
    int a;
    while(1)
    {
        scanf("%s",s);
        if (strcmp(s, "insert") == 0)
        {
            scanf("%d",&a);
            if (find(root, a) == NULL)
                root = insert(root, a);
        }
        else break;
    }
    preOrder(root);
    return 0;
}
