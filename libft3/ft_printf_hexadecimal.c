/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:23:39 by kjullien          #+#    #+#             */
/*   Updated: 2024/12/05 20:30:54 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

void	ft_printf_print_hexadecimal(unsigned int i, int *counter, int is_upper)
{
	char	*hextable;
	char	res[8];
	int		index;

	if (i == 0)
	{
		*counter += (int)write(STDOUT_FILENO, "0", 1);
	}
	if (is_upper)
		hextable = "0123456789ABCDEF";
	else
		hextable = "0123456789abcdef";
	index = 0;
	while (i != 0)
	{
		res[index] = hextable[i % 16];
		i /= 16;
		index++;
	}
	while (--index >= 0)
		*counter += (int)write(STDOUT_FILENO, &res[index], 1);
}

void	ft_printf_print_pointer(uintptr_t ptr, int *counter)
{
	char	*hextable;
	char	res[50];
	int		index;

	if ((void *)ptr == NULL)
	{
		*counter += (int)write(STDOUT_FILENO, "(nil)", 5);
		return ;
	}
	hextable = "0123456789abcdef";
	index = 0;
	while (ptr != 0)
	{
		res[index] = hextable[ptr % 16];
		ptr /= 16;
		index++;
	}
	*counter += (int)write(STDOUT_FILENO, "0", 1);
	*counter += (int)write(STDOUT_FILENO, "x", 1);
	while (--index >= 0)
		*counter += (int)write(STDOUT_FILENO, &res[index], 1);
}
