#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int co=0;
int main()
{
    while(1)
    {
        freopen("test.txt","r",stdin);
        int m[50][50]= {0};
        int node,edge;
        cout<<"insert node size & edge size: ";
        cin>>node>>edge;///size of vertex & edge

        int data1,data2;
        for(int i = 1; i<=node; i++)
        {
            for(int j=1; j<=edge; j++)
            {
                cin>>data1>>data2;///destination of connection
                m[data1][data2]=1;
                m[data2][data1]=1;
            }
            cout<<endl;
        }
        for(int i=1; i<=node; i++)
        {
            for(int j=1; j<=edge; j++)
            {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    cout<<"insert new node relation: ";
    cin>>data1>>data2;///destination of connection
    m[data1][data2]=1;
    m[data2][data1]=1;
    node++;
    cout<<endl;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=edge; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
        int de;
        cout<<"after delete node:";
        cin>>de;
        cout<<endl;
        for(int i=de; i<=node; i++)   ///row delete
        {
            for(int j=1; j<=edge; j++)
            {
                m[i][j]=m[i+1][j];

            }
        }

        for(int i=1; i<=node-1; i++)    ///column delete
        {
            for(int j=de; j<=edge; j++)
            {
                m[i][j]=m[i][j+1];
                m[j][i]=m[i][j];
            }

        }
        node--;
        edge--;
        for(int i=1; i<=node; i++)
        {
            for(int j=1; j<=edge; j++)
            {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        getch();
    }

    return 0;
}
