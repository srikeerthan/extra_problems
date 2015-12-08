/*to add a node to the given circular list*/
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *add(NODE *head, int d)
{
	NODE *temp,*newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = d;
	temp = head;
	while (temp->next != head)
		temp = temp->next;
	temp->next = newnode;
	newnode->next=head;
	return head;
}
NODE *create(int n)
{
	int i, d;
	NODE *head=NULL, *curr, *prev;
	printf("enter the elements in the list\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &d);
		curr = (struct node *)malloc(sizeof(struct node));
		curr->data = d;
		curr->next = NULL;
		if (head == NULL)
		{
			head = prev = curr;
		}
		else
		{
			prev->next = curr;
			prev = curr;
		}
	}
	curr->next = head;
	return head;
}
int main()
{
	NODE *first,*temp;
	int n,value;
	printf("enter the number of elements in the circular list\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("INVALID NUMBER\n");
		return 1;
	}
	first=create(n);
	printf("enter the value to add\n");
	scanf("%d", &value);
	first = add(first, value);
	printf("the elements in the circular list are:");
	temp = first;
	printf("%d\n", temp->data);
	while (temp->next != first)
	{
		temp = temp->next;
		printf("%d\n", temp->data);
	}
	return 0;
}