/* sorting a list which contains both ascending and decending values*/
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *dec;
NODE *reverse(NODE *temp2)
{
	NODE *temp = temp2, *temp1;
	if (temp->next != NULL)
	{
		temp = temp->next;
		temp1 = reverse(temp);
	}
	else
	{
		dec= temp1 = temp;
		return temp1;
	}
	temp1->next = temp2;
	temp1 = temp1->next;
	return temp1;
}
void sort(NODE *head)
{
	NODE *temp,*max,*t;
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
		{
			max = temp;
			temp = temp->next;
			continue;
		}
		else
		{
			t=reverse(temp);
			t->next = NULL;
			break;
		}
	}
	max->next = dec;
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
		printf("INVLID INPUT\n");
		return 1;
	}
	head = create(n);
	sort(head);
	temp = head;
	printf("the values in the list after sorting are:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return 0;
}