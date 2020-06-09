#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	static char *a[100];

	int i = -1;
	
	while (++i < 100)
	{
		a[i] = malloc(sizeof(char));
		*(a[i]) = 0;
		if (a[i] != NULL)
			printf("%d\n", i);
	}
}