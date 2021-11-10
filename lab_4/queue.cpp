#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
void enqueue(int x)
{
    struct node *cur =(struct node*)malloc(sizeof(cur));
    cur->data=x;
    cur->next=NULL;
    if(head==NULL)
    {
        head=cur;
        tail=cur;
    }
    else
    {
        tail->next=cur;
        tail=cur;
    }

}
void dequeue()
{
    node*temp=head;
    if(head==tail)
    {
        head=tail=NULL;
    }
    else
    {
        head=head->next;
    }
    free(head);
}
void display()
{
    node *temp=head;
    cout<<"data: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void copyqueue()
{
    struct node *cur2,*head2=NULL,*tail2=NULL,*temp=head;
    while(temp!=NULL)
    {
        cur2=(struct node*)malloc(sizeof(cur2));
        cur2->data=temp->data;
        cur2->next=NULL;
        if(head2==NULL)
        {
            head2=cur2;
            tail2=cur2;
        }
        else
        {
            tail2->next=cur2;
            tail2=cur2;
        }
        temp=temp->next;
    }
        cout<<"copied queue: ";
        temp=head2;
    while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    cout<<endl;
}
void compress_string()
{
    while(head!=NULL)
    {
        dequeue();
    }
    string s,space;
    getchar();
    getline(cin,s);
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            enqueue(i);
        }
    }
    for(int i=0;i<len;i++)
    {
        if(head!=NULL&&head->data==i)
        {
            dequeue();
            continue;
        }
        space+=s[i];
    }
    cout<<space<<endl;
}
void stack_queue()
{
    int p;
    while(head!=NULL)
    {
        dequeue();
    }
    cout<<"size of stack :";
    cin>>p;
    int arr[p];
    cout<<"elements:";
    for(int i=0;i<p;i++)
    {
        cin>>arr[i];
    }
    for(int i=p-1;i>=0;i--)
    {
        enqueue(arr[i]);
    }
    cout<<"please check by display!"<<endl;
}
void delete_neg()
{
    struct node *curr,*head2=NULL,*tail2=NULL,*temp=head,*temp2=NULL;
    while(temp!=NULL)
    {
        curr=(struct node*)malloc(sizeof(*curr));
        curr->data=temp->data;
        curr->next=NULL;
        if(head2==NULL&&curr->data>=0)
        {
            head2=NULL;
            tail2=NULL;
        }
        else if(curr->data>=0)
        {
            tail2->next=curr;
            tail2=curr;
        }
        temp2=temp;
        temp=temp->next;
        free(temp2);
    }
    head=head2;
    tail=tail2;
    cout<<"negetive elements are deleted."<<endl;
}
int main(void)
{
    int n;
    while(1)
    {
        cout<<"1.enqueue\n2.dequeue\n3.display\n4.copy queue\n5.compressing string\n6.stack to queue creation\n7.delete_all_negative_integer :";
        cin>>n;
        switch(n)
        {
        case 1:
            int x;
            cout<<"input your data:";
            cin>>x;
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            copyqueue();
            break;
        case 5:
            compress_string();
            break;
        case 6:
            stack_queue();
            break;
        case 7:
            delete_neg();
            break;
        default:
            cout<<"choose wrong number"<<endl;
            break;
        }
    }
    return 0;
}
