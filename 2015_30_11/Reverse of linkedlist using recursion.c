/*to reverse the linked list using recursion*/
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *tail;
NODE *reverse(NODE *temp2)
{
	NODE *temp = temp2,*temp1;
	if (temp->next != NULL)
	{
		temp = temp->next;
		temp1=reverse(temp);
	}
	else
	{
		tail=temp1= temp;
		return temp1;
	}
	temp1->next = temp2;
	temp1 = temp1->next;
	return temp1;
}
NODE *create(int n)
{
	int i, d;
	NODE *head = NULL, *curr, *prev;
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
	return head;
}
int main()
{
	NODE *head,*temp1;
	int n;
	printf("enter the number of elements in the list\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("INVALID NUMBER\n");
		return 1;
	}
	head = create(n);
	head = reverse(head);
	head->next = NULL;
	temp1 = tail;
	printf("the elements in reverse oreder are:\n");
	while (temp1 != NULL)
	{
		printf("%d\n", temp1->data);
		temp1 = temp1->next;
	}
	return 0;
}