#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int gcd(int a,int b)
{
    if(b!=0)
    {
        gcd(b,a%b);
    }
    else
    {
        return a;
    }
}
int main()
{
    while(1)
    {
        int num1,num2,x;
        system("CLS");
        cout<<"enter your first number: ";
        cin>>num1;
        cout<<"enter your second number: ";
        cin>>num2;
        x=gcd(num1,num2);
        cout<<x<<endl;
        getch();
    }
    return 0;
}
