/*to add lists using linked list concept*/
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *add(struct node *head1, struct node *head2)
{
	NODE *temp1, *temp2, *head3=NULL, *curr, *prev;
	int n;
	temp1 = head1;
	temp2 = head2;
	while ((temp1 != NULL) || (temp2 != NULL))
	{
		curr = (struct node *)malloc(sizeof(struct node));
		if (temp1 != NULL&&temp2 != NULL)
		{
			n = temp1->data + temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1 != NULL)
		{
			n = temp1->data;
			temp1 = temp1->next;
		}
		else
		{
			n = temp2->data;
			temp2 = temp2->next;
		}
		curr->data = n;
		curr->next = NULL;
		if (head3 == NULL)
		{
			head3 = curr;
			prev = curr;
		}
		else
		{
			prev->next = curr;
			prev = curr;
		}
	}
	return head3;
}
NODE *create(int n1)
{
	int i, n;
	NODE *curr, *first = NULL, *prev;
	printf("enter the numbers to add into list1\n");
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &n);
		curr = (struct node *)malloc(sizeof(struct node));
		curr->data = n;
		curr->next = NULL;
		if (first == NULL)
		{
			first = curr;
			prev = curr;
		}
		else
		{
			prev->next = curr;
			prev = curr;
		}
	}
	return first;
}
int main()
{
	NODE *head1, *head2,*head3,*temp;
	int n1, n2;
	printf("enter the number of elements in the first list\n");
	scanf("%d", &n1);
	if (n1 <= 0)
	{
		printf("INVALID INPUT \n");
		return 1;
	}
	head1 = create(n1);
	printf("enter the number of elements in the first list\n");
	scanf("%d", &n2);
	if (n2 <= 0)
	{
		printf("INVALID INPUT\n");
		return 1;
	}
	head2 = create(n2);
	head3 = add(head1, head2);
	temp = head3;
	printf("the values after adding the two lists:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return 0;
}