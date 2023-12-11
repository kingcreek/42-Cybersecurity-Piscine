#include <string.h>
#include <stdio.h>

int main()
{
	char in[100];
	char *pass = "__stack_check";
	printf("Please enter key: ");
	scanf("%s", in);
	int result = strcmp(in, pass);
	if (result == 0)
	{
		printf("Good job.\n");
	}
	else
	{
		printf("Nope.\n");
	}
	return 0;
}