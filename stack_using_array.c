//stack using array
#include<stdio.h>
#include<stdlib.h>
int stk[5];
int max=5;
int top=-1;

int isfull()
{
	if(top==max-1)
	
		return 1;
	
	else
		return 0;
}

int isempty()
{
	if(top== -1)
		return 1;
	else
		return 0;
}

void push(int n)
{
	if(isfull())
	{
		printf("sorry the stack is full \n");
		return;	//return ,means the execution control will again move to main function at this point
	}
	else
	{
		top++;
		stk[top]=n;
		printf("element %d at the top is successsfully entered \n",n);
	}
}

void pop()
{
	if(isempty())
	{
		printf("sorry the stack is empty nothing to delete \n");
		return;
	}
	else
	{
		int x=stk[top];
		top--;
		printf("element from the top is successfully deleted");
	}
}

void display()
{
	int i;
	if(isempty())
	{
		printf("the stack is empty nothing to display");
		return;
	}
	else
	{
	
	for(i=top;i>=0;i--)     //if we consider the indexing from right to left that is 0 index is at the right most
	{						//if we want to consider it from left to right den for(i=0;i<=top;i++)
		printf("%d ",stk[i]);
	}
	}
}

int main()
{
	int n,choice;
	printf("your menu is \n1)PUSH\n2)POP\n3)DISPLAY\n4)EXIT\n");
	while(1) //this is an infinite loop. 1 means condition will always be true.it wont exit untill the exit(0) funtion is called with in the choice
	{
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\enter the element you want to push\n");
				scanf("%d",&n);
				push(n); //data n is passed inside the function push and push is being called
				break;
			
			case 2:
				pop();
				break;
			case 3:
				printf("\nYOUR STACK IS \n");
				display();
			case 4:
				exit(0);
				break;
			default:
				printf("\nsorry wrong input");
		}
	}
}
