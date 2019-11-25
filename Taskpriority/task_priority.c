#include <stdio.h>
void main()
{
	int input[8];
	int i, in, pri;
	printf("Enter 8 bit binary no.\n");
	scanf("%d", &in);

	for (i = 8; i >= 1; i--)
	{
		input[i] = in % 10;
		in = in / 10;
	}
	for (i = 8; i >= 1; i--)
	{
		if (input[i] == 1) {
			pri = i;
			break;
		}

	}
	printf("Task to be schedule=%d\n", pri);

}