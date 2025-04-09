#include "so_long.h"

// int	isber(char *file)
// {
// 	int				len;
// 	len = ft_strlen(file);
// 	if (file == 0)
// 		return (0);
// 	if (len < 5)
// 		return (0);
// 	if (ft_strcmp(file + len - 4, ".ber") != 0)
// 		return (0);
// 	return (1);
// }

static void	print_error(const char *message)
{
	write(1, "\033[1;31mERROR: ", 13);
	while (*message)
		write(1, message++, 1);
	write(1, "\033[0m\n", 6);
}

int	main(int argc, char **argv)
{
	t_base	*base;

	if (argc != 2)
	{
		print_error("usage: ./solong map(n).ber");
		return (1);
	}
	// else if (isber(argv[1]) == 0)
	// {
	// 	print_error("invalid extension for map");
	// 	return (1);
	// }
	base = base_init(argv[1]);
	create_base(base);
	mlx_hook(base->mlx_win, 2, 1L << 0, key_press, base);
	mlx_hook(base->mlx_win, 3, 1L << 1, key_release, base);
	mlx_hook(base->mlx_win, 17, 1L << 17, destroy_game, base);
	mlx_loop(base->mlx);
	return (0);
}
