#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

int main()
{
    int i,j,k;
    head=NULL;
    for(i=1;i<10;i++)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=i;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    struct node *prnt=head;
    while(prnt!=NULL)
    {   
        printf("%d\n",prnt->data);
        prnt=prnt->next;
    }
}