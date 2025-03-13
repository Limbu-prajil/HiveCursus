/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:40:27 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/05 17:17:30 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exit_error(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	ft_exit(NULL, INVALID);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1 && (str[0] == '+' || str[0] == '-'))
	{
		if (str[1] >= '0' || str[1] <= '9')
			i++;
		else
			return (0);
	}
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '0')
			count++;
		i++;
	}
	if (count > 12 || ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

void	check_format(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!check_int(strs[i]) || !ft_isnum(strs[i]) || isempty(strs[i]))
			exit_error(strs);
		i++;
	}
}
