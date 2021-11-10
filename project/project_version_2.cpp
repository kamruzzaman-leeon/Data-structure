///project: calculator
///kamruzzaman leon 2018-1-60-252
///md. nadim 2018-1-60-161

#include<bits/stdc++.h>
using namespace std;
string posttemp="";/// empty global variable for store postfix expression
string pretemp="";
///prototype
int respect(char ch);
string postfix_expression(string infix);
double post_evaluation(string pos);
float operation(int y, int x, char ch);
string prefix_expression(string inf);
double pre_evaluation(string pre);

///create for maintaining BODMAS
int respect(char ch)
{
    if(ch=='-')
        return 5;
    if(ch=='+')
        return 10;
    else if(ch=='*')
        return 20;
    else if(ch=='/')
        return 25;
    else if(ch=='^')
        return 30;
    else
        return 0;
}
///postfix expression
string postfix_expression(string infix)
{
    string postfix;
    stack<char>data;///STL
    data.push('&');///using '&' for easily handle stack
    string::iterator it;
    for(it=infix.begin();it!=infix.end();it++)
    {
        if(isalnum(char(*it)))///isalnum function for Checking the character is alphanumeric or not.
        {
            postfix+=*it;
        }
        else if(*it=='('){
            data.push('(');
        }
        else if(*it=='^'){
            data.push('^');
        }
        else if(*it==')')
        {
            while(data.top()!='&'&&data.top()!='(')
            {
                postfix+=data.top();///store and pop until '(' has found
                data.pop();
            }
            data.pop(); ///remove '(' from the storage
        }
        else
        {
            if(respect(*it)>respect(data.top()))
            {
                data.push(*it); ///store if precedence is high
            }
            else
            {
                while(data.top()!='&'&&respect(*it)<=respect(data.top()))
                {
                    postfix+=data.top();///store and pop until higher precedence is found
                    data.pop();
                }
                data.push(*it);
            }
        }
    }
    while (data.top()!='&')
    {
        postfix+=data.top();
        data.pop();
    }
    posttemp=postfix;
    return postfix;

}

double operation(double y,double x,char ch)
{
    if(ch == '+')
      return x+y;
    else if(ch == '-')
      return x-y;
    else if(ch == '*')
      return x*y;
    else if(ch == '/')
      return x/y;
    else if(ch == '^')
      return pow(x,y);
    else
      return 0;
}
double post_evaluation(string pos)
{
    double a=0,b=0;
    stack<double>st;
    string::iterator it;

    for(it = pos.begin();it!=pos.end();it++)
    {
        if(*it == '+'|| *it == '-'|| *it == '*'|| *it == '/' || *it == '^')
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(operation(a,b,*it));

        }
        else if(isdigit(*it))
        {
            st.push(*it-'0');
        }
    }
    return st.top();
}
string prefix_expression(string inf)
{
    string prefix="";
    reverse(inf.begin(), inf.end());
    string::iterator it;

    for(it = inf.begin(); it != inf.end(); it++)
    {
        if(*it == '(')
            *it = ')';
        else if(*it == ')')
            *it = '(';
    }
    prefix = postfix_expression(inf);
    reverse(prefix.begin(), prefix.end());
    pretemp=prefix;
    return prefix;
}

double pre_evaluation(string pre)
{

    double a=0,b=0;
    stack<double>st;
    for(int it = pre.size()-1;it>=0;it--)
    {
        if(pre[it] == '+'|| pre[it] == '-'|| pre[it] == '*'|| pre[it] == '/' || pre[it] == '^')
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(operation(b,a,pre[it]));

        }
        else
        {
            st.push(pre[it]-'0');
        }
    }
    return st.top();
}
int main()
{
    string infix;
    cout<<"insert infix expression(without space): ";
    cin>>infix;
    cout<<endl;
    cout<<"Postfix expression: "<<postfix_expression(infix)<<endl<<endl;
    cout<<"postfix evaluation result : "<<post_evaluation(posttemp)<<endl<<endl;
    cout<<"prefix expression: "<<prefix_expression(infix)<<endl<<endl;
    cout<<"prefix evaluation result : "<<pre_evaluation(pretemp)<<endl<<endl;

    return 0;
}
