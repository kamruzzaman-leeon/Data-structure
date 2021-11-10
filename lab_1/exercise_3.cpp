#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int number,j=0,i=0,*pointer;
    cout<<"size of array:";
    cin>>number;
    cout<<"enter your data:"<<endl;
    pointer=(int*)malloc(sizeof(pointer)*number);
    for(j=0;j<number;j++)
    {
        cin>>*(pointer+j);
    }
    j=0;
    while(j<number)
    {
        if(*(pointer+j)>=0)
        {
            j++;
        }
        else{
            for(i=j;i<number;i++)
            {
                *(pointer+i)=*(pointer+i+1);
            }
            number--;
        }
    }

    for(j=0;j<number;j++)
    {
        cout<<*(pointer+j)<<"\t";
    }
    return 0;
}
