#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;
struct list
{
    NODE *head;
};
typedef struct list DLIST;

void init(DLIST *p)
{
    p->head = NULL;
}

NODE *getnode(int ele)
{
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = ele;
  temp->rlink = NULL;
  temp->llink = NULL;
  return temp;
}

void insertf(DLIST *p,int ele)
{
    NODE *newnode;
    newnode = getnode(ele);
    if(p->head==NULL)
    {
        p->head = newnode;
    }
    else
    {
        newnode->rlink = p->head;
        p->head->llink = newnode;
        p->head = newnode;
    }
}

void insertrear(DLIST *p,int ele)
{

    NODE *temp;
    temp = p->head;
    NODE *newnode;
    newnode = getnode(ele);
    if(p->head == NULL)
    {
        p->head = newnode;
    }
    else
    {
        NODE *cur;
        cur = p->head;
        while(cur->rlink!=NULL)
        {
            cur = cur->rlink;
        }
        cur->rlink = newnode;
        newnode->llink = cur;
    }
}

void insertap(DLIST *p, int ele, int pos)
{
    NODE *temp;
    temp = p->head;
    if(pos==1)
    {
        insertf(p,ele);
    }
    NODE *te;
    te = p->head;
    int count = 0;
    while(te!=NULL)
    {
        te = te->rlink;
        count ++;
    }
    if(pos == count)
    {
        insertrear(p,ele);
    }
    else
    {
        NODE *prev = NULL;
        NODE *cur = p->head;
        int count = 1;
        while(cur->rlink!=NULL && count!=pos)
        {
            prev = cur;
            cur = cur->rlink;
            count++;
        }
        NODE *newnode;
        newnode = getnode(ele);
        prev->rlink = newnode;
        newnode->llink = prev;
        newnode->rlink = cur;
        cur->llink = newnode;
    }
}

void delfrnt(DLIST *p)
{
    
    if(p->head == NULL)
    {
        printf("Cannot delete an empty list!!\n");
    }
    else if(p->head->rlink == NULL)
    {
        free(p->head);
        p->head = NULL;
    }
    else
    {
        NODE *temp;
        temp = p->head;
        p->head = p->head->rlink;
        p->head->llink = NULL;
        free(temp);
    }
}

void delrear(DLIST *p)
{
    if(p->head == NULL)
    {
        printf("Cannot delete an empty list!!\n");
    }
    else if(p->head->rlink == NULL)
    {
        free(p->head);
        p->head = NULL;
    }
    else
    {
        NODE *temp=p->head;
        while(temp->rlink!=NULL)
        {
            temp = temp->rlink;
        }
        temp->llink->rlink = NULL;
        free(temp);
    }
}

void delap(DLIST *p,int pos)
{
    if(pos == 1)
    {
        delfrnt(p);
    }
    NODE *temp;
    temp = p->head;
    int c = 0;
    while(temp!=NULL)
    {
        c++;
        temp = temp->rlink;
    }
    if(pos == c)
    {
        delrear(p);
    }
    else
    {
        NODE *temp = p->head;
        int c = 0;
        while(pos!=c && temp->rlink!=NULL)
        {
            temp = temp->rlink;
            c++;
        }
        temp->llink->rlink = temp->rlink;
        temp->rlink->llink = temp->llink;
        free(temp);
    }
}

void disp(DLIST *p)
{
    if(p->head == NULL)
    {
        printf("Empty List!!\n");
        return;
    }
    else
    {
        NODE *temp;
        temp = p->head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->rlink;
        }
    }
}

int main()
{
    DLIST l1;
    init(&l1);
    insertf(&l1,8);
    insertf(&l1,7);
    insertf(&l1,6);
    insertf(&l1,5);
    insertrear(&l1,9);
    insertrear(&l1,10);
    insertap(&l1,12,3);
    insertap(&l1,14,4);
    //delfrnt(&l1);
    delrear(&l1);
    //delap(&l1,4);
    disp(&l1);

}