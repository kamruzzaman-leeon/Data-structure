#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *next;
};
struct node *head=NULL,*temp=NULL;
void push(int value)
{
    node *curr;
    curr=(struct node*)malloc(sizeof(curr));
    curr->value=value;
    curr->next=NULL;
    if(head == NULL)
    {
        head = curr;
    }
    else
    {
        curr->next=head;
        head=curr;
    }
}
int stack_empty()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int pop()
{
    if(stack_empty())
    {
        temp=head;
        head=head->next;
        return temp->value;
    }
    else
    {
        return 0;
    }
}
void display()
{
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void binary(int x)
{

    while(x>0)
    {
        if(x%2==0)
        {
            push(0);
        }
        else
        {
            push(1);
        }
        x=x/2;

    }
}
void parsing()
{

}
int main(void)
{
    int num,data;
    while(1)
    {
        cout<<"1.push\t2.display\t3.pop\t4.reversing"<<endl;
        cin>>num;
        switch(num)
        {
        case 1:
            cout<<"enter your data:";
            cin>>data;
            push(data);
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        case 4:
            int x;
            cout<<"enter a number:";
            cin>>x;
            binary(x);
            break;
        case 5:
            parsing();
        default:
            cout<<"choice again"<<endl;
            break;
        }
    }
}

