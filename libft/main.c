#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void printArray(int *arr, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		printf("%d", arr[i]);
		i++;
	}
}

void ft_toupper2(unsigned int i, char *c)
{
	printf("%d\n", i);
	*c = ft_toupper(*c);
}

int	main(void)
{
	
	char *newstr;


	newstr = ft_strtrim("   tot  o  \n  ");
	printf("%s", "aa");
	printf("%s", newstr);
	printf("%s\n", "bb");
	system("pause");
	return 0;
}