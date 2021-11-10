#include<bits/stdc++.h>
using namespace std;
int a[50],b[50];
int n,maxi,mini;
void Display()
{
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Swap(int pos,int par)
{
    int p;
    p=a[pos];
    a[pos]=a[par];
    a[par]=p;
}
void reheap_down(int pos,int last)
{
    int child;
    int left=2*pos;
    int right=2*pos+1;
    if(right<=last&&a[right]>a[left])
    {
        child=right;
    }
    else
    {
        child=left;
    }
    if(a[child]>a[pos])
    {
        Swap(pos,child);
        reheap_down(child,last);
    }
}
void reheap_up(int pos)
{
    int par;

    if(pos>1)
    {
        par= pos/2;
        if(a[pos]<a[par])
        {
            Swap(pos,par);
            reheap_up(par);
        }
        else
            reheap_up(par);

    }

}
void create()
{
    int x;
    cout<<"data size:";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        a[i]=x;
        reheap_up(i);

    }
    Display();
    cout<<endl;

}
void Delete()
{
    int low;
    low=a[1];
    a[1]=a[n];
    n--;
    cout<<"delete element: "<<low<<endl;
    reheap_down(1,n);

}
void max_min()
{
    maxi=a[1];
    for(int i=2; i<=n; i++)
    {
        if(maxi<a[i])
        {
            maxi=a[i];
        }
    }
    mini=a[1];
    for(int i=2; i<=n; i++)
    {
        if(mini>a[i])
        {
            mini=a[i];
        }
    }
    cout<<"maximum:"<<maxi<<endl;
    cout<<"minimum:"<<mini<<endl;
}
void Sort()
{
    int tem;
    for(int i=1; i<=n; i++)
    {
        b[i]=a[i];
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=i+1; j<=n; ++j)
        {
            if(b[i]>b[j])
            {
                tem=b[i];
                b[i]=b[j];
                b[j]=tem;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<b[i]<<" ";
    }
}

int main()
{
    int e;
    while(1)
    {
        cout<<endl;
        cout<<"1.create list"<<endl;
        cout<<"2.Delete element"<<endl;
        cout<<"3.MAX & MIN"<<endl;
        cout<<"4.sort"<<endl;
        cin>>e;
        switch(e)
        {
        case 1:
            create();
            break;
        case 2:
            Delete();
            cout<<endl;
            Display();
            break;
        case 3:
            max_min();
            break;
        case 4:
            Sort();
            break;

        }
    }
}
