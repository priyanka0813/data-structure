//single linked list
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
	printf("\n the beginning node %d is successfully deleted \n",todelete->data);
	free(todelete);
	}
}

void deleteend()
{
	struct node*todelete,*secondlast;
	
	if(head==NULL)
	{
			printf("nothing to delete\n");
	}
	else
	{
		todelete=head;
		secondlast=head;
		while(todelete->next!=NULL)
		{
			secondlast=todelete;
			todelete=todelete->next;	
		}
		secondlast->next=NULL;		//this is where the last node that os 'todelete' is isolated from the linked list
		
	}
		printf("\nthe last node %d is successfully deleted",todelete->data);
		free(todelete);
}

void deletepos(int p)
{
	struct node*todelete,*helper;
	if(head==NULL)
	{
		printf("nothing to delete\n");
	}
	else
	{
		helper=head;
		while(p- 2>0) //note that here p is the real position position counting starts from 1.
		{
			helper=helper->next; //helper will keep on jumping from the head in order to reach till the node prior to the node which needs to be deleted
			p--;
		}
		todelete=helper->next; //todelete was pointing to nowhere previously,now it is pointing to the node which is to be deleted   
		helper->next=todelete->next;
	}
	printf("\nsuccessfully delted the node %d from position %d\n",todelete->data,p);
	free(todelete);
	
}

void deletebykey(int n) //key means data of the node that is to be deleted. here data n. that is the key ispassed by the user
{
	struct node*helper,*todelete;
	if(head==NULL)
	{
			printf("nothing to delete\n");
	}
	else
	{
		helper=head;
		while((helper->next)->data!=n)
		{
			helper=helper->next;
		}
		todelete=helper->next;
		helper->next=todelete->next;
	}
	printf("the node having data %d is delted ",todelete->data);
	free(todelete);
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
	int n,p,n1;
	printf("your menu is \n1)CREATE LINKED LIST\n2)DELETE FROM THE BEGINNING\n3)DELETE FROM THE END\n4)DELETE FROM A GIVEN POSITION\n5)DISPLAY\n6)EXIT\n7)DELETE BY KEY\n");
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
		case 7:
			printf("enter the key of the node that you want to delete \n");
			scanf("%d",&n1);
			deletebykey(n1);
			break;
		default:
			printf("sorry wrong input please enter again \n");
			
	}
}
	return(0);
}
