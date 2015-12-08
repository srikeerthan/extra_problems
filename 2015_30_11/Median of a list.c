/*to find median of a list using linked list*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *link;
}NODE;
NODE *list=NULL;
int count = 0;
void median()
{
	NODE *temp,*lptr=NULL;
	int m, c = 0, vl;
	float avg=0;
	m = count / 2;
	if (list == NULL)
	{
		printf("there are no elements in the list\n");
		return;
	}
	do
	{
		temp = list;
		while (temp->link != lptr)
		{
			if (temp->value > temp->link->value)
			{
				vl = temp->value;
				temp->value = temp->link->value;
				temp->link->value = vl;
			}
			temp = temp->link;
		}
		c++;
		if (count%2!=0)
		{
			if (c==m+1)
				printf("median is =%d\n", temp->value);
		}
		else
		{
			if (c == m)
			{
				avg += temp->value;
				lptr = temp;
				continue;
			}
			else if (c == m + 1)
			{
				avg += temp->value;
				printf("median is =%f\n", avg / 2);
			}
		}
		lptr = temp;
	} while (c!=count);
}
NODE  *add(struct node *prev)
{
	int n;
	NODE *temp;
	printf("enter the number to add into the lsit\n");
	scanf("%d", &n);
	temp = (struct node *)malloc(sizeof(struct node));
	temp->value = n;
	temp->link = NULL;
	if (list == NULL)
	{
		list = temp;
	}
	else
	{
		prev->link = temp;
	}
	count++;
	return temp;
}
void menu()
{
	printf("enter 1->to add an element to the list\n");
	printf("enter 2->to find median of list\n");
	printf("enter 3->to exit\n");
}
int main()
{
	int choice;
	char ch;
	NODE *prev = NULL;
	do
	{
		menu();
		printf("enter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
				prev=add(prev);
				break;
		case 2:
			median();
			break;
		case 3:
			exit(1);
			break;
		default:
			printf("not a valid choice\n");
		}
		printf("do you want to continue (yes->Y/y)(No->N/n)\n");
		flushall();
		scanf("%c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return 0;
}