#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *head=NULL,*temp=NULL,*mini=NULL,*maxi=NULL,*dele=NULL,*local=NULL;
struct tree *Insert(tree* root,int item)
{
    if(root==NULL)
    {
        tree *cur;
        cur=(struct tree*)malloc(sizeof(cur));
        cur->data=item;
        cur->left=NULL;
        cur->right=NULL;
        root=cur;
        return root;
    }
    else if(item<root->data)
        root->left=Insert(root->left,item);
    else
        root->right=Insert(root->right,item);
    return root;
};
void preorder(struct tree* root)
{

    cout<<root->data<<" ";
    if(root->left!=NULL)
    {
        preorder(root->left);
    }
    if(root->right!=NULL)
    {
        preorder(root->right);
    }

}
void postorder(struct tree* root)
{
    if(root->left!=NULL)
    {
        postorder(root->left);
    }
    if(root->right!=NULL)
    {
        postorder(root->right);
    }
    cout<<root->data<<" ";
}
void Inorder(struct tree* root)
{
    if(root->left!=NULL)
    {
        Inorder(root->left);
    }
    cout<<root->data<<" ";
    if(root->right!=NULL)
    {
        Inorder(root->right);
    }

}
struct tree* Search(struct tree* root,int item)
{
    if(root==NULL||root->data==item)
    {
        temp=root;
        return root;
    }
    if(root->data<item)
        return Search(root->right,item);
    else
    {
        return Search(root->left,item);
    }
};

struct tree* findmin(tree* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    return findmin(root->left);
};

struct tree* findmax(tree* root)
{
    if(root->right==NULL)
    {
        return root;
    }
    return findmax(root->right);
};

struct tree* Delete(tree* root,int item)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data<item)
    {
        root->right=Delete(root->right,item);
        return root;

    }
    if(root->data>item)
    {
        root->left=Delete(root->left,item);
        return root;
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {

            free(root);
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            local=root;
            root=root->right;
            free(local);
            return root;
        }
        else if(root->right==NULL)
        {
            local=root;
            root=root->left;
            free(local);
            return root;
        }
        else
        {
            local=findmin(root->right);
            root->data=local->data;
            root->right=Delete(root->right,local->data);
            return root;
        }
    }
};

int main()
{
    int n,p=0;
    cout<<"how many data you want to insert: ";
    cin>>p;
    while(p)
    {
        cin>>n;
        head = Insert(head,n);
        p--;
    }
    cout<<"preorder: ";
    preorder(head);
    cout<<"postorder: ";
    postorder(head);
    cout<<"Inorder:";
    Inorder(head);
    cout<<endl<<endl;
    int s;
    mini=maxi=head;
    cout<<"minimum: "
    mini=findmin(mini);
    cout<<mini->data;
    cout<<endl;
    cout<<"maximum: ";
    maxi=findmax(maxi);
    cout<<maxi->data;
    cout<<endl<<endl;
    cout<<"input a value for search: ";
    cin>>s;
    temp=head;
    Search(temp,s);
    if(temp!=NULL)
    {
        cout<<"you require data found"<<temp->data<<endl;
    }
    else
    {
        cout<<"not found!"<<endl;
    }
    cout<<endl;
    int d;
    cout<<"enter a value from entry list to delete: ";
    cin>>d;
    dele=head;
    dele=Delete(head,d);
    cout<<"after deletion new list of data :"<<endl;
    cout<<"preorder: ";
    preorder(dele);
    cout<<"postorder: ";
    postorder(dele);
    cout<<"Inorder:";
    Inorder(dele);
    cout<<endl<<endl;
    cout<<"minimum :";
    mini=maxi=head;
    mini=findmin(mini);
    cout<<mini->data;
    cout<<endl;
    cout<<"maximum: ";
    maxi=findmax(maxi);
    cout<<maxi->data;
    cout<<endl;
    return 0;
}
