/*
the quick sort follows divide and conquere algorithm just like merge sort
here a pivot element is selected from the array 
either from the first position, or last position of mid position or randomly

let us consider the pivot element is the last element

now we will traverse every all the element of the array till high-1
and compare with the pivot element is the element is less than o equal pivot the we keep it at the left half
if greater than pivot we keep it  on the right hand side 
*/

#include<stdio.h>

int partition(int [],int ,int);
void print(int[],int);
void quicksort(int[],int,int);
void swap(int*,int*);
int main()
{
    int a[]={2,4,5,7,1,3,2,9,6};
    int n=sizeof(a)/sizeof(a[0]);
    int start=0;
    int end=n-1;
    
    printf("the unsorted array\n");
    print(a,n);
    
    quicksort(a,start,end);
    printf("\nthe sorted array\n");
    print(a,n);
    return 0;
}

void quicksort(int a[],int start,int end)
{
    if(start<end)
    {
        int pi;
        pi=partition(a,start,end);
        quicksort(a,start,pi-1);
        quicksort(a,pi+1,end);
        
    }
}

void swap(int *a,int*b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
    
}
void print(int a[],int n)
{int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int partition(int a[],int start,int end)
{
    int pivot;
    pivot=a[end];
    int i=start -1;
    int j;
    for(j=start;j<=end-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
            
        }
    }
    swap(&a[i+1],&a[end]);
    return i+1;
}

