#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*head=NULL,*last=NULL;

void create(int n) //the code for the creation of the double linked list will be different from that of single linked list
{
	struct node*newnode;
	int i;
	head=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of node 1 \t");
	scanf("%d",&head->data);
	head->prev=NULL;
	head->next=NULL;
	last=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node %d \t",i);
		scanf("%d",&newnode->data);
		newnode->prev=last;
		newnode->next=NULL;
		last->next=newnode;
		last=newnode;
	}
	printf("double linked list is successfully created.\n");
	
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

void traverse()  //traverse means to display it from the end.
{
	struct node*temp;
	if(last==NULL)
	{
		printf("\n sorry the single linked list is empty nothing to display\n");
	}
	else
	{
	temp=last;
	printf("<");
	while(temp!=NULL)
	{
		printf("--");
		printf("%d",temp->data);
		temp=temp->prev;
		
	}
	printf("-->");
	}
}


void insertbeg(int n1)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=n1;
	newnode->prev=NULL; //extraline added with respictive to single linked list.
	newnode->next=head;
	head->prev=newnode; //extraline added with respect to singly linked list
	head=newnode;
	printf("\n newnode issuccessfully inserted at the beginning \n");
}


void insertend(int n2)  //with respect to single linked list the number code lines required will be less.
{
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=n2;
	newnode->prev=last;
	newnode->next=NULL;
	last->next= newnode;
	last=newnode;
	printf("node successfully added at the end");
}

void insertpos(int n3,int p)
{
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n3;
	newnode->next=NULL;
	newnode->prev=NULL;
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
		newnode->prev=temp;
		temp->next->prev=newnode;
		temp->next=newnode;		//newnode will be placed after temp that is next of temp will now point to newnode
	}
	printf("\nnode successfully entered at position %d",p);
	
}

int main()
{
	int choice;
	int n,n1,n2,n3,p;
	printf("your menu is \n1)CREATE LINKED LIST\n2)INSERT AT THE BEGINNING\n3)INSERT AT THE END\n4)INSERT AT A GIVEN POSITION\n5)DISPLAY\n6)traverse\n7)EXIT\n");
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
			traverse();
			break;
		case 7:
			exit(0);
			break;
		default:
			printf("sorry wrong input please enter again \n");
			
	}
}
	return(0);
}
