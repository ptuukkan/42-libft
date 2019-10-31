/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:54:08 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 12:24:54 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <ctype.h>

void	ft_toupper2(char *c)
{
	if (*c >= 97 && *c <= 122)
		*c = *c - 32;
}

void	ft_strtoupper2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_toupper2(&str[i]);
		i++;
	}
}

void	ft_lsttoupper2(t_list *elem)
{
	ft_strtoupper2((char *)elem->content);
}

void	ft_strcapitalize2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_toupper2(&str[i]);
		i++;
		while (str[i] != '\0' && ft_isalnum(str[i]) == 1)
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
		while (str[i] != '\0' && ft_isalnum(str[i]) == 0)
			i++;
	}
}

t_list	*ft_lstcapitalize2(t_list *elem)
{
	t_list	*lst;

	lst = ft_lstnew(elem->content, elem->content_size);
	if (lst == NULL)
		return (NULL);
	ft_strcapitalize2((char *)lst->content);
	return (lst);
}

void	printarray(int *arr, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		printf("%d", arr[i]);
		i++;
	}
}
void	ft_iteritest(unsigned int i, char *c)
{
	*c = *c + i;
}

char	ft_mapitertest(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

char	ft_mapiteritest(unsigned int i, char c)
{
	return (c + i);
}

void	lst_free(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void	ft_lstdel2(t_list **alst, void(*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst == NULL)
		return;
	while (*alst != NULL)
	{
		if ((*alst)->content != NULL)
			(*del)((*alst)->content, (*alst)->content_size);
		temp = *alst;
		*alst = (*alst)->next;
		free(temp);
		temp = NULL;
	}
}

void	test_part2(void)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(5);
	while (i < 5)
	{
		if (str[i] != '\0')
			break ;
		i++;
	}
	if (i == 5)
		printf("ft_memalloc OK\t\n");
	else
	{
		printf("ft_memalloc FAIL, aborting rest part2 tests\t\n");
		return ;
	}
	ft_memdel((void **)&str);
	if (str == NULL)
		printf("ft_memdel OK\t\n");
	else
	{
		printf("ft_memdel FAIL, aborting rest part2 tests\t\n");
		return ;
	}
	str = ft_strnew(4);
	i = 0;
	if (str)
	{
		while (i < 5)
		{
			if (str[i] != '\0')
				break ;
			i++;
		}
		if (i == 5)
			printf("ft_strnew OK\t\n");
		else
		{
			printf("ft_strnew FAIL, aborting rest part2 tests\t\n");
			return ;
		}
	}
	ft_strdel(&str);
	if (str == NULL)
		printf("ft_strdel OK\t\n");
	else
	{
		printf("ft_strdel FAIL, aborting rest part2 tests\t\n");
		return ;
	}
	str = ft_strnew(4);
	if (!str)
		return ;
	str = strcpy(str, "toto");
	if (strcmp(str, "toto") == 0)
	{
		ft_striter(str, &ft_toupper2);
		if (strcmp(str, "TOTO") == 0)
			printf("ft_striter OK\t\n");
		else
			printf("ft_striter FAIL\t\n");
		ft_strclr(str);
		i = 0;
		while (i < 5)
		{
			if (str[i] != '\0')
				break ;
			i++;
		}
		if (i == 5)
			printf("ft_strclr OK\t\n");
		else
			printf("ft_strclr FAIL\t\n");
	}
	else
		printf("ft_strclr FAIL\t\n");
	str = strcpy(str, "toto");
	ft_striteri(str, &ft_iteritest);
	if (strcmp(str, "tpvr") == 0)
		printf("ft_striteri OK\t\n");
	else
		printf("ft_striteri FAIL\t\n");
	str = strcpy(str, "toto");
	char *str2;
	str2 = ft_strmap(str, &ft_mapitertest);
	if (strcmp(str, "toto") == 0 &&
		strcmp(str2, "TOTO") == 0)
		printf("ft_strmap OK\t\n");
	else
		printf("ft_strmap FAIL\t\n");
	str = strcpy(str, "toto");
	str2 = ft_strmapi(str, &ft_mapiteritest);
	if (strcmp(str, "toto") == 0 &&
		strcmp(str2, "tpvr") == 0)
		printf("ft_strmapi OK\t\n");
	else
		printf("ft_strmapi FAIL\t\n");
	if (ft_strequ("toto", "toto") == 1 &&
		ft_strequ("doggoabba", "doggo") == 0)
		printf("ft_strequ OK\t\n");
	else
		printf("ft_strequ FAIL\t\n");
	if (ft_strnequ("doggo", "dog", 3) == 1 &&
		ft_strnequ("abcdf", "abc", 5) == 0 &&
		ft_strnequ("toto", "toto", 10) == 1)
		printf("ft_strnequ OK\t\n");
	else
		printf("ft_strnequ FAIL\t\n");
	free(str);
	str = ft_strsub("abcdefghij", 3, 5);
	if (!str)
	{
		printf("ft_strsub FAIL\t\n");
		return ;
	}
	if (strcmp(str, "defgh") == 0)
		printf("ft_strsub OK\t\n");
	else
		printf("ft_strsub FAIL\t\n");
	free(str);
	str = ft_strjoin("toto", "africa");
	if (!str)
	{
		printf("ft_strjoin FAIL\t\n");
		return ;
	}
	if (strcmp(str, "totoafrica") == 0)
		printf("ft_strjoin OK\t\n");
	else
		printf("ft_strjoin FAIL\t\n");
	free(str);
	free(str2);
	str = ft_strnew(50);
	if (!str)
		return ;
	str = strcpy(str, "    \ttoto\t   \t");
	str2 = ft_strtrim(str);
	if (!str2)
	{
		printf("ft_strtrim FAIL\t\n");
		return ;
	}
	if (strcmp(str2, "toto") == 0 &&
		strcmp(str, "    \ttoto\t   \t") == 0)
		printf("ft_strtrim OK\t\n");
	else
		printf("ft_strtrim FAIL\t\n");
	free(str2);
	free(str);
	char **tab;
	tab = ft_strsplit("*hello*fellow***students**", '*');
	if (!tab)
	{
		printf("ft_strsplit FAIL\t\n");
		return ;
	}
	if (strcmp(tab[0], "hello") == 0 &&
		strcmp(tab[1], "fellow") == 0 &&
		strcmp(tab[2], "students") == 0 &&
		tab[3] == 0)
		printf("ft_strsplit OK\t\n");
	else
		printf("ft_strsplit FAIL\t\n");
	str = ft_itoa(682001);
	str2 = ft_itoa(-2147483648);
	if (!str || !str2)
	{
		printf("ft_itoa FAIL\t\n");
		return ;
	}
	if (strcmp(str, "682001") == 0 &&
		strcmp(str2, "-2147483648") == 0)
		printf("ft_itoa OK\t\n");
	else
		printf("ft_itoa FAIL\t\n");



}



void	test_lst(void)
{
	t_list	*lst;
	t_list	*temp;
	int		i;
	char	str[] = "toto";

	i = 42;
	lst = ft_lstnew(str, sizeof(str));
	if (lst == NULL)
		return;
	if (strcmp("toto", lst->content) == 0 && lst->content_size == 5 && lst->next == NULL)
		printf("ft_lstnew OK\t\n");
	else
	{
		printf("ft_lstnew FAIL, aborting following lst tests\n");
		return;
	}
	ft_lstadd(&lst, ft_lstnew(&i, sizeof(i)));
	if (*(int *)lst->content == 42 && strcmp("toto", lst->next->content) == 0)
		printf("ft_lstadd OK\t\n");
	else
	{
		printf("ft_lstadd FAIL, aborting following lst tests\n");
		return;
	}
	ft_lstadd(&lst, ft_lstnew("tatata", 7));
	temp = lst;
	lst = lst->next;
	ft_lstdelone(&temp, &lst_free);
	if (temp != NULL)
	{
		printf("ft_lstdelone FAIL, aborting following lst tests\n");
		return;
	}
	temp = lst;
	lst = lst->next;
	ft_lstdelone(&temp, &lst_free);
	if (temp != NULL)
	{
		printf("ft_lstdelone FAIL, aborting following lst tests\n");
		return;
	}
	if (strcmp("toto", lst->content) == 0 && lst->content_size == 5 && lst->next == NULL)
		printf("ft_lstdelone OK\t\n");
	else
	{
		printf("ft_lstdelone FAIL, aborting following lst tests\n");
		return;
	}
	ft_lstadd(&lst, ft_lstnew("tatata", 7));
	ft_lstadd(&lst, ft_lstnew("doggo", 6));
	ft_lstadd(&lst, ft_lstnew("totoro", 7));
	ft_lstiter(lst, &ft_lsttoupper2);
	if (strcmp("TOTORO", lst->content) == 0 &&
		strcmp("DOGGO", lst->next->content) == 0 &&
		strcmp("TATATA", lst->next->next->content) == 0 &&
		strcmp("TOTO", lst->next->next->next->content) == 0)
		printf("ft_lstiter OK\t\n");
	else
		printf("ft_lstiter FAIL\t\n");
	temp = ft_lstmap(lst, &ft_lstcapitalize2);
	if (strcmp("TOTORO", lst->content) == 0 &&
		strcmp("Totoro", temp->content) == 0 &&
		strcmp("Doggo", temp->next->content) == 0 &&
		strcmp("Tatata", temp->next->next->content) == 0 &&
		strcmp("Toto", temp->next->next->next->content) == 0)

	{
		printf("ft_lstmap OK\t\n");
		ft_lstdel2(&temp, &lst_free);
	}
	else
		printf("ft_lstmap FAIL\t\n");
	ft_lstdel(&lst, &lst_free);
	if (lst == NULL)
		printf("ft_lstdel OK\t\n");
	else
		printf("ft_lstdel FAIL\t\n");
}

void	test_bonuslst(void)
{
	t_list	*lst;
	char	*str;
	void	*data;
	size_t	size;

	lst = NULL;
	ft_lstadd(&lst, ft_lstnew("tatata", 7));
	ft_lstadd(&lst, ft_lstnew("doggo", 6));
	ft_lstapp(&lst, ft_lstnew("totoro", 7));
	if (strcmp("doggo", lst->content) == 0 &&
		strcmp("tatata", lst->next->content) == 0 &&
		strcmp("totoro", lst->next->next->content) == 0)
		printf("ft_lstapp OK\t\n");
	else
		printf("ft_lstapp FAIL\t\n");
	size = ft_lstsize(lst);
	if (size == 20)
		printf("ft_lstsize OK\t\n");
	else
		printf("ft_lstsize FAIL\t\n");
	str = ft_lstfold(&lst, &ft_lstjoin);
	if (strcmp("doggotatatatotoro", str) == 0)
		printf("ft_lstfold OK\t\nft_lstjoin OK\t\n");
	else
		printf("ft_lstfold FAIL\t\nft_lstjoin FAIL\t\n");
	lst = NULL;
	ft_lstadd(&lst, ft_lstnew("tatata", 7));
	ft_lstadd(&lst, ft_lstnew("doggo", 6));
	ft_lstapp(&lst, ft_lstnew("totoro", 7));
	data = ft_lstpop(&lst);
	if (strcmp("doggo", data) == 0 &&
		strcmp("tatata", lst->content) == 0)
		printf("ft_lstpop OK\t\n");
	else
		printf("ft_lstpop FAIL\t\n");
}

void	test_tolower(void)
{
	if (ft_tolower('a') == 'a' &&
		ft_tolower('A') == 'a' &&
		ft_tolower('5') == '5')
	{
		printf("ft_tolower OK\t\n");
	}
	else
		printf("ft_tolower FAIL\t\n");
}

void	test_toupper(void)
{
	if (ft_toupper('a') == 'A' &&
		ft_toupper('A') == 'A' &&
		ft_toupper('5') == '5')
	{
		printf("ft_toupper OK\t\n");
	}
	else
		printf("ft_toupper FAIL\t\n");
}

void	test_isprint(void)
{
	int	i;
	int	ret;
	int	ret2;

	i = 0;
	ret = 0;
	ret2 = 0;
	while (i < 128)
	{
		ret += isprint(i);
		i++;
	}
	i = 0;
	while (i < 128)
	{
		ret2 += ft_isprint(i);
		i++;
	}
	if (ret == ret2)
		printf("ft_isprint OK\t\n");
	else
	{
		printf("ft_isprint FAIL\t\n");
		printf("is %d", ret2);
		printf("should be %d\n", ret);
	}
}

void	test_isascii(void)
{
	int	i;
	int	ret;
	int	ret2;

	i = 0;
	ret = 0;
	ret2 = 0;
	while (i < 128)
	{
		ret += isascii(i);
		i++;
	}
	i = 0;
	while (i < 128)
	{
		ret2 += ft_isascii(i);
		i++;
	}
	if (ret == ret2)
		printf("ft_isascii OK\t\n");
	else
		printf("ft_isascii FAIL\t\n");
}

void	test_isalnum(void)
{
	int	ret;
	int	ret2;

	ret = isalnum('a');
	ret += isalnum('A');
	ret += isalnum('5');
	ret += isalnum('#');
	ret2 = ft_isalnum('a');
	ret2 += ft_isalnum('A');
	ret2 += ft_isalnum('5');
	ret2 += ft_isalnum('#');
	if (ret == ret2)
		printf("ft_isalnum OK\t\n");
	else
		printf("ft_isalnum FAIL\t\n");
}

void	test_isdigit(void)
{
	int	ret;
	int	ret2;

	ret = isdigit('a');
	ret += isdigit('A');
	ret += isdigit('5');
	ret2 = ft_isdigit('a');
	ret2 += ft_isdigit('A');
	ret2 += ft_isdigit('5');
	if (ret == ret2)
		printf("ft_isdigit OK\t\n");
	else
		printf("ft_isdigit FAIL\t\n");
}

void	test_isalpha(void)
{
	int	ret;
	int	ret2;

	ret = isalpha('a');
	ret += isalpha('A');
	ret += isalpha('5');
	ret2 = ft_isalpha('a');
	ret2 += ft_isalpha('A');
	ret2 += ft_isalpha('5');
	if (ret == ret2)
		printf("ft_isalpha OK\t\n");
	else
		printf("ft_isalpha FAIL\t\n");
}

void	test_atoi(void)
{
	if (atoi("  -8401") == ft_atoi("  -8401"))
		printf("ft_atoi test1 OK, ");
	else
		printf("ft_atoi test1 FAIL, ");
	if (atoi("12612473") == ft_atoi("12612473"))
		printf("test2 OK\n");
	else
		printf("test2 FAIL\n");
}

void	test_strncmp(void)
{
	int	ret2;
	int	result;

	result = 0;
	ret2 = ft_strncmp("toto", "toto", 4);
	if (ret2 == 0)
		result++;
	ret2 = ft_strncmp("a", "h", 1);
	if (ret2 < 0)
		result++;
	ret2 = ft_strncmp("doggo", "dbc", 3);
	if (ret2 > 0)
		result++;
	if (result == 3)
		printf("ft_strncmp OK\t\n");
	else
		printf("ft_strncmp FAIL\t\n");
}

void	test_strcmp(void)
{
	int	result;
	int	ret2;

	result = 0;
	ret2 = ft_strcmp("toto", "toto");
	if (ret2 == 0)
		result++;
	ret2 = ft_strcmp("a", "h");
	if (ret2 < 0)
		result++;
	ret2 = ft_strcmp("doggo", "dbc");
	if (ret2 > 0)
		result++;
	if (result == 3)
		printf("ft_strcmp OK\t\n");
	else
		printf("ft_strcmp FAIL\t\n");
}

void	test_strnstr(void)
{
	char	*ptr;
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	ptr = ft_strnstr(buf, "deux", 10);
	if (ptr && strcmp(ptr, "deux 9") == 0)
		printf("ft_strnstr test1 OK, ");
	else
		printf("ft_strnstr test1 FAIL, ");
	ptr = ft_strnstr(buf, "", 6);
	if (ptr && strcmp(ptr, buf) == 0)
		printf("test2 OK, ");
	else
		printf("test2 FAIL, ");
	ptr = ft_strnstr(buf, "9", 10);
	if (ptr && strcmp(ptr, "9") == 0)
		printf("test3 OK, ");
	else
		printf("test3 FAIL, ");
	ptr = ft_strnstr(buf, "9", 8);
	if (ptr == NULL)
		printf("test4 OK, ");
	else
		printf("test4 FAIL, ");
	ptr = ft_strnstr(buf, "deux", 5);
	if (ptr == NULL)
		printf("test5 OK, ");
	else
		printf("test5 FAIL, ");

	const char *largestring = "ozarabozaraboze123";
	const char *smallstring = "ozaraboze";

	ptr = ft_strnstr(largestring, smallstring, 15);
	if (ptr != NULL && strcmp(ptr, "ozaraboze123") == 0)
		printf("test6 OK\n");
	else
		printf("test6 FAIL\n");
}

void	test_strstr(void)
{
	const char *haystack = "MZIRIBMZIRIBMZP";
	const char *needle = "MZIRIBMZP";
	char	*ret;
	char	*ret2;

	ret = strstr(haystack, needle);
	ret2 = ft_strstr(haystack, needle);
	if (strcmp(ret, ret2) == 0)
		printf("ft_strstr OK\t\n");
	else
		printf("ft_strstr FAIL\t\n");
}

void	test_strrchr(void)
{
	const char str[] = "bonjour";
	const char str2[] = "bonjour";
	const char ch = 'b';
	char *ret;
	char *ret2;

	ret = strrchr(str, ch);
	ret2 = ft_strrchr(str2, ch);
	if (strcmp(ret, ret2) == 0)
	{
		printf("ft_strrchr OK\t\n");
	}
	else
	{
		printf("ft_strrchr FAIL\t\n");
		printf("is %s", ret2);
		printf(" should be %s\n", ret);
	}
}

void	test_strchr(void)
{
	const char str[] = "http://www.tutorialspoint.com";
	const char str2[] = "http://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;
	char *ret2;

	ret = strchr(str, ch);
	ret2 = ft_strchr(str2, ch);
	if (strcmp(ret, ret2) == 0)
		printf("ft_strchr OK\t\n");
	else
		printf("ft_strchr FAIL\t\n");
}

void	test_strncat(void)
{
	char	*dest;
	char	*dest2;

	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = strcpy(dest, "This is destination");
	dest2 = strcpy(dest2, "This is destination");
	dest = strncat(dest, "toto", 2);
	dest2 = ft_strncat(dest2, "toto", 2);
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_strncat OK\t\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_strncat FAIL\t\n");
}

void	test_strlcat(void)
{
	char	*dest;
	char	*dest2;
	size_t	ret;
	size_t	ret2;

	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	memset(dest, 0, 50);
	memset(dest2, 0, 50);
	dest = strcpy(dest, "This is destination");
	dest2 = strcpy(dest2, "This is destination");
	ret = ft_strlcat(dest, "toto", 10);
	ret2 = ft_strlcat(dest2, "toto", 10);
	if (strcmp(dest, dest2) == 0 &&
		ret == ret2)
	{
		printf("ft_strlcat OK\t\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_strlcat FAIL\t\n");
}

void	test_strcat(void)
{
	char	*dest;
	char	*dest2;

	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = strcpy(dest, "This is destination");
	dest2 = strcpy(dest2, "This is destination");
	dest = strcat(dest, "toto");
	dest2 = ft_strcat(dest2, "toto");
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_strcat OK\t\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_strcat FAIL\t\n");
}

void	test_strncpy(void)
{
	char	*str;
	char	*str2;
	str = strdup("This string");
	str2 = strdup("This string");
	str = strncpy(str, "toto", 8);
	str2 = ft_strncpy(str2, "toto", 8);
	if (strcmp(str, str2) == 0)
	{
		printf("ft_strncpy OK\t\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_strncpy FAIL\t\n");
}

void	test_strcpy(void)
{
	char	*str;
	char	*str2;
	str = strdup("This string");
	str2 = strdup("This string");
	str = strcpy(str, "toto");
	str2 = ft_strcpy(str2, "toto");
	if (strcmp(str, str2) == 0)
	{
		printf("ft_strcpy OK\t\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_strcpy FAIL\t\n");
}

void	test_strdup(void)
{
	char	*str;
	char	*str2;
	str = strdup("This string");
	str2 = ft_strdup("This string");
	str = strncpy(str, "toto", 4);
	str2 = strncpy(str2, "toto", 4);
	if (strcmp(str, str2) == 0)
	{
		printf("ft_strdup OK\t\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_strdup FAIL\t\n");
}

void	test_strlen(void)
{
	int	ret;
	int	ret2;

	ret = strlen("toto");
	ret2 = ft_strlen("toto");
	if (ret == ret2)
		printf("ft_strlen OK\t\n");
	else
		printf("ft_strlen FAIL\t\n");
}

void	test_memcmp(void)
{
	int	result;
	int	ret2;
	int	i;
	int	i2;

	i = 42;
	i2 = 42;
	result = 0;
	ret2 = ft_memcmp("toto", "toto", 4);
	if (ret2 == 0)
		result++;
	ret2 = ft_memcmp("a", "h", 1);
	if (ret2 < 0)
		result++;
	ret2 = ft_memcmp("doggo", "dbc", 3);
	if (ret2 > 0)
		result++;

	ret2 = ft_memcmp(&i, &i2, sizeof(i));
	if (ret2 == 0)
		result++;
	if (result == 4)
		printf("ft_memcmp OK\t\n");
	else
	{
		printf("ft_memcmp FAIL\t\n");
	}
}

void	test_memchr(void)
{
	const char str[] = "http://www.tutorialspoint.com";
	const char str2[] = "http://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;
	char *ret2;

	ret = memchr(str, ch, strlen(str));
	ret2 = ft_memchr(str2, ch, strlen(str2));
	if (strcmp(ret, ret2) == 0)
		printf("ft_memchr OK\t\n");
	else
		printf("ft_memchr FAIL\t\n");
}

void	test_memmove(void)
{
	char	src[] = "This test string";
	char	src2[] = "This test string";
	char	*dest;
	char	*dest2;
	dest = src + 1;
	dest2 = src2 + 1;
	dest = memmove(dest, src, 5);
	dest2 = ft_memmove(dest2, src2, 5);
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_memmove OK\t\n");
	}
	else
		printf("ft_memmove FAIL\t\n");
}

void	test_memccpy(void)
{
	const char	src[50] = "This test string";
	char		*dest;
	const char	src2[50] = "This test string";
	char		*dest2;
	char		*dptr;
	char		*dptr2;

	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	memset(dest, '\0', 50);
	memset(dest2, '\0', 50);
	dest = strcpy(dest, "byebyebyebyebyebyebyebye");
	dest2 = strcpy(dest2, "byebyebyebyebyebyebyebye");
	dptr = (char *)memccpy(dest, src, 'e', 11);
	dptr2 = (char *)ft_memccpy(dest2, src2, 'e', 11);
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_memccpy OK\t\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_memccpy FAIL\t\n");
}

void	test_memcpy(void)
{
	const char	src[50] = "This test string";
	char		*dest;
	const char	src2[50] = "This test string";
	char		*dest2;
	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = (char *)memcpy(dest, src, sizeof(src));
	dest2 = (char *)ft_memcpy(dest2, src2, sizeof(src2));
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_memcpy OK\t\n");
		free(dest);
		free(dest2);
	}
	else
	{
		printf("ft_memcpy FAIL\t\n");
	}



}

void	test_bzero(void)
{
	char	*str;
	char	*str2;
	str = strdup("This string");
	str2 = strdup("This string");
	ft_bzero(str, 5);
	ft_bzero(str2, 5);
	if (memcmp(str, str2, 11) == 0)
	{
		printf("ft_bzero OK\t\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_bzero FAIL\t\n");
}

void	test_memset(void)
{
	char	*str;
	char	*str2;
	str = strdup("This string");
	str2 = strdup("This string");
	str = (char *)memset(str, '$', 5);
	str2 = ft_memset(str2, '$', 5);
	if (strcmp(str, str2) == 0)
	{
		printf("ft_memset OK\t\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_memset FAIL\t\n");
}

int		main(void)
{

	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strstr();
	test_strnstr();
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_isalpha();
	test_isalnum();
	test_isdigit();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();

	test_part2();
	test_lst();
	test_bonuslst();


	return (0);
}
