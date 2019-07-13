//insertion sort
//hop right
//key hop to its perfect position

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void InsertionSort(int[],int);
int main()
{
    int n,a[100],i;
    printf("enter the number of elements ");
    scanf("%d",&n);
    
    printf("Enter the elelemnts of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    InsertionSort(a,n);

printf("The sorted elements are ");

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

void InsertionSort(int a[],int n)
{
    int temp,i,j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while((a[j]>key)&&(j>=0))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key; //since j was decremented before coming out of the while loop
    }
printf("Bubble Sorting done");
}
