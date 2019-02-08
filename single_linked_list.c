//single linked list
//insertion all type
//deletion of all types

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;	
};
struct node*head=NULL;

void create(int n)
{
	struct node*newnode,*temp;
	int i;
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node %d : ",i+1);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;	
			}
			temp->next=newnode;	
		}
		printf("the list is successfully created\n");
	}
}

void insertbeg(int n1)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n1;
	newnode->next=head;
	head=newnode;
	printf("\n newnode issuccessfully inserted at the beginning \n");
}

void insertend(int n2)
{
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n2;
	newnode->next=NULL;
	if(head==NULL)
	{
			head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;	
		}
		temp->next=newnode;	
	}
		printf("\n node is successfully inserted at the end");
}

void insertpos(int n3,int p)
{
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n3;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		while(p- 2>0)
		{
			temp=temp->next;
			p--;
		}
		newnode->next=temp->next;   //next of newnode that was pointing to 'NULL' previously will now point to the next node of temp
		temp->next=newnode;		//newnode will be placed after temp that is next of temp will now point to newnode
	}
	printf("\nnode successfully entered at position %d",p);
	
}

void display()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("\n sorry the single linked list is empty nothing to display\n");
	}
	else
	{
	temp=head;
	printf("<");
	while(temp!=NULL)
	{
		printf("--");
		printf("%d",temp->data);
		temp=temp->next;
		
	}
	printf("-->");
	}
}

int main()
{
	int choice;
	int n,n1,n2,n3,p;
	printf("your menu is \n1)CREATE LINKED LIST\n2)INSERT AT THE BEGINNING\n3)INSERT AT THE END\n4)INSERT AT A GIVEN POSITION\n5)DISPLAY\n6)EXIT\n");
	while(1)
	{
	printf("\nenter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("enter the number of nodes you want to enter in the linked list \n");
			scanf("%d",&n);
			create(n);
			break;
		case 2:			
			printf("enter the data you want to insert at the beginning \n");
			scanf("%d",&n1);
			insertbeg(n1);
			break;
		case 3:
			printf("enter the data you want to insert at th end \n");
			scanf("%d",&n2);
			insertend(n2);
			break;
		case 4:
			printf("enter the data and position where you want to insert \n");
			scanf("%d%d",&n3,&p);
			insertpos(n3,p);
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("sorry wrong input please enter again \n");
			
	}
}
	return(0);
}
