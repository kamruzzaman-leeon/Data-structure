#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*last=NULL;
void create(int y)
{
    struct node *curr;
    curr=(struct node*)malloc(sizeof(curr));
    curr->data=y;
    curr->next=NULL;
    if(head==NULL)
    {
        head=curr;
        last=curr;
    }
    else
    {
        last->next=curr;
        last=curr;
    }

}
struct node* rev(node *temp)
{
    if(temp==NULL||temp->next==NULL)
    {
        return temp;
    }
    head=rev(temp->next);
    temp->next->next=temp;
    temp->next=NULL;
    return head;

}
void display(node *link)
{
    if(link!=NULL)
    {
        cout<<link->data<<" ";
        display(link->next);

    }
}

int main(void)
{
    int n,x;
    while(1)
    {
        cout<<"choose:\t1.create\t2.reverse \t3.display: ";
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"enter your data: ";
            cin>>x;
            create(x);
            break;
        case 2:
            rev(head);
            cout<<"operation complete!check by display."<<endl;
            break;
        case 3:
            display(head);
            cout<<endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
