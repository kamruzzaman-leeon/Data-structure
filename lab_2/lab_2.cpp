#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL,*tail = NULL,*temp,*temp1;
void create() /// 1
{
    struct node *curr;
    int i=0,number;
    cout<<"how many input are you want:";
    cin>>number;                    ///number variable use for maintaining the current value limit.
    cout<<"enter your data:";
    while(i<number)
    {
        curr = (struct node*)malloc(sizeof(curr));
        cin>>curr->data;
        curr->next = NULL;
        if(head==NULL)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            tail->next = curr;
            tail = curr;
        }
        i++;
    }
    cout<<"successfully operation complete!"<<endl;
}


void insertionbeg()/// 2
{
    struct node *curr;
    curr = (struct node*)malloc(sizeof(curr));
    cout<<"input new data for insertion into the beginning:";
    cin>>curr->data;
    if(head==NULL)
    {
        head=curr;
        tail=curr;
    }
    else
    {
        curr->next=head;
        head=curr;
    }
    cout<<"successfully operation complete!"<<endl;
}


void insertionany() /// 3
{
    int position,i=0;
    struct node *curr;
    curr = (struct node*)malloc(sizeof(curr));
    cout<<"data insertion position:";
    cin>>position;
    cout<<"input new data for insertion : ";
    cin>>curr->data;
    curr->next=NULL;

    if(head==NULL)
    {
        head = curr;
        tail = curr;
    }
    else
    {
        temp =head;
        while(i<position-1)
        {
            temp1=temp;
            temp=temp->next;
            i++;
        }
        temp1->next=curr;
        curr->next=temp;

    }
    cout<<"successfully operation complete!"<<endl;

}
void insertionend() ///4
{
    struct node *curr;
    curr = (struct node*)malloc(sizeof(curr));
    cout<<"input your data to insert at last:";
    cin>>curr->data;
    curr->next=NULL;
    if(head==NULL)
    {
        head = curr;
        tail = curr;
    }
    else
    {
        tail->next=curr;
        tail=curr;
    }
    cout<<"successfully operation complete!"<<endl;
}
void deletebeg()
{
    temp=head;
    head=head->next;
    free(temp);
    cout<<"successfully operation complete!"<<endl;
}
void deleteend()
{
    if(head!=NULL)
    {
        temp =head;
        while(temp->next!=NULL)
        {
            temp1 =temp;
            temp = temp->next;
        }
        temp1->next =NULL;
        free(temp);
    }
    cout<<"successfully operation complete!"<<endl;

}
void deleteany()
{
    int del; ///del is a variable which use for delete data from link list
    cout<<"input your data for delete:";
    cin>>del;
    if(head!=NULL)
    {
        temp =head;
        while(temp->next!=NULL && temp->data!=del)
        {
            temp1=temp;
            temp=temp->next;
        }
        if(temp->data==del)
        {
            temp1->next=temp->next;
            free(temp);
        }
    }
    cout<<"successfully operation complete!"<<endl;
}

void reverselist()
{
    struct node* curr;
    temp1=NULL;
    curr = head;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=temp1;
        temp1=curr;
        curr=temp;

    }
    head=temp1;

    cout<<"successfully operation complete!"<<endl;
}
void removeduplicate()
{
    struct node* duplicate;
    temp= head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        temp1=temp;
        while(temp1->next!=NULL)
        {


            if(temp->data==temp1->next->data)
            {
                duplicate=temp1->next;
                temp1->next=temp1->next->next;
                free(duplicate);

            }
            else{
                temp1=temp1->next;
            }
        }temp=temp->next;
    }
    cout<<"successfully operation complete!"<<endl;
}

void display()
{
    temp=head;
    while(1)
    {
        cout<<temp->data<<"\t";
        if(temp->next ==NULL)
            break;
        temp=temp->next;
    }
    cout<<endl<<endl;
    cout<<"successfully operation complete!"<<endl;
}

void searchdata()
{
    int x;
    cout<<"search a number:";
    cin>>x;
    temp=head;
    while(head!=NULL)
    {
        if(temp->data==x)
        {
            cout<<"found"<<endl;
            break;
        }
        temp=temp->next;
    }
    if(head==NULL)
    {
        cout<<"not yet found"<<endl;
    }
    //cout<<"successfully operation complete!"<<endl;
}

int main()
{
    int n;

    while(1)
    {
        cout<<"\t1.create link list\t"<<endl;
        cout<<"\t2.insert into beginning\t"<<"\t3.insert at any position\t"<<"4.insert at end"<<endl;
        cout<<"\t5.Delete from beginning\t"<<"\t6.delete from any position\t"<<"7.Delete from last"<<endl;
        cout<<"\t8.Reverse link list\t"<<"\t9.removeduplicate\t"<<"\t10.Display"<<endl;
        cout<<"\t11.search"<<endl;
        cout<<"enter your choose:";
        cin>>n;
        switch(n)
        {
        case 1:
            create(); ///CREATE A LINKLIST
            break;
        case 2:
            insertionbeg();
            break;

        case 3:
            insertionany();
            break;
        case 4:
            insertionend();
            break;
        case 5:
            deletebeg();
            break;
        case 6:
            deleteany();
            break;
        case 7:
            deleteend();
            break;
        case 8:
            reverselist();
            break;
        case 9:
            removeduplicate();
            break;
        case 10:
            display();
            break;
        case 11:
            searchdata();
            break;
        default:
            cout<<endl;
            cout<<"choose another option"<<endl;
            break;
        }

    }
    return 0;
}
