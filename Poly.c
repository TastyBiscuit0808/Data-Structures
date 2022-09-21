#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node 
{
    int data;
    int power;
    struct node *link;
};
typedef struct node NODE;
struct list
{
    NODE *head;
};
typedef struct list LLIST;

void init(LLIST *p1, LLIST *p2)
{
    p1->head = NULL;
    p2->head = NULL;

}

NODE *getnode(int ele, int exp)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->power = exp;
    temp->link = NULL;
}


void insertf(LLIST *p,int ele, int exp)
{
  NODE *temp;
  temp = getnode(ele, exp);
  if(p->head==NULL)
  {
    p->head = temp;
  }
  else
  {
    temp->link=p->head;
    p->head = temp;
  }
}

void inp1(LLIST *p1)
{
    int n;
    printf("Enter the length of first polynomial : ");
    scanf("%d",&n);
    while(n!=0)
    {
        int e,x;
        printf("Enter the element and power from the lowest :");
        scanf("%d %d",&e,&x);
        insertf(p1,e,x);
        n--;
    }
}

void inp2(LLIST *p2)
{
    int n;
    printf("Enter the length of second polynomial : ");
    scanf("%d",&n);
    while(n!=0)
    {
        int e,x;
        printf("Enter the element and power from the lowest  :");
        scanf("%d %d",&e,&x);
        insertf(p2,e,x);
        n--;
    }
}
    
void add(LLIST *p1,LLIST *p2)
{
    NODE *cur1 = p1->head;
    NODE *cur2 = p2->head;
    int sum = 0;
    while(cur1!=NULL || cur2!=NULL)
    {
        if(cur1->power == cur2->power)
        {
            
            sum = cur1->data + cur2->data;
            printf("%d\n",sum);
        }
        cur1 = cur1->link;
        cur2 = cur2->link;
    }
}

void eval(LLIST *p1,LLIST *p2,int x)
{
    printf("For the first polynomial the evaluation is : ");
    NODE *temp1;
    temp1 = p1->head;
    int val1 = 0;
    while(temp1!=NULL)
    {
        val1+=(temp1->data)*pow(x,temp1->power);
        temp1 = temp1->link;
    }
    printf("%d\n",val1);

    printf("For the second polynomial the evaluation is : ");
    NODE *temp2;
    temp2 = p2->head;
    int val2 = 0;
    while(temp2!=NULL)
    {
        val2+=(temp2->data)*pow(x,temp2->power);
        temp2 = temp2->link;
    }
    printf("%d\n",val2);
}

int main()
{
    LLIST l1, l2;
    init(&l1,&l2);
    inp1(&l1);
    inp2(&l2);
    add(&l1,&l2);
    eval(&l1,&l2,2);
}