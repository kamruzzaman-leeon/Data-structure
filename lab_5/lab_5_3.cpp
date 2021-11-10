#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int lcm(int a,int b)
{
    int temp=a%b;
    if(temp==0)
        return a;
    else
        return a*lcm(b,temp)/temp;
}
int main()
{
    while(1)
    {

        int num1,num2,y;
        system("CLS");
        cout<<"enter your first number: ";
        cin>>num1;
        cout<<"enter your second number: ";
        cin>>num2;
        y=lcm(num1,num2);
        cout<<"L.C.M:"<<y<<endl;
        getch();
    }
    return 0;
}
