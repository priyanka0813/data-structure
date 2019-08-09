//HEAP SORT 
/*
heap sort-> is a comparision based sorting algorithm which uses the property of heapto sort a given array.
Heap-> is a special tree based data structure where the nodes are arranged in a special way such that thevalue of 
the parent node is greater(smaller) than anyof it's child node. the former is called max heap and the later is called min heap.

Binary heap->is a complete binary tree( tree where every level expect possibly the last level is completely filled)
which follows the property of heap .
*/

//let us implement heap sort with the help of max heap property

#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int n,int i) //a is the array that needs to be heapified n is the size of heap
{
    int largest=i; //index of the parent node
    int l=2*i+1;//index of the left child of the parent node
    int r=2*i+2;//index of the right child of the parent node
    
    if(l<n&&(a[l]>a[largest]))
    largest=l;
    
    
    if(r<n&&(a[r]>a[largest]))
    largest=r;
    
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n)
{
    int i;
    for(i=n/2 -1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    
    //after this we get the max heap 
    
    for(i=n-2;i>=0;i--)
    {
        swap(&a[0],&a[i]); //largest element at a[0] goes to the end of array
        heapify(a,i,0);
    }
}

int main()
{
    int a[]={3,6,1,9,3,6,0,7,5};
    int n=sizeof(a)/sizeof(a[0]);
    int i;
    heapsort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
