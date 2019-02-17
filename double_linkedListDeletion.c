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

void deletebeg()
{
	struct node*todelete;
	if(head==NULL)
	{
			printf("nothing to delete\n");
	}
	else
	{
	todelete=head;
	head=head->next;
	head->prev=NULL;
	printf("\n the beginning node %d is successfully deleted \n",todelete->data);
	free(todelete);
	}
}

void deleteend()
{
	struct node*todelete;
	if(last==NULL)
	{
			printf("nothing to delete\n");
	}
	else
	{
	todelete=last;
	last=last->prev;
	last->next=NULL;
	printf("\n the beginning node %d is successfully deleted \n",todelete->data);
	free(todelete);
	}
}

void deletepos(int p)
{
	struct node*todelete;
	if(head==NULL)
	{
			printf("nothing to delete\n");
	}
	else
	{
		todelete=head;
		while(p- 1>0)  //nte that p is the real position not index position
		{
			todelete=todelete->next;
			p--;
		}
		todelete->prev->next=todelete->next;
		todelete->next=todelete->prev->next;
		printf("\n the beginning node %d is successfully deleted \n",todelete->data);
		free(todelete);
	}
		
}

int main()
{
	int choice;
	int n,p,n1;
	printf("your menu is \n1)CREATE LINKED LIST\n2)DELETE FROM THE BEGINNING\n3)DELETE FROM THE END\n4)DELETE FROM A GIVEN POSITION\n5)DISPLAY\n6)EXIT\n");
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
			deletebeg();
			break;
		case 3:
			deleteend();
			break;
		case 4:
			printf("enter the position where you want to delte \n");
			scanf("%d",&p);
			deletepos(p);
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


