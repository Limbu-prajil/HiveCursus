/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:37:17 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 15:51:51 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_calloc(size_t count, size_t size)
{
	void *result_ft;
	void *result_libc;

	result_ft = ft_calloc(count, size);
	result_libc = calloc(count, size);
	if (result_ft == NULL && result_libc == NULL)
	{
		printf("ft_calloc(%zu, %zu): PASS (Both returned NULL)\n", count, size);
	}
	else if (result_ft != NULL && result_libc != NULL && ft_memcmp(result_ft, result_libc, count * size) == 0)
	{
		printf("ft_calloc(%zu, %zu): "GREEN"PASS\n"RESET"", count, size);
	}
	else
	{
		printf("ft_calloc(%zu, %zu): "RED"FAIL\n"RESET"", count, size);
	}

	// Free allocated memory
	free(result_ft);
	free(result_libc);
}

int main()
{
	// Test cases
	test_ft_calloc(10, sizeof(int));
	test_ft_calloc(0, sizeof(int));
	test_ft_calloc(10, 0);
	test_ft_calloc(0, 0);
	test_ft_calloc(1, sizeof(char));
	test_ft_calloc(100, sizeof(char));
	test_ft_calloc(50, sizeof(double));
	test_ft_calloc(20, sizeof(long));
	test_ft_calloc(5, sizeof(short));
	test_ft_calloc(1000, sizeof(char));
	test_ft_calloc(100, sizeof(int) * 100);

	return (0);
}
