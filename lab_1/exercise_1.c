#include<stdio.h>
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
    max = *pointer;
    for(i=0;i<number;i++)
    {
        if(max<pointer[i])
        {
            max = pointer[i];
        }
    }
    printf("Expected Output:%d\n",max);

    return 0;
}
