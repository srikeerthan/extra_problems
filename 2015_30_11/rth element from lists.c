/*to find rth element from n1 and n2 tables values which are arranged in sorted order*/
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
void add(int n)
{
	int c=0;
	NODE *curr, *prev,*temp,*prev1;
	curr = (struct node *)malloc(sizeof(struct node));
	curr->data = n;
	curr->next = NULL;
	if (head == NULL)
		head=prev = curr;
			
	else
	{
		temp =prev1= head;
		while (temp != NULL)
		{
			if (n < temp->data)
			{
				if (temp == head)
				{
					curr->next = head;
					head = prev = curr;
					c = 1;
					break;
				}
				else
				{
					curr->next = temp;
					prev1->next = curr;
					prev = curr;
					c = 1;
					break;
				}
			}
			else if (n == temp->data)
			{
				return;
			}
			else
			{
				prev1 = temp;
				temp = temp->next;
				continue;
			}
		}
		if (temp == NULL&&c==0)
		{
			prev1->next = curr;
			prev = curr;
		}
	}
}
void findr(int n1,int n2,int r)
{
	int i;
	for (i = 1; i <= r; i++)
	{
		add(n1 * i);
		add(n2*i);					//if n3,n4...and son given i can add aloop for add functions.
	}
}
int main()
{
	NODE *temp;
	int n1, n2,r,value,count=1;
	printf("enter the elements n1 and n2:\n");
	scanf("%d%d", &n1, &n2);
	if (n1 <= 0 || n2 <= 0)
	{
		printf("INVALID INPUT\n");
		return 1;
	}
	printf("enter the rth element:\n");
	scanf("%d", &r);
	if (r<0)
	{
		printf("INVALID INPUT\n");
		return 1;
	}
	findr(n1,n2, r);
	temp = head;
	while (r != count)
	{
		count++;
		temp = temp->next;
	}
	printf("the rth element is:\n");
	printf("%d\n", temp->data);
	return 0;
}