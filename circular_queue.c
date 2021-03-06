//stack using array
#include<stdio.h>
#include<stdlib.h>
int queue[5];
int maxq=5;
int front=-1;
int rear=-1;

int isfull()
{
	if(front==(rear+1)%maxq)
	
		return 1;
	
	else
		return 0;
}

int isempty()
{
	if(rear== -1)
		return 1;
	else
		return 0;
}

void enqueue(int n)
{
	if(isfull())
	{
		printf("sorry the queue is full \n"); //overflow
		return;	//return ,means the execution control will again move to main function at this point
	}
	else if(front == -1)
	{
		front =0;
		rear= 0;
	}
	else
	{
		rear=(rear + 1)%maxq;
	}
	
		queue[rear]=n;
		printf("element %d at the rear is successsfully entered \n",n);
	
}

void dequeue()
{
	if(isempty())
	{
		printf("sorry the queue is empty nothing to delete \n");
		return;
	}
	else
	{
		int x=queue[front];
		if(front== rear)
		{
			front= -1;
			rear= -1;
		}
		else
		{
			front=(front+1)%maxq;
		}
		printf("element from the front is successfully deleted");
	}
}

void display()
{
	int i;
	if(isempty())
	{
		printf("the queue is empty nothing to display");
		return;
	}
	else if(front<=rear)
	{
	
	for(i=front;i<=rear;i++)     //this will print the elements fron front to rear index
	{
	
		printf("%d ",queue[i]);
	}
	}
	else
	{
		for(i=front;i<=maxq-1;i++)
		{
			printf("%d ",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
		
	}
}

int main()
{
	int n,choice;
	printf("your menu is \n1)ENQUEUE\n2)DEQUEUE\n3)DISPLAY\n4)EXIT\n");
	while(1) //this is an infinite loop. 1 means condition will always be true.it wont exit untill the exit(0) funtion is called with in the choice
	{
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\enter the element you want to push\n");
				scanf("%d",&n);
				enqueue(n); //data n is passed inside the function push and push is being called
				break;
			
			case 2:
				dequeue();
				break;
			case 3:
				printf("\nYOUR CIRCULAR IS \n");
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nsorry wrong input");
		}
	}
	return(0);
}
