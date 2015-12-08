/* to find last n lines of a file*/
#include<stdio.h>
int main()
{
	FILE *f;
	char str[1000], ch;
	int count = 0, n, pos, begin, end;
	printf("enter file name along with path\n");
	scanf("%s", str);
	f = fopen(str, "r");
	if (f == NULL)
	{
		printf("can't be opened\n");
		return 1;
	}
	printf("\n Enter no of lines from last u want to print:");
	scanf("%d", &n);
	begin = ftell(f);
	fseek(f, 0, SEEK_END);
	end = ftell(f);
	pos = ftell(f);
	while (count <= n)
	{
		pos = ftell(f);
		if (pos < begin)
			break;
		ch = fgetc(f);
		if (ch == '\n')
			count++;
		fseek(f, pos - 1, begin);
	}
	while ((ch = fgetc(f)) != EOF)
		putchar(ch);
	fclose(f);
	return 0;
}