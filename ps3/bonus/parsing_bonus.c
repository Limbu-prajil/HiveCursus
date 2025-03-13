/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:21:50 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/06 16:35:54 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

char	*ft_strjoin_space(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	i = -1;
	j = 0;
	if (s1)
	{
		while (s1[++i])
		{
			str[j] = s1[i];
			j++;
		}
		free(s1);
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = ' ';
	str[j + 1] = '\0';
	return (str);
}

t_list	*add_node(char *str, t_list *head)
{
	t_list	*tmp;
	t_list	*node;

	tmp = head;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nb = ft_atoi(str);
	free(str);
	node->next = NULL;
	if (head == NULL)
		return (node);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

char	**split_args(int ac, char **av)
{
	char	*tmp;
	char	**strs;
	int		i;

	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin_space(tmp, av[i]);
		if (isempty(av[i]))
			ft_exit(tmp, INVALID);
		i++;
	}
	strs = ft_split(tmp, ' ');
	free(tmp);
	return (strs);
}

t_list	*create_list(int ac, char **av)
{
	t_list	*head;
	char	**strs;
	int		i;

	strs = split_args(ac, av);
	check_format(strs);
	head = NULL;
	i = 0;
	while (strs[i])
	{
		head = add_node(strs[i], head);
		i++;
	}
	free(strs);
	return (head);
}
