#include<bits/stdc++.h>
using namespace std;

struct node
{
    char value;
    node *next;
};
struct node *head=NULL,*temp=NULL;
void push(char value)
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
        return 1;
    }
    else
    {
        return 0;
    }
}
char pop()
{
    if(!stack_empty())
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
char peek()
{
    if(!stack_empty())
    {
        return head->value;
    }
}
int main()
{
    char str[100];
    int i=0;
    cout<<"enter your input:";
    cin>>str;
    while((str[i])!=NULL)
    {
        if(str[i]=='(')
            push(str[i]);
        else if(str[i]==')')
        {
            while(1)
            {
                if(peek()=='('&&!stack_empty())
                {
                    pop();
                    break;
                }
                else
                {
                    push(str[i]);
                    break;
                }
            }
        }
        i++;
    }
    if(stack_empty())
    {
        cout<<"everything right";

    }
    else
    {
        if(peek()=='(')
        {
            cout<<"opening parentheses not end"<<endl;
        }
        else if(peek()==')')
        {
            cout<<"closing parentheses not matched"<<endl;
        }
    }


}
