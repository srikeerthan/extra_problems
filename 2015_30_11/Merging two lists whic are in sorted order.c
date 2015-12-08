/*to merge two lists into one list which are in sorted order*/
#include<stdio.h>
typedef struct node
{
	int value;
	struct node *next;
}NODE;
NODE  *merge(NODE *list1, NODE *list2)
{
	NODE *temp1,*temp2,*temp3,*prev1,*prev2;
	temp2 = prev2 = list2;
	temp1 = prev1 = list1;
		while (temp1!= NULL&&temp2!=NULL)
		{
			if (list2->value <= list1->value)
			{
				temp3 = list2->next;
				list2->next = list1;
				list1 = list2;
				list2 = temp3;
				temp2=prev2 = list2;
				temp1=prev1 = list1;
			}
			else if (list2->value<=temp1->value)
			{
				temp3 = list2->next;
				prev1->next = list2;
				list2->next = temp1;
				temp2=prev2=list2 = temp3;
				temp1 = prev1->next;
			}
			prev1 = temp1;
			if (temp1 != NULL)
				temp1 = temp1->next;
			else
				break;
		}
		if (temp2!=NULL)
		prev1->next = temp2;
	return list1;
}
NODE *create(int n1)
{
	int i,n;
	NODE *curr, *first = NULL,*prev;
	printf("enter the numbers to add into list1\n");
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &n);
		curr = (struct node *)malloc(sizeof(struct node));
		curr->value = n;
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
	NODE *list1 = NULL, *list2 = NULL,*temp;
	int n1, n2;
	printf("enter the number of elements in first list\n");
	scanf("%d", &n1);
	if (n1 <= 0)
	{
		printf("Invalid number\n");
		return 1;
	}
	list1 = create(n1);
	printf("enter the number of elements in second list\n");
	scanf("%d", &n2);
	if (n1 <= 0)
	{
		printf("Invalid number\n");
		return 1;
	}
	list2 = create(n2);
	list1=merge(list1, list2);
	temp = list1;
	while (temp != NULL)
	{
		printf("%d\t",temp->value);
		temp = temp->next;
	}
	return 0;
}