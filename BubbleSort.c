//Bubble sorting
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i,j,n,temp=0,a[100];
    printf("enter the number of elements ");
    scanf("%d",&n);
    
    printf("Enter the elelemnts of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
printf("Bubble Sorting done");

printf("The sorted elements are ");

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

