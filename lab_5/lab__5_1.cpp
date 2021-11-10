#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
float recursion(float num,float power)
{
    if(power==0)
    {
        return 1;
    }
    else
    {
        return num*recursion(num,power-1);
    }
}
int main()
{
    while(1)
    {
        system("CLS");
        float number,pow;
        cout<<"input any number: ";
        cin>>number;
        cout<<"input power: ";
        cin>>pow;
        cout<<"output: "<<recursion(number,pow)<<endl;
        getch();
    }
    return 0;
}
