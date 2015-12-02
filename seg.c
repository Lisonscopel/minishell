#include <unistd.h>

int main(void)
{
	char *toto = NULL;
	int i = 0;
	while (toto)
	{
		write(1, &toto[i + 2], 1);
		i++;
	}
	return(0);
}
