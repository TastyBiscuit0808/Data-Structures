#include<stdio.h>
#include<stdlib.h>

int h[20];

void heap_bottomup(int h[], int n)
{
    int v,heap,j;
    for(int i = n/2;i>=1;i--)
    {
        int k = i;                                                  
        v = h[k]; // Will give the parent node
        heap = 0;
        while((!heap) && (2*k)<=n)
        {
            j = 2*k; // Will give the child node
            if(j<n)
            {
                if(h[j]<h[j+1]) // Check if the right child is greater than the child node.
                {
                    j = j+1; // Make the right child as j if it's greater than the left child of the same parentv.
                }
                if(v>=h[j])
                {
                    heap = 1;
                }
                else
                {
                    h[k] = h[j]; // Swap the nodes of child and parent. 
                    k = j; 
                }
            }
        }
        h[k] = v;
    }
}

void heap_top_down(int h[],int i)
{
    int j;
    j = i/2;
    while(i>1 && h[i]>=h[j])
    {
        int temp = h[i];
        h[i] = h[j];
        h[j] = temp;
        i = j;
        j = i/2;
    }
}

void shift_up(int h[], int i)
{
    int j;                                                          
    j = i/2;
    while(i>1 && h[i]>=h[j])
    {
        int temp = h[i];
        h[i] = h[j];
        h[j] = temp;
        i = j;
        j = i/2;
    }
}

void shift_down(int h[], int k, int *n)
{
    int v,heap,j;
    v = h[k];
    heap = 0;
    while((!heap) && (2*j)<=*n)
    {
        j = 2*k;        
        if(j<*n)
        {
            if(h[j]<h[j+1])
            {
                j = j+1;                
            }
            if(v>=h[j])
            {
                heap = 1;
            }
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
    }
    h[k] = v;
}

void pqinsert(int h[], int *n)
{
    int ele;
    printf("Enter the element : ");
    scanf("%d",&n);
    *n = *n + 1;
    shift_up(h,*n);
}

void pqdelete(int h[], int *n)
{
    if(*n == 0)
    {
        printf("Empty pq!!\n");
        return;
    }
    printf("Deleted element is %d\n",h[1]);
    h[1] = h[*n]; 
    *n = *n-1;
    shift_down(h,1,n);
}

void disp(int h[], int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d ",h[i]);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter : ");
        scanf("%d",&h[i]);
    }
    heap_bottomup(h,n);
    // for(int i = 1;i<=n;i++)
    // {
    //     heap_top_down(i);
    // }
    // pqinsert(h,&n);
    pqdelete(h,&n);
    disp(h,n);
    
}

// #include<stdio.h>
// #define MAX 50

// struct priq
// {
//     int pq[MAX];
//     int n;
// };
// typedef struct priq PQ;

// void init(PQ *pt)
// {
//     pt->n=0;
// }

// void disp(PQ *pt)
// {
//     int i;
//     for(i=0;i<pt->n;i++)
//     {
//         printf("%d ",pt->pq[i]);
//     }
//     printf("\n");
// }

// int enqueue(PQ *pt,int e)
// {
//     int p,c;
//     if(pt->n==MAX-1) return 0;
//     c=pt->n;
//     p=(c-1)/2;
//     while(c>0 && pt->pq[p]<e)
//     {
//         pt->pq[c]=pt->pq[p];
//         c=p;
//         p=(c-1)/2;
//     }
//     pt->pq[c]=e;
//     pt->n=pt->n+1;
//     return 1;
// }

// int dequeue(PQ *pt,int *ele)
// {
//     int p,c;
//     *ele=pt->pq[0];
//     int elt=pt->pq[pt->n-1];
//     p=0;
//     if(pt->n==1)
//         c=-1;
//     else c=1;
//     if(pt->n>2 && pt->pq[2]>pt->pq[1])
//         c=c+1;
//     while(c>=0 && elt<pt->pq[c])
//     {
//         pt->pq[p]=pt->pq[c];
//         p=c;
//         c=2*p+1;

//         if(c+1<pt->n-1 && pt->pq[c+1]>pt->pq[c])
//         c=c+1;
//         if(c>=pt->n-1) c=-1;
//     }
//     pt->pq[p]=elt;
//     pt->n=pt->n-1;
//     return 1;
// }

// int main()
// {
//     PQ pobj;
//     int x,choice,ele;
//     init(&pobj);
//     do
//     {
//         printf("Enter 1 to enqueue, 2 to dequeue and 3 to display: ");
//         scanf("%d",&choice);
//         switch(choice)
//         {
//             case 1: printf("Enter the value: ");
//                     scanf("%d",&ele);
//                     enqueue(&pobj,ele);
//                     break;
//             case 2: x = dequeue(&pobj,&ele);
//                     if(!x) 
//                     printf("Empty!!");
//                     else
//                     printf("%d dequeues element\n",ele);
//                     break;
//                     case 3: disp(&pobj);
//                     break;
//         }
//     }while(choice<4);
// return 0;
// }