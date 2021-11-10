#include<bits/stdc++.h>
using namespace std;
struct stu
{
    char name[100];
    int id;
    float cgpa;
};
int max_cg,j;
int main(void)
{
    int i,number;
    stu *pointer;
    cout<<"number of student information:";
    cin>>number;
    pointer=(struct stu*)malloc(sizeof(struct stu)*number);

    for(i=0; i<number; i++)
    {
        cout<<"enter student name:";
        cin>>(pointer+i)->name;
        cout<<"enter student id:";
        cin>>(pointer+i)->id;
        cout<<"enter student cgpa:";
        cin>>(pointer+i)->cgpa;
        cout<<endl;
    }
    max_cg=pointer->cgpa;
    i=0;
    while(i<number)
    {
        if((pointer+i)->cgpa>max_cg)
        {
            max_cg=(pointer+i)->cgpa;
            j=i;
        }
        i++;
    }
        cout<<"highest cgpa holder: ";
        cout<<(pointer+j)->name<<"\t";
        cout<<(pointer+j)->id<<"\t";
        cout<<(pointer+j)->cgpa<<endl;

    return 0;
}
