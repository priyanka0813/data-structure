#include<stdio.h>
void merge(int [],int,int);
void mergesort(int [],int,int);
void print(int [],int);

int main()
{
    int a[]={2,5,1,9,5,7,8};
    int n=sizeof(a)/sizeof(a[0]);
    int start=0,end=n-1;
    printf("un sorted array is \n");
    print(a,n);
    
    mergesort(a,start,end);
    printf("\nsorted array is \n");
    print(a,n);
    return 0;
}

void mergesort(int a[],int start,int end)
{
    int mid;
    if(start==end)
    return;
    else
    {
        mid=(start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,end);
    }
}
void merge(int a[],int start,int end)
{
    int mid,i=0,j=0,k=0;
    int temp[end-start+1]; //size of n
    mid=(start+end)/2;
    i=start;
    j=mid+1;
    //where i is the index f left halve and j indexof right halve
    while(i<=mid&&j<=end)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        temp[k++]=a[j++];
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
        
    }
    while(j<=end)
    {
        temp[k++]=a[j++];
    }
    
    for(i=0;i<k;i++) //for first iteration 0 and 1
    {
        a[start++]=temp[i]; //by the end of first one value of start will start from 2 index
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
