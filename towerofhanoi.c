#include<stdio.h>
#include<math.h>

void hanoi(int,char,char,char);
int main()
{
int n;
char A='A';
char B='B';
char C='C';
printf("enter the number of disk \n");
scanf("%d",&n);
int steps=(pow(2,n)-1);
printf("nos of steps in cluded are %d\n",steps);
hanoi(n,A,C,B);
return 0;
}

void hanoi(int n,char A,char C,char B)
{
if(n==1)
{
printf("Move from %c to %c \n",A,C);
return;
}
hanoi(n-1,A,B,C);
printf("move from %c to %c \n",A,C);
hanoi(n-1,B,C,A);
}
