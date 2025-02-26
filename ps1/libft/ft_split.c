/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:23:45 by pdietric          #+#    #+#             */
/*   Updated: 2023/10/29 22:13:09 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	**ft_split(char const *s, char c);
//#include "stdio.h"
#include "string.h"
//
//void 	print(char **p)
//{
//	while (*p != 0)
//	{
//		printf("%s\n", *p);
//		p++;
//	}
//}
//
//void print_p(char	**p)
//{
//	while(*p != 0)
//	{
//		printf("%llu ", (unsigned long long)*p);
//		p++;
//	}
//	printf("%llu ", (unsigned long long)*p);
//	printf("\n");
//}
//
//void print_c(char	**p)
//{
//	while(*p != 0)
//	{
//		printf("%c ", **p);
//		p++;
//	}
//	printf("\n");
//}
//
//int	main(void)
//{
//	//char	*string = "AAAAaBBaCCCCCaD_";
//	//char	*string = "_AAAAaBBaCCCCCaDDDDaEEE";
//	//char	*string = "_AAAAaBBaCaDaEaFaG";
//	//char	*string = "_AAAAaaaaBBaCaDaEaFaG";
//	char	*string = "";
//	char	**p = ft_split(string, (char)'a');
//	print(p);
//	return (0);
//}
//
char	**cleanup(char	**p)
{
	size_t	pn;

	pn = 0;
	while (*(p + pn) != 0)
	{
		free(*(p + pn));
		pn++;
	}
	free(p);
	return (0);
}

const char	*nxt_field(char const *s, char c)
{
	while ((*s == c) && (*s != '\0'))
		s++;
	if (*s == '\0')
		s = 0;
	return (s);
}

size_t	field_len(char const *s, char c)
{
	char const	*s_orig;

	s_orig = s;
	while ((*s != c) && (*s != '\0'))
		s++;
	return (s - s_orig);
}

char	**add_field(char **p, size_t sz, char const *s, size_t len)
{
	char	**p_new;
	char	*field;

	p_new = ft_calloc(sz + 2, sizeof(*p_new));
	if (!p_new)
		return (cleanup(p));
	*(p_new + sz + 1) = (char *)0;
	(void)ft_memmove(p_new, p, sz * sizeof(*p_new));
	free (p);
	field = ft_calloc(len + 1, sizeof(char));
	if (!field)
		return (cleanup(p_new));
	ft_strlcpy(field, s, len + 1);
	*(p_new + sz) = field;
	return (p_new);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	size;
	size_t	len;

	p = ft_calloc(1, sizeof(*p));
	if (!p)
		return (0);
	*p = 0;
	size = 0;
	s = nxt_field(s, c);
	while (s)
	{
		len = field_len(s, c);
		p = add_field(p, size, s, len);
		if (!p)
			break ;
		size++;
		s = nxt_field(s + len, c);
	}
	return (p);
}
