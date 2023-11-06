#include<stdio.h>
#include<stdlib.h>
 struct node
 {
    int data;
    int row;
    int col;
    struct node* next;
 };

 struct node* insert(struct node *element, int r, int c, int val)
 {
    struct node *temp;
    if(element==NULL)
    {
        element=(struct node*)malloc(sizeof(struct node));
        element->row=r;
        element->col=c;
        element->data=val;
        element->next=NULL;
    }
    else
    {
        temp=element;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->row=r;
        temp->col=c;
        temp->data=val;
        temp->next=NULL;
    }
    return (element);
 }

 voidprintlist(struct node*element)
 {
    printf("thr resultant sparse matrix is:");
    while(element->next!=NULL)
    {
        printf("%d%d%d->",element->row, element->col,element->data);
        element=element->next;
    }
     printf("%d%d%d->",element->row, element->col,element->data);
 }

 
 int main()
 {
    int i,n;
   
    printf("enter the number of non zero elements:");
    scanf("%d",&n);
     int r,c,val;
     struct node* element=NULL;
     for(i=1;i<=n;i++)
     {
        printf("enter the row and column and data");
        scanf("%d%d%d",&r,&c,&val);
        struct node* insert(element,r,c,val);
     }

    printlist(element); 
    return 0;
 }