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

//function to reverse the linked list

void reverse()
{
	struct node*current=head,*prev=NULL,*next=NULL;//current pointer is initiaised as head and prev and next is initialised as NULL
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev; //inorder to follow how it is happening please see the linked given in the description
}

int main()
{
	int n;
	printf("enter the number of elements you want in the list");
	scanf("%d",&n);
	create(n);
	printf("the resutant list is \n");
	display();
	printf("the resutant reversed list is \n");
	reverse();
	display();
	return(0);
}
