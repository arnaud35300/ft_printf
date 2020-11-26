#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_charset(char c, char charset)
{
	return (c == charset || c == '\0');
}

static int	get_tab_len(char const *s, char c)
{
	int	i;
	int count;

	i = 1;
	count = 0;
	if (!is_charset(s[0], c))
		count++;
	while (s[i])
	{
		if (is_charset(s[i - 1], c) && !is_charset(s[i], c))
			count++;
		i++;
	}
	return (count);
}

static int	get_char_len(char const *s, char c, int index)
{
	int	i;
	int count;
	int	char_len;

	i = 0;
	count = 0;
	char_len = 0;
	if (!is_charset(s[0], c))
		count++;
	while (s[i])
	{
		if (i > 0)
			if (is_charset(s[i - 1], c) && !is_charset(s[i], c))
				count++;
		if (index + 1 == count && !is_charset(s[i], c))
			char_len++;
		i++;
	}
	return (char_len);
}

static int	assign_char(char *current_s, char const *s, char c, int index)
{
	int	i;
	int count;
	int	char_len;

	i = 0;
	count = 0;
	char_len = 0;
	if (!is_charset(s[0], c))
		count++;
	while (s[i])
	{
		if (i > 0)
			if (is_charset(s[i - 1], c) && !is_charset(s[i], c))
				count++;
		if (index + 1 == count && !is_charset(s[i], c))
		{
			*current_s = s[i];
			current_s++;
		}
		i++;
	}
	*current_s = '\0';
	return (char_len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;

	len = get_tab_len(s, c);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = NULL;
	i = 0;
	while (i < len)
	{
		tab[i] = malloc(sizeof(char) * (get_char_len(s, c, i) + 1));
		if (!tab[i])
			return (NULL);
		assign_char(tab[i], s, c, i);
		i++;
	}
	return (tab);
}

int is_voyelles(char c)
{
	char *v = "aeuioy";
	while (*v)
	{
		if (*v == c)
			return (1);
		++v;
	}
	return (0);
}

int main(void)
{
	char **tab;
	int i = -1;
	int j = -1;
	tab = ft_split("Bah si tu parcours lettres par lettres", ' ');

	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			write(1, &tab[i][j], 1);
			if (tab[i][j + 1] && !is_voyelles(tab[i][j]) && !is_voyelles(tab[i][j + 1]))	
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}

}
