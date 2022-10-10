#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int info;
    bool rthread;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;

struct tree
{
    NODE *root;
};
typedef struct tree TREE;

void init(TREE *p)
{
    p->root=NULL;
}

NODE* createNode(int ele)
{
    NODE* temp=malloc(sizeof(NODE));
    temp->info=ele;
    temp->left=NULL;
    temp->right=NULL;
    temp->rthread=1;
    return temp;
}

void setLeft(NODE* q,int e) //set node to left of queue
{
    NODE* temp=createNode(e);
    q->left=temp;
    temp->right=q;
}

void setRight(NODE* q,int e)
{
    NODE* temp=createNode(e);
    temp->right=q->right; //thread
    q->right=temp;
    q->rthread=0;
}
void inOrder(TREE *t)
{
    NODE *p=t->root;
    NODE *q;
    do{
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            p=p->left;
        }
        if(q!=NULL)
        {
            printf("%d ",q->info);
            p=q->right;
            while(q->rthread && p!=NULL)
            {
                printf("%d ",p->info);

                q=p;
                p=p->right;
            }
        }
    }while(q!=NULL);
}

void create(TREE *pt)
{
    NODE *p,*q;
    int e,wish;
    printf("Enter root info\n");
    scanf("%d",&e);
    pt->root=createNode(e);
    do{
        printf("Enter info\n");
        scanf("%d",&e);
        p=pt->root;
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            if(e<p->info)
                p=p->left;
            else{
                if(p->rthread)
                    p=NULL;
                else
                    p=p->right;
                }
        }
    if(e < q->info)
        setLeft(q,e);

    else
    setRight(q,e);
    printf("Do you wish to add another element\n");
    scanf("%d",&wish);
    }while(wish);
}

int main()
{
    TREE t;
    init(&t);
    create(&t);
    inOrder(&t);
    return 0;
}