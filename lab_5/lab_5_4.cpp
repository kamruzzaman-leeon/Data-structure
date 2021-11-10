#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int x=0;
int palindrome(int n)
{
    int y;
    if(n!=0)
    {
        y=n%10;
        x=x*10+y;
        palindrome(n/10);
    }
    else
    {
        return x;
    }

}
int main()
{
    while(1)
    {
        int num,rec;
        system("CLS");
        cout<<"check palindrome:";
        cin>>num;
        rec=palindrome(num);
        if(num!=rec)
        {
            cout<<"it is not palindrome"<<endl;
        }
        else
        {
            cout<<"it is a palindrome"<<endl;
        }
        getch();
    }
    return 0;
}
