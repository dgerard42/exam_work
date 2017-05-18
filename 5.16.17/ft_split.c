
#include <stdlib.h>

int				ft_wordcount(char *str)
{
	int words;
	char *tmp;

	words = 0;
	tmp = str;
	while (*tmp)
	{
		while (*tmp == ' ' || *tmp == '\n' || *tmp == '\t')
			tmp++;
		if (*tmp && *tmp != ' ' && *tmp != '\n' && *tmp != '\t')
		{
			while (*tmp && *tmp != ' ' && *tmp != '\n' && *tmp != '\t')
				tmp++;
			words++;
		}
	}
	return (words);	
}

int				ft_lettercount(char *str)
{
	int letters;
	char *tmp;

	letters = 0;
	tmp = str;
	while (*tmp && *tmp != ' ' && *tmp != '\n' && *tmp != '\t')
	{
		letters++;
		tmp++;
	}
	return (letters);

}

char			**ft_split(char *str)
{
	int i;
	int j;
	int words;
	int letters;
	char **res;

	i = 0;
	j = 0;
	words = ft_wordcount(str);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	res[words] = NULL;
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		if (*str != '\0')
		{
			letters = ft_lettercount(str);
			res[i] = (char *)malloc(sizeof(char) * (letters + 1));
			res[i][letters] = '\0';
		}
		while (*str != '\0' && *str != ' ' && *str != '\n' && *str != '\t')
			res[i][j++] = *str++;
		i++;
		j = 0;
	}
	return (res);
}
