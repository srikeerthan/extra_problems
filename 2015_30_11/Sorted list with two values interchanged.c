/* to sort a given list in which all elements are in sorted except two elements interchanged*/
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *sort(NODE *head)
{
	NODE *temp,*prev=head,*m1,*m2,*m3;
	int count=0;
	temp = head->next;
	while (temp != NULL)
	{
		if (prev->data < temp->data)
		{
			prev = temp;
			temp = temp->next;
			continue;
		}
		else if (count == 0)
		{
			m1 = prev;
			prev = temp;
			temp = temp->next;
			count++;
		}
		else if (count == 1)
		{
			m3 = prev;
			m2 = temp;
			prev = temp;
			temp = temp->next;
			count++;
		}
		else
			break;
	}
	if (m1 == head)
	{
		m3->next = m1;
		temp = m2->next;
		m2->next = m1->next;
		m1->next = temp;
		return m2;
	}
	else
	{
		temp = head;
		while (temp->next != m1)
			temp = temp->next;
		temp->next = m2;
		m3->next = m1;
		temp = m2->next;
		m2->next = m1->next;
		m1->next = temp;
		return head;
	}
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
	NODE *head,*temp;
	int n;
	printf("enter number of elements in the list:\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("INVALID INPUT\n");
		return 1;
	}
	head = create(n);
	head=sort(head);
	printf("the values in the list after sorting\n");
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return 0;
}