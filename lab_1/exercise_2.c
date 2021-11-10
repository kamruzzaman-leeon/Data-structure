//#include<stdio.h>
//int main(void)
//{
//    int n,i;
//    printf("total array size:");
//    scanf("%d",&n);
//    int a[n];
//    printf("input %d number of elements in the array: ",n);
//    for(i=0;i<n;i++)
//    {
//            scanf("%d",&a[i]);
//    }
//
//    return 0;
//}
#include<stdio.h>
void sortarray(int n,int *p)
{
    int i,j,temp = 0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(p+i)>*(p+j))
            {
                temp = *(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;
            }

        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(p+i));
    }

}
int main(void)
{
    int number,j,i,*pointer,max;
    printf("Input size of array: ");
    scanf("%d",&number);

    pointer = (int*)malloc(sizeof(int)*number);
    printf("Array element: ");
    for(j=0;j<number;j++)
    {
        scanf("%d",(pointer+j));
    }
    sortarray(number,pointer);

    return 0;
}
