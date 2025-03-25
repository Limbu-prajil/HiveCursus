#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	*ptr_multi_free(void **ptr1, void **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

static int	int_multi_free(void **ptr1, void **ptr2, int return_value)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (return_value);
}

static int	string_until_newline(char **str, int fd)
{
	char	*buf;
	ssize_t	byt;
	char	*fnd;
	char	*tmp;

	byt = ft_strlen(*str);
	fnd = ft_strchr(*str, '\n');
	while (!fnd)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (0);
		byt = read(fd, buf, BUFFER_SIZE);
		if (byt == -1)
			return (int_multi_free((void **)&buf, NULL, -1));
		if (byt == 0)
			return (int_multi_free((void **)&buf, NULL, 0));
		buf[byt] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buf);
		int_multi_free((void **)&tmp, (void **)&buf, 0);
		fnd = ft_strchr(*str, '\n');
	}
	return (byt);
}

static char	*extract_single_line(char **fnd, char **str, char **ln)
{
	char	*tmp;

	if (*fnd)
	{
		*ln = ft_substr(*str, 0, *fnd - *str + 1);
		if (!*ln)
			return (NULL);
		tmp = *str;
		*str = ft_strdup(*fnd + 1);
		free(tmp);
	}
	else
	{
		*ln = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (*ln);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*fnd;
	char		*ln;
	int			byt;
	void		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	byt = string_until_newline(&str, fd);
	if (byt == -1)
		return (ptr_multi_free((void **)&str, NULL));
	if (!byt && (!str || !*str))
		return (ptr_multi_free((void **)&str, NULL));
	fnd = ft_strchr(str, '\n');
	ptr = extract_single_line(&fnd, &str, &ln);
	if (!ptr || (!fnd && str && *str == 0))
		return (ptr_multi_free((void **)str, NULL));
	return (ln);
}
